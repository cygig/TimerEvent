/*
TimerEvent 0.5.0 For Arduino by cygig
TimerEvent is based on TimedAction 1.6 by Alexander Brevig (alexanderbrevig@gmail.com).
It is updated to work with Arduino IDE 1.8.5.

TimerEvent provides an easy way to trigger functions every set time and is a non-blocking alternative
to delay() function.

*/

// This sketch will print timings from three timers to Serial monitor.
// The first prints a random number every 997ms.
// The second prints a flips a boolean between 1 and 0 every 1361ms.
// The third prints the time that the sketch has been running every 3000ms.

#include <TimerEvent.h>

const unsigned int timerOnePeriod = 997;
const unsigned int timerTwoPeriod = 1361;
const unsigned int timerThreePeriod = 3000;

// Create two TimerEvent instances
TimerEvent timerOne;
TimerEvent timerTwo;
TimerEvent timerThree;

bool myBool=false;

void setup(){
  Serial.begin(9600);

  randomSeed( (unsigned long)( micros()%millis() ) );

  // Set the interval timing as well as pass the function name
  timerOne.set(timerOnePeriod, timerOneFunc);
  timerTwo.set(timerTwoPeriod, timerTwoFunc);
  timerThree.set(timerThreePeriod, timerThreeFunc);
}

void loop(){

  // Remember to run the update() function in loop()!
  timerOne.update();
  timerTwo.update();
  timerThree.update();
  
}

// This function will be called every timerOnePeriod
void timerOneFunc(){
  Serial.print("<< Timer One >> Random Number: ");
  Serial.print(random(100));
  Serial.print(" (Update in ");
  Serial.print(timerOnePeriod);
  Serial.println("ms)\n");
}

// This function will be called every timerTwoPeriod
void timerTwoFunc(){
  myBool=!myBool; //Flip my bool from true to false or the other way round
  
  Serial.print("[[ Timer Two ]] myBool is ");
  Serial.print(myBool);
  Serial.print(" (Update in ");
  Serial.print(timerTwoPeriod);
  Serial.println("ms)\n"); 
}

// This function will be called every timerThreePeriod
void timerThreeFunc(){
  Serial.print("* Timer Three * This sketch ran for "); 
  Serial.print(millis());
  Serial.print("ms (Update in ");
  Serial.print(timerThreePeriod);
  Serial.println("ms)\n");
}
