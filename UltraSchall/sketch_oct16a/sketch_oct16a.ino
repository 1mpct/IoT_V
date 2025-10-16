const int SENDEN = 12;
const int ECHO = 13;
int Entfernung = 0;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(SENDEN,OUTPUT);
pinMode(ECHO, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(SENDEN, LOW);
delay(5);
//5 microsekunden low signal
digitalWrite(SENDEN, HIGH);
delayMicroseconds(10);
//10 microskunden high signal

digitalWrite(SENDEN, LOW);
//Signal auf low setzten
long Zeit = pulseIn(ECHO, HIGH);
//pulseIn -> Zeit für Signal abgabe und Aufnahme

Entfernung = (Zeit / 2) * 0.03432; 
//Entfernung in cm berechnen

delay(500);
//500 microsekunden nichts

Serial.print("Entfernung in cm: ");
Serial.println(Entfernung);
}


