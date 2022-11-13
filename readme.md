# TimerEvent
TimerEvent is a non-blocking alternative to the delay() function. It provides an easy way to trigger a callback function every set period of time and using multiple instances of this library enables your Arduino to multitask via time slicing.

TimerEvent is based on TimedAction 1.6 by Alexander Brevig (alexanderbrevig@gmail.com). It is updated to work with Arduino IDE 1.8.5 and above.

# Updates
- 0.5.0
	- Changed period of timer from `unsigned long` to `unsigned int` as most timer update less than every few seconds to save RAM. You can change `periodInInt ` definition in header file to `0` to set it back to `unsigned long`.
	- Added isEnabled() to check if the timer is enabled.
	- Changed example to use three timers instead.
	- Changed certain variable names.
	- Changed include guard name.
	- Change `set()` that takes two parameters to be based of `set()` with three parameters.



# Public functions

## _void_ set(_unsigned long_ myPeriod, _void_ (*myFunction)())
Used to setup the timer. Use this within `setup()`. `myPeriod` is the interval in milliseconds that the function `myFunction` will repeat.
For example: myTimer.set(1000, myFunction);

## _void_ set(_unsigned long_ myLastTime, _unsigned long_ myPeriod, _void_ (*myFunction)())
Similar to the other `set` function, but you can set the last callback time in milliseconds. The library will compare the last callback time against the current time to know if the callback function should be called. It will also update this last callback time after every callback. `myLastTime` is the last callback time in `unsigned long`, which will otherwise be set to the current time if not declared.

## _void_ set(_unsigned long_ myPeriod, _void_ (*myFunction)(_const TimerEvent_ *, _void_ *), _void_ *myContext)
Similar to the first simpler `set` function, but one can additionally provide an opaque pointer to be used when the callback function is called. This can help in cases where a couple of similar timers are used (like e.g. an array of timers) and there should be a way of telling a single callback function which context the timer relates to.

## _void_ set(_unsigned long_ myLastTime, _unsigned long_ myPeriod, _void_ (*myFunction)(_const TimerEvent_ *, _void_ *), _void_ *myContext)
Similar to the second `set` function, but one can additionally provide an opaque pointer to be used when the callback function is called. This can help in cases where a couple of similar timers are used (like e.g. an array of timers) and there should be a way of telling a single callback function which context the timer relates to.

## _void_ reset()
Resets the timer.

## _void_ enable()
Enable the timer

## _void_ disable()
Disables the timer.

## _void_ update()
`update()` goes inside `loop()`, which check for callback constantly.

## _void_ setPeriod( _unsigned long_ myPeriod )
Used to change the period after you had set it.

## _bool_ isEnabled()
Returns `true` is the timer is enabled while `false` if it is disabled.