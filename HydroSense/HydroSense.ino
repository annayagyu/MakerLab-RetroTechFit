#include <ESP32Servo.h>

const int pinoFluxo = 34;
const int pinoServo = 12;
const int pinoBotaoReset = 25; 
const int ledAzul = 19;
const int ledVermelho = 4;

Servo valvula;
bool valvulaAberta = true;
unsigned long tempoInicioFluxo = 0;

void setup() {
  Serial.begin(115200);
  valvula.attach(pinoServo);
  
  pinMode(pinoBotaoReset, INPUT_PULLUP);
  pinMode(ledAzul, OUTPUT);
  pinMode(ledVermelho, OUTPUT);

  abrirValvula();
  Serial.println("--- HydroSense Inicializado ---");
}

void loop() {
  int leitura = analogRead(pinoFluxo);
  unsigned long tempoAtual = millis();

  // Lógica do Botão de Reset
  if (digitalRead(pinoBotaoReset) == LOW && !valvulaAberta) {
    Serial.println("\n[SISTEMA] Botão Reset pressionado. Restaurando fluxo...");
    abrirValvula();
    delay(500); 
  }

  if (valvulaAberta) {
    if (leitura < 100) {
      // ESTADO: SEM VAZÃO
      digitalWrite(ledAzul, HIGH);
      digitalWrite(ledVermelho, LOW);
      if (tempoInicioFluxo != 0) {
        Serial.println("Status: Sem Fluxo. Monitoramento resetado.");
      }
      tempoInicioFluxo = 0; 
    } 
    else {
      // ESTADO: FLUXO ATIVO
      if (tempoInicioFluxo == 0) tempoInicioFluxo = tempoAtual;
      long tempoPassado = (tempoAtual - tempoInicioFluxo) / 1000;

      // Classificação da Vazão para o Print
      String categoriaVazao;
      if (leitura < 1500) categoriaVazao = "BAIXA (Possível Gotejamento)";
      else if (leitura < 3000) categoriaVazao = "NORMAL (Uso Comum)";
      else categoriaVazao = "INTENSA (Alerta de Vazamento)";

      Serial.print("Vazão: ");
      Serial.print(categoriaVazao);
      Serial.print(" | Tempo Ativo: ");
      Serial.print(tempoPassado);
      Serial.println("s / 30s");

      // Corte de segurança
      if (tempoPassado >= 30) {
        fecharValvula("ALERTA CRÍTICO: Vazão constante detectada por 30 segundos!");
      }
    }
  }
  delay(1000); // Print a cada 1 segundo para ficar legível
}

void abrirValvula() {
  valvulaAberta = true;
  valvula.write(90); 
  digitalWrite(ledAzul, HIGH);
  digitalWrite(ledVermelho, LOW);
  Serial.println("STATUS: Válvula Aberta. Monitorando...");
}

void fecharValvula(String motivo) {
  valvulaAberta = false;
  valvula.write(0); 
  digitalWrite(ledAzul, LOW);
  digitalWrite(ledVermelho, HIGH);
  Serial.println("\n************************************");
  Serial.println(motivo);
  Serial.println("Ação: Registro Geral bloqueado.");
  Serial.println("************************************\n");
}
