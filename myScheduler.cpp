#include "myScheduler.h"
#include <Arduino.h>

Schedular::Schedular()
{
  _lastRun = 0;
}

// Check if task needs to run
void Schedular::check(TaskFunctionCallback MethodeToCall,unsigned long Interval) {
    if(_lastRun > 0 && _lastRun+Interval < millis()) {
      MethodeToCall();
      _lastRun = millis();
    };
}

bool Schedular::check(unsigned long Interval) {
    if(_lastRun > 0 && _lastRun+Interval < millis()) {
      _lastRun = millis();
      return true;
    };
    return false;
}

// Start as soon as the the function fires
void Schedular::start() {
  _lastRun = millis()+1;
}

// Delays start by 'delayStartBy' milli seconds
void Schedular::start(long delayStartBy) {
  _lastRun = millis()+delayStartBy;
}

// Stops Task
void Schedular::stop() {
  _lastRun = 0;
}
