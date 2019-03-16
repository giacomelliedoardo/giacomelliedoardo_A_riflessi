int led1 = 6;
int ledRosso = 0;
int ledVerde = 1;
int ledBlu = 2; 
int btn0 = 8;
int btn1 = 10;
int btn2 = 12;
int buzzer = 4;
int tempoLed = 0;
int tempoBuzzer = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(led1, OUTPUT);
  pinMode(ledRosso, OUTPUT);
  pinMode(ledVerde, OUTPUT);
  pinMode(ledBlu, OUTPUT);
  pinMode(btn0, INPUT);
  pinMode(btn1, INPUT);
  pinMode(btn2, INPUT);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  inizio();
  primoRiflesso();
  secondoRiflesso();
}

void inizio() {
  while(digitalRead(btn0) != HIGH) {}
}

void primoRiflesso() {
  delay(random(2000, 8000));
  digitalWrite(led1, HIGH);
  
  while (digitalRead(btn1) != HIGH) {
    tempoLed++;
    delay(1);
  }
  digitalWrite(led1, LOW); 
}

void secondoRiflesso() {
  delay(random(2000, 8000));
  digitalWrite(buzzer, HIGH);

  while(digitalRead(btn2) != HIGH) {
    tempoBuzzer++;
    delay(1);
  }
  digitalWrite(buzzer, LOW);
}
