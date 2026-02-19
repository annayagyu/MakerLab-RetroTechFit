#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <ESP32Servo.h>

// Configurações do Display
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// Pinos
const int pinoGas = 34;
const int pinoBuzzer = 23;
const int pinoServo = 13;
const int pinoLedVerde = 18;
const int pinoLedVermelho = 19;

Servo valvulaGas;
int limiteAlerta = 1500;

void setup() {
  Serial.begin(115200);
  
  // Inicializa Display OLED
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { 
    Serial.println(F("Falha no OLED"));
    for(;;);
  }
  
  valvulaGas.attach(pinoServo);
  pinMode(pinoBuzzer, OUTPUT);
  pinMode(pinoLedVerde, OUTPUT);
  pinMode(pinoLedVermelho, OUTPUT);

  valvulaGas.write(90); // Inicia com a válvula aberta
  display.clearDisplay();
  display.setTextColor(WHITE);
}

void loop() {
  int nivelGas = analogRead(pinoGas);
  
  // Interface no Display
  display.clearDisplay();
  display.setCursor(0,0);
  display.setTextSize(1);
  display.println("ANGATECH - AEROSENSE");
  display.drawLine(0, 12, 128, 12, WHITE);
  
  display.setCursor(0, 25);
  display.setTextSize(2);
  display.print("GAS: ");
  display.print(nivelGas); 

  if (nivelGas > limiteAlerta) {
    // --- ESTADO DE PERIGO ---
    display.setCursor(0, 50);
    display.setTextSize(1);
    display.println("!!! PERIGO - CORTE !!!");
    
    digitalWrite(pinoLedVerde, LOW);
    digitalWrite(pinoLedVermelho, HIGH);
    valvulaGas.write(0); // Fecha a válvula de gás
    tone(pinoBuzzer, 1000, 200); // Alerta sonoro
  } else {
    // --- ESTADO SEGURO ---
    display.setCursor(0, 50);
    display.setTextSize(1);
    display.println("STATUS: AMBIENTE SEGURO");
    
    digitalWrite(pinoLedVerde, HIGH);
    digitalWrite(pinoLedVermelho, LOW);
    valvulaGas.write(90); // Válvula permanece aberta
    noTone(pinoBuzzer);
  }

  display.display();
  delay(500);
}
