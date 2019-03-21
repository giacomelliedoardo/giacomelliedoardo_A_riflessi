#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

int led1        = 7;
int ledRosso    = 2;
int ledVerde    = 4;
int btn0        = 8;
int btn1        = 10;
int btn2        = 12;
int buzzer      = 13;
int tempoLed    = 0;
int tempoBuzzer = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(led1, OUTPUT);
  pinMode(ledRosso, OUTPUT);
  pinMode(ledVerde, OUTPUT);
  pinMode(btn0, INPUT);
  pinMode(btn1, INPUT);
  pinMode(btn2, INPUT);
  pinMode(buzzer, OUTPUT);
  lcd.init();
  lcd.backlight();
}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.setCursor(0, 0);
  lcd.print ("Test iniziato");
  inizio();
  primoRiflesso();
  secondoRiflesso();
  esito();
}

void inizio() {
  while(digitalRead(btn0) != HIGH) {}
  lcd.setCursor(0, 0);
  lcd.print ("Test iniziato");
  tempoLed = 0;
  tempoBuzzer = 0;
  digitalWrite(ledVerde, LOW);
  digitalWrite(ledRosso, LOW);
}

void primoRiflesso() {
  delay(random(2000, 8000));
  digitalWrite(led1, HIGH);
  
  while (digitalRead(btn1) == LOW) {
    tempoLed++;
    delay(1);
  }
  digitalWrite(led1, LOW);
}

void secondoRiflesso() {
  delay(random(2000, 8000));
  digitalWrite(buzzer, HIGH);

  while(digitalRead(btn2) == LOW) {
    tempoBuzzer++;
    delay(1);
  }
  digitalWrite(buzzer, LOW);
}

void esito() {
  if (tempoLed <= 500 && tempoBuzzer <= 500) {
    digitalWrite(ledVerde, HIGH);
  }
  else {
    digitalWrite(ledRosso, HIGH);
  }
}
