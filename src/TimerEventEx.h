/*
TimerEventEx 0.5.1 For Arduino by lcramos05
TimerEventEx is based on TimerEvent from cygig.
TimerEvent is based on TimedAction 1.6 by Alexander Brevig (alexanderbrevig@gmail.com).
It is updated to work with Arduino IDE 1.8.5.

TimerEventEx provides an easy way to trigger functions every set time and is a non-blocking alternative
to delay() function. It also provides a way of calling the callback function passing a context pointer.

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


class TimerEventEx {
  
  public:
    TimerEventEx();
  	void set(unsigned long myPeriod,void (*myFunction)());
  	void set(unsigned long myTimer,unsigned long myPeriod,void (*myFunction)());
  	void set(unsigned long myPeriod,void (*myFunction)(const TimerEvent*, void*), void* myContext);
  	void set(unsigned long myTimer,unsigned long myPeriod,void (*myFunction)(const TimerEvent*, void*), void* myContext);
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
    void (*richCallBackFunction)(const TimerEventEx*, void*);
    void* context;
		
};

#endif
