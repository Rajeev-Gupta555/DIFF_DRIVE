#define LS A0
#define RS A3
#define LM1 12
#define LM2 11
#define RM1 10 
#define RM2 9 

int LMS = 200;  // inner motor
int RMS = 200; // outer motor
void setup() {
  // put your setup code here, to run once:
  pinMode(LM1, OUTPUT);
  pinMode(LM2, OUTPUT); 
  pinMode(RM1, OUTPUT);
  pinMode(RM2, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(100);
  digitalWrite(LM1, HIGH);
  digitalWrite(RM1, HIGH);
  analogWrite(LM2, LMS);
  analogWrite(RM2, RMS);
}