#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
// variabili
int led1;
int ledRosso;
int ledVerde;
int btn0;
int btn1;
int btn2;
int buzzer;
int tempoLed;
int tempoBuzzer;

void setup() {
  // put your setup code here, to run once:
  //stabilisco variabili in input e output
  pinMode(led1, OUTPUT);
  pinMode(ledRosso, OUTPUT);
  pinMode(ledVerde, OUTPUT);
  pinMode(btn0, INPUT);
  pinMode(btn1, INPUT);
  pinMode(btn2, INPUT);
  pinMode(buzzer, OUTPUT);
  
  led1        = 3;
  ledRosso    = 9;
  ledVerde    = 11;
  btn0        = 13;
  btn1        = 2;
  btn2        = 5;
  buzzer      = 6;
  tempoLed    = 0;
  tempoBuzzer = 0;
  
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
  if(tempoLed <= 80){                                             //se il tempo è minore di 80ms il test non è valido
    lcd.clear(); 
    lcd.setCursor(0, 0);
    lcd.print("TEST NON VALIDO");
    digitalWrite(ledRosso, HIGH);
    delay(3000);
  }
  else {
   tempoBuzzer = riflesso(buzzer, btn2, tempoBuzzer, 1);
   if (tempoBuzzer <= 80){                                        //se il tempo è minore di 80ms il test non è vealido 
     lcd.clear();
     lcd.setCursor(0, 0);
     lcd.print("TEST NON VALIDO");
     digitalWrite(ledRosso, HIGH);
     delay(3000);
   }
   else{
     esito();
   }
  }
  while(digitalRead(btn0) != HIGH) {}
}

void inizio() {
  while(digitalRead(btn0) != HIGH) {}                             //premo il bottone e parte il test
  tempoLed    = 0;
  tempoBuzzer = 0;
  lcd.clear();
  lcd.print("Test iniziato");
  delay(2000);
  lcd.clear();
}

 int riflesso(int i, int a, int tempo, int linea) {               //metodo riflesso per led e buzzer con variabili in input
   delay(random(2000, 8000));
   digitalWrite(i, HIGH);
   while (digitalRead(a) == LOW) {
      tempo++;
      delay(1);
      }
    digitalWrite(i, LOW);
    lcd.setCursor(0, linea);                                      //mi stampa sul display il tempo registrato
    lcd.print("Tempo: ");
    lcd.print(tempo);
    lcd.print("ms");
    return tempo;
  }
  
void esito() {
  if (tempoLed <= 500 && tempoBuzzer <= 500) {                    //mi dice se il test è stato superato tramite led rgb e display, se entrambe i test sono sotto i 500ms superato altrimenti no
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
