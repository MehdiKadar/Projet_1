#ifndef  __DistanceSensoer__
#define  __DistanceSensoer__

#include <Arduino.h>
#define SOUND_SPEED 340,29

class DistanceSensor{

  private:
  int pin_trig;
  int pin_echo;
  float last_distance;

  public:
  DistanceSensor(int trig,int echo);
  float getDistance();

  
};

#endif //__DistanceSensoer__
