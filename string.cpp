#include "string.h"

String::String():
  myWord(nullptr)
{}

/**
 *  Constructor from char*
 */
String::String(const char* wordToBe)
{
  myWord = new char[strlen(wordToBe) + 1];
  strcpy(myWord, wordToBe);
}

/**
 *  String copy constructor
 */
String::String(const String& wordToBe)
{
  if(rhs.myWord != nullptr)
  {
    myWord = new char[strlen(wordToBe.c_str()) + 1];
    strcpy(myWord, wordToBe.c_str());
  }
}

/**
 * Overloaded assignment from String
 */
String& String::operator= (const String& rhs)
{
  if(this != &rhs)
  {
    if(myWord != nullptr)
    {
      delete[] myWord;
    }
    if(rhs.myWord != nullptr)
    {
      myWord = new char[strlen(rhs.c_str()) + 1];
      strcpy(myWord, rhs.c_str());
    }
  }
  return *this;
}

/**
 *  Destructor
 */
String::~String()
{
  if(myWord != nullptr)
  {
    delete[] myWord;
  }
}

/**
 *  returns character string of this String's word
 */
char* String::c_str()
{
  char* wordLeaving = new char[strlen(myWord) + 1];
  strcpy(wordLeaving, myWord);
  return wordLeaving;
}

/**
 *  Equality operator from char*
 */
// bool String::operator== (const char* rhs)
// {
//
// }

/**
 * Equality operator from String&
 */
bool String::operator== (const String& rhs) const
{
  if(strcmp(this->myWord, rhs.myWord) == 0)
  {
    return 1;
  }
  return 0;
}
