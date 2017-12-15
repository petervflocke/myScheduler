enum schedulerUnits
{
   _Millis,
   _Seconds
};

typedef void  (*TaskFunctionCallback) ();

class Schedular {
  private:
    schedulerUnits _units;
    unsigned long _lastRun;
    bool _working;
    unsigned long getTimeByUnit();
    unsigned long calcTimeByUnit(unsigned long _tt);

  public:
    Schedular(schedulerUnits _units);
    void start();

    // +back -delay  (+100 -20 => move firt start by 100 assuming 20 delay)
    void start(long delayStartBy);
    void stop();
    void check(TaskFunctionCallback MethodeToCall, long Interval);
    bool check(long Interval);
};
