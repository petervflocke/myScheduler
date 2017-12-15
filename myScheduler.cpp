#include "myScheduler.h"
#include <TimeLib.h>
#include <Arduino.h>

Schedular::Schedular(schedulerUnits _units)
{
  Schedular::_units   = _units;
  Schedular::_working = false;
}

inline unsigned long Schedular::getTimeByUnit() {
   return (_units==_Millis)? millis():now();
}

unsigned long Schedular::calcTimeByUnit(unsigned long _tt) {
  return _tt;
  // switch (_units) {
  //   case _Millis  : return _tt;
  //   case _Seconds : return _tt;
  //   case _Minutes : return _tt * SECS_PER_MIN;
  //   case _Hours   : return _tt * SECS_PER_HOUR;
  // }
}

// Check if task needs to run
void Schedular::check(TaskFunctionCallback MethodeToCall, long Interval) {
    unsigned long _tmp = getTimeByUnit();
    // Serial.print("now=");
    // Serial.print(_tmp);
    // Serial.print(" last=");
    // Serial.print(_lastRun);
    // Serial.print(" now-last=");
    // Serial.println(long(_tmp - _lastRun));

    //if(_working && abs(long(_tmp - _lastRun)) >= long(calcTimeByUnit(Interval))) {
    if(_working && abs((long)(_tmp - _lastRun)) >= Interval) {
//      Serial.println("OK");
      MethodeToCall();
      _lastRun = _tmp;
    };
}


bool Schedular::check(long Interval) {
    unsigned long _tmp = getTimeByUnit();
    // if(_working && abs(long(_tmp - _lastRun)) >= long(calcTimeByUnit(Interval))) {
    if(_working && abs((long)(_tmp - _lastRun)) >= Interval) {
      _lastRun = _tmp;
      return true;
    };
    return false;
}

// Start as soon as the the function fires
void Schedular::start() {
  _lastRun = getTimeByUnit();
  _working = true;
}

// Delays start by 'delayStartBy' milli seconds
void Schedular::start(long delayStartBy) {
  // Serial.print("Last=");Serial.println(_lastRun);
  // Serial.print("Delay");Serial.println(((delayStartBy >= 0)?1:-1)*calcTimeByUnit(abs(delayStartBy)));
  // _lastRun = getTimeByUnit()+((delayStartBy >= 0)?1:-1)*calcTimeByUnit(abs(delayStartBy));
  _lastRun = getTimeByUnit()+delayStartBy;
  _working = true;
}

// Stops Task
void Schedular::stop() {
  _working = false;
}
