// This #define tells Catch to provide a main().
// Only do this in one, and only one cpp file.
#define CATCH_CONFIG_MAIN

#include "catch.hpp" // for the testing framework named Catch2

#include <string> // for class string
#include "SelectionFun.hpp" // for the 12 functions under test

/*
 * This unit test has at least one test method for each of
 * the 12 methods in SelectionFun.hpp. However, they are
 * incomplete and do not represent 100% code coverage.
 * This is meant to encourage you to think of other
 * needed test cases and add your own REQUIREs.
 * The TEST_CASES() should average about 12 REQUIRES each.
 *
 * We will run a unit test that is much much larger unit test
 * than this starter unit test (we have about 140 REQUIRE
 * or REQUIRE_FALSE macros.
 *
 * Think of as many test cases as you can.
 *
 * Programmers: Rick Mercer and YourFirstName YourLastName
 */

/////////////////////////////////////////////////////////
// Unit test some calendar functions using primitive types

// The argument is the name of the function being tested.
// In this first TEST_CASE, thanksDate is under test.
/*TEST_CASE ("thanksDate") {
    REQUIRE(25 == thanksDate(1));
}


TEST_CASE ("dayOfWeek") {
    // REQUIRE("Monday" == dayOfWeek(1));
    // REQUIRE("Unknown" == dayOfWeek(8));
}


TEST_CASE ("daysInMonth") {
    // REQUIRE(31 == daysInMonth(1, 2018));
}


TEST_CASE ("season") {
    // REQUIRE("Winter" == season(12, true));
}


TEST_CASE ("validDate when valid") {
    // REQUIRE(validDate("01/01/2019"));
    // Many, many more REQUIRES are need to fully test validDate
}

TEST_CASE ("validDate when not valid") {
    // This passes because the function stub always returns !true
    // REQUIRE_FALSE(validDate("02/29/2019"));
    // Many, many more REQUIRES are need to fully test validDate
}
*/
TEST_CASE ("dayNumber") {
     REQUIRE(-1 == dayNumber("02/29/2019"));
     REQUIRE(-1 == dayNumber("13/11/2020"));
     REQUIRE(3 == dayNumber("01/03/2016"));
}


////////////////////////////////////////////////////////
// Test some string functions using string messages

TEST_CASE("string combo(std::string, string") {
      REQUIRE("hiHellohi" == combo("Hello", "hi"));
}


TEST_CASE("concatMin") {
     REQUIRE("123456" == concatMin("123", "456"));
     REQUIRE("loHi" == concatMin("Hello", "Hi"));
     REQUIRE("javaello" == concatMin("java", "Hello"));
}


TEST_CASE("firstOf3") {
    // REQUIRE("MA" == firstOf3("ma", "ma", "MA"));
}


TEST_CASE("fizzBuzz") {
    // REQUIRE("Fizz" == fizzBuzz("f"));
}
