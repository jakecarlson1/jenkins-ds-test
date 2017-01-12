#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include <cstring>
#include "string.h"


TEST_CASE("String class", "[string]")
{
  String str[10];
  str[0] = String("this is a string");
  str[1] = String("");
  str[2] = String("this is not an empty string");

  SECTION("Constructors")
  {
    REQUIRE(strcmp(str[0].c_str(), "this is a string") == 0);
    REQUIRE(strcmp(str[1].c_str(), "") == 0);
    REQUIRE(strcmp(str[2].c_str(), "this is not an empty string") == 0);
  }

  SECTION("Comparison Operators")
  {
    REQUIRE(str[0] == String("this is a string"));

  }
}
