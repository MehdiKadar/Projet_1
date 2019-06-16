#ifndef  __SBGC__
#define  __SBGC__

#include <Arduino.h>


class LedRGB{

  private:

  /*interrupt timer*/


  /*Pin color*/
  int pin_red;
  int pin_green;
  int pin_blue;
  
  /*Percentage between 0% and 100%*/
  float percent_red;
  float percent_green;
  float percent_blue;

  public:

  /*Constructor*/
  LedRGB(int pinR,int pinG, int pinB);

  /*Getters*/
  float get_percent_red(void);
  float get_percent_green(void);
  float get_percent_blue(void);

  /*Setters*/
  bool set_percent_red(float percent);
  bool set_percent_green(float percent);
  bool set_percent_blue(float percent);
  
  /*Methodes*/
  void init(void);
  
};


#endif //__SBGC__
