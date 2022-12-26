#ifndef TIMER_HPP
#define TIMER_HPP
#include <time.h>

namespace Tridme {
  class Timer {
    public:
      void Init();

      unsigned long GetCurrentTime();

    private:
      struct timespec m_startTime;
      double m_time;
  };
};

#endif