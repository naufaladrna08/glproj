#include <Core/Timer.hpp>
using namespace Tridme;

void Timer::Init() {
  clock_gettime(CLOCK_REALTIME, &m_startTime);
}

unsigned long Timer::GetCurrentTime() {
  struct timespec ts;
  clock_gettime(CLOCK_REALTIME, &ts);

  return (unsigned long) ts.tv_sec * 1000000000 + (unsigned long) ts.tv_nsec;
}