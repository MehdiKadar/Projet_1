#include <Arduino.h>
#include "LedRGB.h"

#define PIN_RGB_RED    11
#define PIN_RGB_GREEN  10
#define PIN_RGB_BLUE    9

#define STAT_COLOR 0
#define STAT_VALUE 1

#define RED 0
#define GREEN 1
#define BLUE 2
#define NO_COLOR 3

LedRGB led(PIN_RGB_RED,PIN_RGB_GREEN,PIN_RGB_BLUE);
String msg;
int stat;
int color;
int value;
bool check_correct_value;
bool authorization_to_set;

void setup() {
  Serial.begin(9600);
  while (!Serial) {
  }
  led.init();
  stat = STAT_COLOR;
  authorization_to_set = false;
}

void loop() {
  if(Serial.available()){
    msg=Serial.readString();
    
//read color and value to set in the led RGB    
    switch(stat){
      
     case STAT_COLOR:
          if(msg=="red\n"){
            color = RED;
            Serial.println("Red was selected");
            stat=STAT_VALUE;
            authorization_to_set = false;
          }
         else if (msg=="green\n"){
           color = GREEN;
           Serial.println("Green was selected");
           stat=STAT_VALUE;
           authorization_to_set = false;
         }
          else if (msg=="blue\n"){
            color = BLUE;
            Serial.println("Blue was selected");
            stat=STAT_VALUE;
            authorization_to_set = false;
          }
          else if (msg=="reset\n"){
            color = NO_COLOR;
            Serial.println("Color reinitialized");
            led.init();
            authorization_to_set = false;
          }
          else{
            color = NO_COLOR;
            authorization_to_set = false;
            Serial.println("Select color: red - green - blue !");
          }
     break;

     case STAT_VALUE:
          value = atoi(msg.c_str());
          authorization_to_set = true;
     break;

     default:
     break;
    }
     
//set color to led RGB  
  if(authorization_to_set==true){
    switch(color){
      case RED:
      check_correct_value=led.set_percent_red(value);
       stat=STAT_COLOR;
       break;

       case GREEN:
       check_correct_value=led.set_percent_green(value);
       stat=STAT_COLOR;
       break;

      case BLUE:
       check_correct_value=led.set_percent_blue(value);
       stat=STAT_COLOR;
       break;

       default:
       break;
    
    }
  }
   
   if(check_correct_value==false){
    stat=STAT_VALUE;
    Serial.println("Please set correct value (en%) !");
   }
  }
}
