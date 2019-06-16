
#include "DistanceSensor.h"

DistanceSensor::DistanceSensor(int trig,int echo){
  pin_trig = trig;
  pin_echo = echo;
  pinMode(pin_trig,OUTPUT);
  pinMode(pin_echo,INPUT);
}

float DistanceSensor::getDistance(){
  digitalWrite(pin_trig, HIGH); // On passe le trigger à l'état haut pendant une durée de 10µs
  delayMicroseconds(10); 
  digitalWrite(pin_trig, LOW);
  last_distance = (float)pulseIn(pin_echo, HIGH)*1000000*SOUND_SPEED; // On récupère la mesure
  return last_distance;
}
