#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// Configurações da Tela OLED
#define LARGURA_TELA 128
#define ALTURA_TELA 64
#define RESET_OLED -1
Adafruit_SSD1306 display(LARGURA_TELA, ALTURA_TELA, &Wire, RESET_OLED);

// Nomes dos Pinos
const int pinoRele = 23;
const int pinoPotenciometro = 34;
const int pinoBotao = 19; // Nosso novo botão físico

// Variáveis de Memória do Sistema
bool tomadaLigada = false;       // O sistema começa com a tomada desligada
bool estadoAnteriorBotao = HIGH; // Guarda o último clique para não dar "duplo clique" sem querer

void setup() {
  pinMode(pinoRele, OUTPUT);
  
  // O INPUT_PULLUP liga um resistor virtual dentro do ESP32, economizando peças físicas!
  pinMode(pinoBotao, INPUT_PULLUP); 

  // Inicia a Tela OLED
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("Falha ao iniciar o OLED"));
    for(;;); 
  }
  
  // Tela de Abertura
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(10, 25);
  display.println("AnGa RetroTechfit");
  display.setCursor(30, 40);
  display.println("EnergySense");
  display.display();
  delay(3000); 
}

void loop() {
  // 1. LÊ O BOTÃO
  // Como usamos PULLUP, o botão solto lê HIGH, e o botão apertado lê LOW.
  bool estadoAtualBotao = digitalRead(pinoBotao);

  // 2. DETECTA O CLIQUE (Se ele estava solto e agora foi apertado)
  if (estadoAnteriorBotao == HIGH && estadoAtualBotao == LOW) {
    tomadaLigada = !tomadaLigada; // Inverte o estado: se era falso vira verdadeiro, e vice-versa.
    delay(50); // Um pequeno atraso para o botão físico não dar mal contato (Debounce)
  }
  estadoAnteriorBotao = estadoAtualBotao; // Atualiza a memória para o próximo ciclo

  // 3. EXECUTA A AÇÃO NA TOMADA E NA TELA
  if (tomadaLigada == true) {
    digitalWrite(pinoRele, HIGH); // Estala o relé e acende o LED
    
    // Lê o consumo simulado
    int valorPot = analogRead(pinoPotenciometro); 
    int watts = map(valorPot, 0, 4095, 0, 2500);  
    
    atualizarTela("LIGADO", watts);
  } else {
    digitalWrite(pinoRele, LOW); // Desliga o relé e apaga o LED
    atualizarTela("DESLIGADO", 0); // Consumo zera
  }
  
  delay(50); // Deixa a tela fluida
}

// Função do Dashboard na tela (A mesma de antes)
void atualizarTela(String status, int watts) {
  display.clearDisplay();
  display.drawRect(0, 0, 128, 64, WHITE);
  
  display.setTextSize(1);
  display.setCursor(5, 10);
  display.print("Status: ");
  display.print(status);

  display.setTextSize(2); 
  display.setCursor(25, 35);
  display.print(watts);
  display.print(" W");

  display.display();
}
