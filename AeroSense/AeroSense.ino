// Pinos dos Componentes - AeroSense
const int pinoGas = 34;
const int pinoBuzzer = 23;      // <--- Atualizado para o seu novo pino!
const int pinoLedVerde = 18;
const int pinoLedVermelho = 19;

// Configuração de Sensibilidade (Ajustável)
// No Wokwi, o sensor de gás costuma subir rápido quando você aproxima a fumaça
const int limiteAlerta = 1500; 

void setup() {
  Serial.begin(115200);
  
  // Configurando os pinos de saída
  pinMode(pinoBuzzer, OUTPUT);
  pinMode(pinoLedVerde, OUTPUT);
  pinMode(pinoLedVermelho, OUTPUT);
  
  Serial.println("AeroSense Inicializado - Vigilância de Ar Ativa");
}

void loop() {
  // 1. Lê o nível de gás/fumaça (Valor de 0 a 4095)
  int nivelGas = analogRead(pinoGas);
  
  // Mostra no monitor serial para você calibrar se precisar
  Serial.print("Nivel de Gas: ");
  Serial.println(nivelGas);

  // 2. Lógica de Segurança (Alerta Crítico)
  if (nivelGas > limiteAlerta) {
    // --- ESTADO DE PERIGO ---
    digitalWrite(pinoLedVerde, LOW);     // Apaga o verde
    digitalWrite(pinoLedVermelho, HIGH); // Acende o vermelho (Alerta visual)
    
    // Alerta Sonoro de Emergência (Intermitente para chamar atenção)
    tone(pinoBuzzer, 1000); // Som de 1kHz (agudo)
    delay(150);             // Beep rápido
    noTone(pinoBuzzer);
    delay(150);
    
    Serial.println("!!! PERIGO: VAZAMENTO OU FUMAÇA DETECTADOS !!!");
  } else {
    // --- ESTADO SEGURO ---
    digitalWrite(pinoLedVerde, HIGH);    // Mantém o verde aceso
    digitalWrite(pinoLedVermelho, LOW);
    noTone(pinoBuzzer);                 // Garante que o alarme fique quieto
  }

  delay(100); // Pequena pausa para o processamento não "fritar"
}
