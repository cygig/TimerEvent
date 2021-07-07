/*
TimerEvent 0.4 For Arduino by cygig
TimerEvent is based on TimedAction 1.6 by Alexander Brevig (alexanderbrevig@gmail.com).
It is updated to work with Arduino IDE 1.8.5.

TimerEvent provides an easy way to trigger functions every set time and is a non-blocking alternative
to delay() function.

*/

#ifndef TIMEREVENT
#define TIMEREVENT

#if ARDUINO >= 100
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif


class TimerEvent {
  
  public:
    TimerEvent();
  	void set(unsigned long myPeriod,void (*myFunction)());
  	void set(unsigned long myTimer,unsigned long myPeriod,void (*myFunction)());
  	void reset();
  	void disable();
  	void enable();
  	void update();
	void setInterval( unsigned long myPeriod );
	bool start();

  private: 
    bool active;
    unsigned long timer;
    unsigned long period;
    void (*function)();
		
};

#endif
