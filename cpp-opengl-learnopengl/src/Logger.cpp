#include <Logger.hpp>

char* datestr(struct tm* timeinfo) {
  /* 00/00/0000 00:00:00 */
  char* string = (char*) malloc(19);

  sprintf(
    string, 
    "%d/%d/%d %d:%d:%d", 
    timeinfo->tm_mday, 
    timeinfo->tm_mon, 
    (timeinfo->tm_year) + 1900, 
    timeinfo->tm_hour, 
    timeinfo->tm_min, 
    timeinfo->tm_sec
  );

  return string;
}

int LOG(LOG_TYPE type, const char* fmt, ...) {
  FILE* fp = (FILE*) sizeof(FILE);
  bool flag_warning = false;
  bool flag_error = false;

  /* Get logging type */
  switch (type) {
    case NORMAL:
    case INFO:
    case WARNING:
      fp = stdout;
      flag_warning = true;
      break;
    case ERROR:
      fp = stderr;
      flag_error = true;
    
    default:
      fp = stdout;
      break;
  }

  const char* LOG_TYPE_NAME[4] = {
    "NORM",
    "INFO",
    "WARN",
    "ERRR"
  };

  const char* LOG_TYPE_COLOR[4] = {
    "37",
    "32",
    "33",
    "31"
  };

  /* Get current time */
  time_t      raw_time;
  struct tm*  timeinfo;

  time(&raw_time);
  timeinfo = localtime(&raw_time);

  const char* timestr = (const char*) datestr(timeinfo);
  fprintf(fp, "\033[1;%sm[%s][%s] : ", LOG_TYPE_COLOR[type], timestr, LOG_TYPE_NAME[type]);

  /* Print all */
  va_list ptr;
  va_start(ptr, fmt);
  
  int ret = vfprintf(fp, fmt, ptr); 
  printf("\033[0m\n", LOG_TYPE_COLOR[type]);
  
  va_end(ptr);

  return ret;
}

int LOG(LOG_TYPE type, String str, ...) {
  va_list ptr;
  va_start(ptr, str);
  int RET = LOG(type, str.get(), str);
  va_end(ptr);

  return RET;
}