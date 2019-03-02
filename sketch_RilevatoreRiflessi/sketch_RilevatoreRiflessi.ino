int led1 = 13;
int btn = 7;
int val = 0;
int tempo = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(led1, OUTPUT);
  pinMode(btn, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  primoRiflesso();
}

void primoRiflesso() {
  val = digitalRead(btn);
  digitalWrite(led1, HIGH);
  tempo = random(2000, 5000);
  
  if (val == HIGH) {
  digitalWrite(led1, LOW);
  } else {
  digitalWrite(led1, HIGH);
  }
}
