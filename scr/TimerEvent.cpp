#include "TimerEvent.h"

TimerEvent::TimerEvent(){
// Nothing inside constructor.
}

void TimerEvent::set(unsigned long myPeriod,void (*myFunction)()){
  active = true;
	timer = 0;
	period = myPeriod;
	function = myFunction;	
}

void TimerEvent::set(unsigned long myTimer,unsigned long myPeriod,void (*myFunction)()){
  active = true;
	period = myPeriod;
	timer = myTimer;
	function = myFunction;	
	
}

void TimerEvent::reset(){
    timer = millis();
}

void TimerEvent::disable(){
    active = false;
}

void TimerEvent::enable(){
	active = true;
}

void TimerEvent::update(){
  if ( active && ((unsigned long) (millis()-timer) >= period) ) {
    function();
	  timer = millis();
  }
}

void TimerEvent::setInterval( unsigned long myPeriod){
	period = myPeriod;
}
