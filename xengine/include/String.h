#ifndef STRING_H
#define STRING_H
#include <stdlib.h>
#include <string.h>
#include <cstdio>

class String {
  public:
    String(const char* string);
    ~String();

    int Assign(const char* string);

    int operator=(const char* string);
    int operator+(const char* string);
    int operator+=(const char* string);

    char* get();

    static int Length(const char* string);
    static int Replace(const String& str, const char* find, const char* replace);
  
  private:
    char* m_data;
};

#endif