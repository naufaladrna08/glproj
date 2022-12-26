#ifndef LOGGER_H
#define LOGGER_H
#include <cstdio>
#include <cstdarg>
#include <ctime>
#include <cstdlib>
#include <cstring>
#include <String.hpp>

enum LOG_TYPE {
  NORMAL,
  INFO,
  WARNING,
  ERROR
};

char* datestr(struct tm* timeinfo);

int LOG(LOG_TYPE type, const char* fmt, ...);
int LOG(LOG_TYPE type, String str, ...);

#endif