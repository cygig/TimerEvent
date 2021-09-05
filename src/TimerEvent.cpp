#include "TimerEvent.h"

TimerEvent::TimerEvent(){
// Nothing inside constructor.
// We use set instead if not we need to declare myFunction on top of setup().
}

void TimerEvent::set(unsigned long myPeriod,void (*myFunction)()){
  set(millis(), myPeriod, myFunction);	
}

void TimerEvent::set(unsigned long myLastTime,unsigned long myPeriod,void (*myFunction)()){
  enabled = true;
	period = myPeriod;
	lastTime = myLastTime;
	callBackFunction = myFunction;	
	
}

void TimerEvent::reset(){
    lastTime = millis();
}

void TimerEvent::disable(){
    enabled = false;
}

void TimerEvent::enable(){
	enabled = true;
}

void TimerEvent::update(){
  if ( enabled && ((unsigned long) (millis()-lastTime) >= period) ) {
    callBackFunction();
	  lastTime = millis();
  }
}

void TimerEvent::setPeriod( unsigned long myPeriod){
	period = myPeriod;
}

bool TimerEvent::isEnabled(){
  return enabled;
}
