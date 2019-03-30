#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

int led1        = 3;
int ledRosso    = 9;
int ledVerde    = 11;
int btn0        = 13;
int btn1        = 1;
int btn2        = 5;
int buzzer      = 6;
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
  while(digitalRead(btn0) != HIGH) {}
  digitalWrite(ledVerde, LOW);
  digitalWrite(ledRosso, LOW);
  inizio();
  tempoLed = riflesso(led1, btn1, tempoLed, 0);
  if(tempoLed <= 80){
    lcd.clear(); 
    lcd.setCursor(0, 0);
    lcd.print("TEST NON VALIDO");
    digitalWrite(ledRosso, HIGH);
    delay(3000);
  }
  else {
   tempoBuzzer = riflesso(buzzer, btn2, tempoBuzzer, 1);
   if (tempoBuzzer <= 80){
     lcd.clear();
     lcd.setCursor(0, 0);
     lcd.print("TEST NON VALIDO");
     digitalWrite(ledRosso, HIGH);
     delay(3000);
   }
   else 
     esito();
  }
  while(digitalRead(btn0) != HIGH) {}
}

void inizio() {
  while(digitalRead(btn0) != HIGH) {}
  tempoLed    = 0;
  tempoBuzzer = 0;
  lcd.clear();
  lcd.print("Test iniziato");
  delay(2000);
  lcd.clear();
}

 int riflesso(int i, int a, int tempo, int linea) {
   delay(random(2000, 8000));
   digitalWrite(i, HIGH);
   while (digitalRead(a) == LOW) {
      tempo++;
      delay(1);
      }
    digitalWrite(i, LOW);
    lcd.setCursor(0, linea);
    lcd.print("Tempo: ");
    lcd.print(tempo);
    lcd.print("ms");
    return tempo;
  }
  
void esito() {
  if (tempoLed <= 500 && tempoBuzzer <= 500) {
    digitalWrite(ledVerde, HIGH);
    delay(3000);
    lcd.clear();
    lcd.print("TEST SUPERATO!");
  }
  else {
    digitalWrite(ledRosso, HIGH);
    delay(3000);
    lcd.clear();
    lcd.print("NON SUPERATO");
  }
}
