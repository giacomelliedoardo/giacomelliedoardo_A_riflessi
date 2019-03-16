int led1 = 6;
int btn0 = 8;
int btn1 = 10;
int tempoLed = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(led1, OUTPUT);
  pinMode(btn0, INPUT);
  pinMode(btn1, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  inizio();
  primoRiflesso();
}
void inizio() {
  while(digitalRead(btn0) != HIGH) {}
}

void primoRiflesso() {
  delay(random(2000, 8000));
  digitalWrite(led1, HIGH);
  
  while (digitalRead(btn1) != HIGH){
    tempoLed++;
    delay(1);
  }
  digitalWrite(led1, LOW); 
}
