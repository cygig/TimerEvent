// This sketch will print timings from two timers to Serial monitor

#include <TimerEvent.h>

const int timerOneInterval = 997;
const int timerTwoInterval = 1361;

// Create two TimerEvent instances
TimerEvent timerOne;
TimerEvent timerTwo;


void setup(){
  Serial.begin(9600);

  // Set the interval timing as well as pass the function name
  timerOne.set(timerOneInterval, timerOneFunc);
  timerTwo.set(timerTwoInterval, timerTwoFunc);
}

void loop(){

  // Remember to run the update() function in loop()!
  timerOne.update();
  timerTwo.update();
  
}

// This function will be called every timerOneInterval
void timerOneFunc(){
  Serial.print(timerOneInterval);
  Serial.println("ms has passed!");
}

// This function will be called every timerTwoInterval
void timerTwoFunc(){
  Serial.print(timerTwoInterval);
  Serial.println("ms has passed!");  
}
