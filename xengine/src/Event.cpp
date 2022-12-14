#include "Event.h"

int Tridme::KEY(int code) {
  int newCode = code;
  #ifdef __linux__
  newCode -= 27;
  #endif

  return newCode;
}