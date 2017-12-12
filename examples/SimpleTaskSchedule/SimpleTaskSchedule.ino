#include <myScheduler.h>
#include <TimeLib.h>

int led = 2;
Schedular Task1(_Millis);

void setup() {
  setTime(1512093784); // Friday, December 1, 2017 2:03:04 AM
  pinMode(led, OUTPUT);
  Task1.start(-400); // -400 + 500 = -100 after 100 ms it will start for the fisrt time
}

void loop() {
    Task1.check(TaskToPerform,500);  //
}

void TaskToPerform()
{
  // Flash the onboard led
  digitalWrite(led, HIGH);
  delay(100);
  digitalWrite(led, LOW);
}
