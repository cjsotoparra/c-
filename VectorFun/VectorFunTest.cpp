/**
 * This class has many test methods for testing the functions
 * that must be in a file named VectorFun.hpp
 *
 * Author  Rick Mercer and Your Name
 */
#include <vector>
#include <string>
#include "catch.hpp"
#include "VectorFun.hpp"
using namespace std;

TEST_CASE("testSortOfSort1") {
	vector<int> x = {2, 4, 3, 1};
	sortOfSort(x);
	REQUIRE(1 == *x.begin());
	REQUIRE(4 == *(x.end()-1));

	vector<string> y = {"christian", "johnny", "soto", "parra"};
	sortOfSort(y);
	REQUIRE("christian" == *y.begin());
	REQUIRE("soto" == *(y.end()-1));

	vector<int> check_length = {1};
	sortOfSort(check_length);
	REQUIRE(1 == *check_length.begin());
	REQUIRE(1 == *(check_length.end()-1));

	vector<int> length2 = {2,1};
	sortOfSort(length2);
	REQUIRE(1 == *length2.begin());
	REQUIRE(2 == *(length2.end()-1));

	vector<int> length3 = {1,2};
	sortOfSort(length3);
	REQUIRE(1 == *length3.begin());
	REQUIRE(2 == *(length3.end()-1));

	vector<int> a = {4,3,2,0,1,2};
	sortOfSort(a);
	REQUIRE(0 == *a.begin());
	REQUIRE(4 == *(a.end()-1));

	vector<int> b = {4,3,2,1};
	sortOfSort(b);
	REQUIRE(1 == *b.begin());
	REQUIRE(4 == *(b.end()-1));

	vector<int> c = {-1,3,2,4};
	sortOfSort(c);
	REQUIRE(-1 == *c.begin());
	REQUIRE(4 == *(c.end()-1));
}


TEST_CASE("testNumberOfPairs1") {
    vector<string> s1{"a", "b", "c"};
    REQUIRE(0 == numberOfPairs(s1));
}

/*
TEST_CASE("testSumIsGreater") {
    vector<double> x = {1.1, 2.2, 3.3};
    REQUIRE(sumGreaterThan(x, 4.0));
}

TEST_CASE("testSumIsGreater2") {
    vector<double> x2 = {1.1, 2.2, 3.3};
    REQUIRE(!sumGreaterThan(x2, 6.6));
}

TEST_CASE("testFrequency") {
    vector<int> nums{1, 1, 1, 3, 3, 5, 6, 6, 10, 10, 10};
    vector<int> result = frequency(nums);
    REQUIRE(0 == result[0]);
    REQUIRE(3 == result[1]);
    REQUIRE(0 == result[2]);
    REQUIRE(2 == result[3]);
    REQUIRE(0 == result[4]);
    REQUIRE(1 == result[5]);
    REQUIRE(2 == result[6]);
    REQUIRE(0 == result[7]);
    REQUIRE(0 == result[8]);
    REQUIRE(0 == result[9]);
    REQUIRE(3 == result[10]);
}

TEST_CASE("testFailedHowMany") {
    vector<string> strs{"a", "C", "X", "x", "b", "a", "b",
                        "b", "a",
                        "b", "a"};
    REQUIRE(4 == howMany(strs, "b"));
}

TEST_CASE("testEvensLeft") {
    vector<int> a = {1, 2, 3, 4, 5, 6, 7};
    evensLeft(a);
// left side of the array at indexes 0..2 is even
    for (int i = 0; i <= 2; i++)
        REQUIRE(0 == a[i] % 2);
// right side of the array at indexes 3..6 is odd
    for (int i = 3; i <= 6; i++)
        REQUIRE(1 == a[i] % 2);
}


TEST_CASE("testShiftNTimes") {
    vector<int> a = {1, 2, 3};
    shiftNTimes(a, 1);
    REQUIRE(2 == a[0]);
    REQUIRE(3 == a[1]);
    REQUIRE(1 == a[2]);
}


TEST_CASE("testRange") {
    vector<int> x = { 4 };
    REQUIRE(0 == range(x));
}


TEST_CASE("fizzBuzz") {
    vector<string> strs = fizzBuzz(1, 6);
    REQUIRE("1" == strs[0]);
    REQUIRE("2" == strs[1]);
    REQUIRE("Fizz" == strs[2]);
    REQUIRE("4" == strs[3]);
    REQUIRE("Buzz" == strs[4]);
}
*/
