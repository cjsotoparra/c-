//
// Created by Rick Mercer on 2019-01-02.
// Finish by Christian Soto, 2019
//
// This #define tells Catch to provide a main().
// Only do this in one cpp file.
//
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include <string>
#include "LoopFun.hpp"

TEST_CASE("isPrime") {
    REQUIRE(isPrime(3));
    REQUIRE_FALSE(isPrime(9));
    REQUIRE(isPrime(2));
    REQUIRE_FALSE(isPrime(10));
    REQUIRE(isPrime(11));
    REQUIRE(isPrime(71));
    REQUIRE(isPrime(67));
    REQUIRE(isPrime(61));
    REQUIRE(isPrime(43));
    REQUIRE_FALSE(isPrime(500));
    REQUIRE(isPrime(31));
}

TEST_CASE ("fibonacci") {
	REQUIRE(1 == fibonacci(1));
	REQUIRE(1 == fibonacci(1));
	REQUIRE(2 == fibonacci(3));
	REQUIRE(3 == fibonacci(4));
	REQUIRE(5 == fibonacci(5));
	REQUIRE(8 == fibonacci(6));
	REQUIRE(13 == fibonacci(7));
	REQUIRE(21 == fibonacci(8));
}

TEST_CASE ("factorial") {
	REQUIRE(1 == factorial(0));
	REQUIRE(1 == factorial(1));
	REQUIRE(2 == factorial(2));
	REQUIRE(6 == factorial(3));
	REQUIRE(24 == factorial(4));
	REQUIRE(720 == factorial(6));
	REQUIRE(120 == factorial(5));
	REQUIRE(5040 == factorial(7));
	REQUIRE(40320 == factorial(8));
	REQUIRE(362880 == factorial(9));
	REQUIRE(3628800 == factorial(10));
 }

TEST_CASE ("vowelCount") {
	REQUIRE(11 == vowelCount("How much wood could a woodchuck chuck"));
	REQUIRE(0 == vowelCount("y+_x12x!y"));
	REQUIRE(0 == vowelCount(""));
	REQUIRE(10 == vowelCount("aeiouAeiou"));
}


TEST_CASE ("numberOfPairs") {
	REQUIRE(0 == numberOfPairs(""));
	REQUIRE(0 == numberOfPairs("a"));
	REQUIRE(1 == numberOfPairs("aa"));
	REQUIRE(2 == numberOfPairs("aaa"));
	REQUIRE(0 == numberOfPairs("BbB"));
	REQUIRE(0 == numberOfPairs("abc"));
	REQUIRE(3 == numberOfPairs("aabbcc"));
	REQUIRE(2 == numberOfPairs("!!!"));
}

TEST_CASE("isSorted") {
    // You might need to cast str.length(), an unsigned long
    // to an int like this: static_cast<int>(str.length())
	REQUIRE(isSorted(""));
	REQUIRE(isSorted("1"));
	REQUIRE(isSorted("abbcddef"));
	REQUIRE(isSorted("123456"));
	REQUIRE(isSorted("11111"));
	REQUIRE_FALSE(isSorted("12321"));
	REQUIRE_FALSE(isSorted("123452"));
	REQUIRE(isSorted("58"));
	REQUIRE_FALSE(isSorted("21"));
	REQUIRE(isSorted("135799"));
}

TEST_CASE ("howSwedish") {
    // You might need to cast str.length(), an unsigned long
    // to an int like this: static_cast<int>(str.length())
	REQUIRE(0 == howSwedish(""));
	REQUIRE(0 == howSwedish("ABB"));
	REQUIRE(0 == howSwedish("AB"));
	REQUIRE(0 == howSwedish("A"));
	REQUIRE(1 == howSwedish("AbBa"));
	REQUIRE(1 == howSwedish("AbBa a B b a"));
	REQUIRE(2 == howSwedish("!abbaABba!"));
	REQUIRE(2 == howSwedish("abbAbba"));
}

TEST_CASE ("allAsLeft") {
	REQUIRE("AAA" == allAsLeft("aaaAAA").substr(0,3));
	REQUIRE("" == allAsLeft(""));
	REQUIRE("A" == allAsLeft("A"));
	REQUIRE("G" == allAsLeft("G"));
	REQUIRE("AB" == allAsLeft("AB"));
	REQUIRE("AB" == allAsLeft("BA"));
	REQUIRE("AABCaDEFGa" == allAsLeft("ABCaDEFGaA"));
}

TEST_CASE ("mirrorEnds") {
	REQUIRE("" == mirrorEnds(""));
	REQUIRE("a" == mirrorEnds("a"));
	REQUIRE("aasdsaa" == mirrorEnds("aasdsaa"));
	REQUIRE("ab" == mirrorEnds("abXYZba"));
	REQUIRE("a" == mirrorEnds("abca"));
	REQUIRE("aba" == mirrorEnds("aba"));
	REQUIRE("racecar" == mirrorEnds("racecar"));
}

TEST_CASE ("starOut") {
	REQUIRE(starOut("sm**eil*ly") == "siy");
	REQUIRE(starOut("sm*eilly") == "silly");
	REQUIRE(starOut("ab*cd") == "ad");
	REQUIRE(starOut("ab**cd") == "ad");
	REQUIRE(starOut("a*") == "");
	REQUIRE(starOut("a*a") == "");
	REQUIRE(starOut("") == "");
	REQUIRE(starOut("abc") == "abc");
	REQUIRE(starOut("ad") == "ad");
	REQUIRE(starOut("*ab") == "b");
	REQUIRE(starOut("ab*") == "a");
	REQUIRE(starOut("******") == "");
	REQUIRE(starOut("****aaa****aa") == "aa");
}
