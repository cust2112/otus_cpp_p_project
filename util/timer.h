#ifndef TIMER_H
#define TIMER_H

#include <chrono>
#include <cstdio>


#define USE_TIMER


#ifdef USE_TIMER
class Timer {
public:
    explicit Timer (const char *intervalName)
        : intervalName (intervalName),
          startT (std::chrono::steady_clock::now ()) {}

    ~Timer ()
    {
        auto endT = std::chrono::steady_clock::now ();
        std::chrono::duration<double> elapsedSeconds = endT - startT;

        printf ("%s: %f sec.\n", intervalName, elapsedSeconds.count ());
    }


private:
    const char *intervalName;
    std::chrono::time_point<std::chrono::steady_clock> startT;
};
#else
class Timer {
public:
    explicit Timer (const char *intervalName) { (void) intervalName; }
};
#endif


#define WORKS_IMPLICITLY(x) (void) (x);

#define MEASURE_SCOPE_EXEC_TIME(x) Timer t (x);  WORKS_IMPLICITLY (t)
#define START_TIMER(x) { MEASURE_SCOPE_EXEC_TIME (x)
#define STOP_TIMER(x)    (void) (x); }

#endif // TIMER_H
