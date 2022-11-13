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
	richCallBackFunction = nullptr;
	context = nullptr;
}

void TimerEvent::set(unsigned long myPeriod,void (*myFunction)(const TimerEvent*, void*),void* myContext) {
    set(millis(), myPeriod, myFunction, myContext);	
}

void TimerEvent::set(unsigned long myLastTime,unsigned long myPeriod,void (*myFunction)(const TimerEvent*, void*),void* myContext) {
    enabled = true;
    period = myPeriod;
    lastTime = myLastTime;
    callBackFunction = nullptr;
    richCallBackFunction = myFunction;
    context = myContext;
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
    if (callBackFunction) {
      callBackFunction();
    } else if (richCallBackFunction) {
      richCallBackFunction(this, context);
    }
    lastTime = millis();
  }
}

void TimerEvent::setPeriod( unsigned long myPeriod){
	period = myPeriod;
}

bool TimerEvent::isEnabled(){
  return enabled;
}
