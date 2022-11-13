#include "TimerEventEx.h"

TimerEventEx::TimerEventEx(){
// Nothing inside constructor.
// We use set instead if not we need to declare myFunction on top of setup().
}

void TimerEventEx::set(unsigned long myPeriod,void (*myFunction)()){
  set(millis(), myPeriod, myFunction);	
}

void TimerEventEx::set(unsigned long myLastTime,unsigned long myPeriod,void (*myFunction)()){
  enabled = true;
	period = myPeriod;
	lastTime = myLastTime;
	callBackFunction = myFunction;	
	richCallBackFunction = nullptr;
	context = nullptr;
}

void TimerEventEx::set(unsigned long myPeriod,void (*myFunction)(const TimerEventEx*, void*),void* myContext) {
    set(millis(), myPeriod, myFunction, myContext);	
}

void TimerEventEx::set(unsigned long myLastTime,unsigned long myPeriod,void (*myFunction)(const TimerEventEx*, void*),void* myContext) {
    enabled = true;
    period = myPeriod;
    lastTime = myLastTime;
    callBackFunction = nullptr;
    richCallBackFunction = myFunction;
    context = myContext;
}

void TimerEventEx::reset(){
    lastTime = millis();
}

void TimerEventEx::disable(){
    enabled = false;
}

void TimerEventEx::enable(){
	enabled = true;
}

void TimerEventEx::update(){
  if ( enabled && ((unsigned long) (millis()-lastTime) >= period) ) {
    if (callBackFunction) {
      callBackFunction();
    } else if (richCallBackFunction) {
      richCallBackFunction(this, context);
    }
    lastTime = millis();
  }
}

void TimerEventEx::setPeriod( unsigned long myPeriod){
	period = myPeriod;
}

bool TimerEventEx::isEnabled(){
  return enabled;
}
