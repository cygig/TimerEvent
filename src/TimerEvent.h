/*
TimerEvent 0.4.0 For Arduino by cygig
TimerEvent is based on TimedAction 1.6 by Alexander Brevig (alexanderbrevig@gmail.com).
It is updated to work with Arduino IDE 1.8.5.

TimerEvent provides an easy way to trigger functions every set time and is a non-blocking alternative
to delay() function.

*/

#ifndef TIMEREVENT_H
#define TIMEREVENT_H

#if ARDUINO >= 100
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif

/* The library initially used unsigned long for the period before 0.5.0
 * Later on, I realised that most events have a period of less than few seconds.
 * Thus using unsigned long is a waste of RAM. So I changed to unsigned int instead.
 * You can set periodInInt to 0 to change it back to unsigned long.
 */
#define periodInInt 1


class TimerEvent {
  
  public:
    TimerEvent();
  	void set(unsigned long myPeriod,void (*myFunction)());
  	void set(unsigned long myTimer,unsigned long myPeriod,void (*myFunction)());
  	void reset();
  	void disable();
  	void enable();
  	void update();
  	void setPeriod( unsigned long myPeriod );
    bool isEnabled();

  private: 
    bool enabled;
    unsigned long lastTime;
    #if periodInInt==1
      unsigned int period;
    #else
      unsigned long period;
    #endif
    void (*callBackFunction)();
		
};

#endif
