#include "LedRGB.h"

LedRGB::LedRGB(int pinR,int pinG, int pinB):pin_red(pinR),pin_green(pinG),pin_blue(pinB){
  pinMode(pinR,OUTPUT);
  pinMode(pinG,OUTPUT);
  pinMode(pinB,OUTPUT);
}

/*getter*/
float LedRGB::get_percent_red(void){
  return percent_red;
}
float LedRGB::get_percent_green(void){
  return percent_green;
}
float LedRGB::get_percent_blue(void){
  return percent_blue;
}

/*setter*/
bool LedRGB::set_percent_red(float percent){
  int value=0;
  if(percent>=0.0f&&percent<=100.0f){
    percent_red=percent;
    value=255*(percent/100);
    analogWrite(pin_red,value);
    return true;
  }
  return false;
}
bool LedRGB::set_percent_green(float percent){
  int value=0;
  if(percent>=0.0f&&percent<=100.0f){
    percent_green=percent;
    value=255*(percent/100);
    analogWrite(pin_green,value);
    return true;
  }
  return false; 
}
bool LedRGB::set_percent_blue(float percent){
  int value=0;
  if(percent>=0.0f&&percent<=100.0f){
    percent_blue=percent;
    value=255*(percent/100);
    analogWrite(pin_blue,value);
    return true;
  }
  return false; 
}

/*Methodes*/
void LedRGB::init(void){
  set_percent_red(0.00f);
  set_percent_green(0.00f);
  set_percent_blue(0.00f);
}
