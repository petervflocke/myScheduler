enum schedulerUnits
{
   _Millis,
   _Seconds,
   _Minutes,
   _Hours
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
    void start(long delayStartBy);
    void stop();
    void check(TaskFunctionCallback MethodeToCall, long Interval);
    bool check(long Interval);
};
