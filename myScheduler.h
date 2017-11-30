typedef void  (*TaskFunctionCallback) ();

class Schedular {
  private:
    unsigned long _lastRun;
  public:
    Schedular();
    void start();
    void start(long delayStartBy);
    void stop();
    void check(TaskFunctionCallback MethodeToCall, unsigned long Interval);
    bool check(unsigned long Interval);
};
