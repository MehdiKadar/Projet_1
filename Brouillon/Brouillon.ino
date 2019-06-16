#include <Arduino.h>

#define trig  4 
#define echo  2 
long mesure_echo; 
long mesure_cm;
 
void setup() 
{ 
  pinMode(trig, OUTPUT); // On définit le pin trigger comme une sortie
  digitalWrite(trig, LOW); // Et on le mets à l'état bas
  pinMode(echo, INPUT); // On définit le pin echo comme une entrée
  Serial.begin(9600); 
}
 
void loop() 
{ 
  digitalWrite(trig, HIGH); // On passe le trigger à l'état haut pendant une durée de 10µs
  delayMicroseconds(10); 
  digitalWrite(trig, LOW); 
  
  mesure_echo = pulseIn(echo, HIGH); // On récupère la mesure
  mesure_cm = mesure_echo / 58; // On la convertis en cm
  
  Serial.print(mesure_cm); // On l'affiche
  Serial.println("cm");
  
  delay(1000); // On attends 1 seconde avant de lancer la prochaine mesure 
}
