#ifndef STRING_H
#define STRING_H

#include <iostream>
#include <cstring>

class String
{
public:
  String();
  String(const char*);
  String(const String&);

  // String& operator= (const char*);
  String& operator= (const String&);
  String operator+ (const String&);
  bool operator== (const char*);
  bool operator== (const String&) const;
  bool operator> (const String&);
  char& operator[] (const int);

  int size();
  String substring(int, int);
  char* c_str();

  /**
   * Stream insertion operator
   */
  friend std::ostream& operator<< (std::ostream& os, const String& rhs)
  {
    os << rhs.myWord;
    return os;
  }

  ~String();

private:
  char* myWord;

};

#endif // STRING_H
