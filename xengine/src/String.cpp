#include <String.h>

String::String(const char* string) {
  this->Assign(string);
}

String::~String() {

}

int String::Assign(const char* string) {
  /* Sanitize */
  if (string == NULL)
    return -1;

  this->m_data = (char*) malloc(Length(string));
  strcpy(this->m_data, string);

  return 0;
}

int String::operator=(const char* string) {
  return this->Assign(string);
}

int String::operator+(const char* string) {
  if (string == NULL) 
    return -1;

  int newSize    = Length(string);
  int beforeSize = Length(m_data);
  int size       = Length(m_data) + Length(string);

  m_data = (char*) realloc(m_data, size);

  for (int i = 0; i < newSize; i++) {
    m_data[i + beforeSize] = string[i];
  }

  return 0;
}

int String::operator+=(const char* string) {
  if (string == NULL) 
    return -1;

  int newSize    = Length(string);
  int beforeSize = Length(m_data);
  int size       = Length(m_data) + Length(string);

  m_data = (char*) realloc(m_data, size);

  for (int i = 0; i < newSize; i++) {
    m_data[i + beforeSize] = string[i];
  }

  return 0;
}

int String::Length(const char* string) {
  int i = 1;
  while (string[i] != '\0') i++;
  return i;
}

char* String::get() {
  return m_data;
}

int String::Replace(const String& str, const char* find, const char* replace) {
  char* match = strstr(str.m_data, find);

  if (!match) return 1;
  int replace_len = strlen(replace);
  int search_len = strlen(find);

  // Calculate the length of the string after replacing the search string
  // with the replace string
  int new_len = strlen(str.m_data) + replace_len - search_len;

  // Create a new string to hold the modified string
  char new_str[new_len + 1];

  // Copy the original string up to the first occurrence of the search string
  strncpy(new_str, str.m_data, match - str.m_data);
  strncpy(new_str + (match - str.m_data), replace, replace_len);
  strncpy(new_str + (match - str.m_data) + replace_len, match + search_len, strlen(match) - search_len);
  new_str[new_len] = '\0';
  strcpy(str.m_data, new_str);

  return 0;
}