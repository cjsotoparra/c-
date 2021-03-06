/**
 * This class has many test methods for testing the functions
 * that must be in a file named VectorFun.hpp
 *
 * Author  Rick Mercer and Christian Soto, 2019
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

	vector<int> twoPair = {1,1,1};
	REQUIRE(2 == numberOfPairs(twoPair));

	vector<string> s2{"christian", "christian"};
	REQUIRE(1 == numberOfPairs(s2));

	vector<string> s3{"christian"};
	REQUIRE(0 == numberOfPairs(s3));

	vector<string> s4{};
	REQUIRE(0 == numberOfPairs(s4));

	vector<int> i1{1,2,1,2,1};
	REQUIRE(0 == numberOfPairs(i1));

	vector <string> s5{"a","a","a","a"};
	REQUIRE(3 == numberOfPairs(s5));

	vector<string> s6{"a","a","b","b","c","c"};
	REQUIRE(3 == numberOfPairs(s6));
}


TEST_CASE("testSumIsGreater") {
	vector<double> d1{};
	REQUIRE(sumGreaterThan(d1, -1));

	vector<double>d2{0};
	REQUIRE(sumGreaterThan(d2, -1));

	vector<double> d3{0};
	REQUIRE_FALSE(sumGreaterThan(d3, 0));

	vector<double> x = {1.1, 2.2, 3.3};
	REQUIRE(sumGreaterThan(x, 4.0));

	vector<double> d4{1.1,2.2,3.3};
	REQUIRE_FALSE(sumGreaterThan(d4,6.6));
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

	vector<int> nums2{5,0,7,7,7,9,9,5,8,10};
        vector<int> result2 = frequency(nums2);
        REQUIRE(1 == result2[0]);
        REQUIRE(0 == result2[1]);
        REQUIRE(0 == result2[2]);
        REQUIRE(0 == result2[3]);
        REQUIRE(0 == result2[4]);
        REQUIRE(2 == result2[5]);
        REQUIRE(0 == result2[6]);
        REQUIRE(3 == result2[7]);
        REQUIRE(1 == result2[8]);
        REQUIRE(2 == result2[9]);
        REQUIRE(1 == result2[10]);
}

TEST_CASE("testFailedHowMany") {
	vector<string> strs{"a", "C", "X", "x", "b", "a", "b",
                        "b", "a",
                        "b", "a"};
	REQUIRE(4 == howMany(strs, "b"));

	vector<string> s1{};
	REQUIRE(0 == howMany(s1, "empty"));

	vector<string> s2{"And", "there", "goes", "another"};
	REQUIRE(1 == howMany(s2, "another"));

	vector<string> s3{"And", "there", "goes", "another"};
	REQUIRE(0 == howMany(s3, "Not here"));

	vector<string> s4{"A", "a", "A", "a"};
	REQUIRE(2 == howMany(s4, "A"));
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


	vector<int> b = {3,-2,-2};
	evensLeft(b);
	//Left side
	for(int i = 0; i <=1; i++){
		REQUIRE(0 == b[i]%2);
	}
	//Right side
	for(int i = 2; i<2; i++){
		REQUIRE(1 == b[i] % 2);
	}

	vector<int> c {1,0,1,0,0,1,1};
	evensLeft(c);

	//Left side
	for(int i = 0; i <= 2; i++){
		REQUIRE(0 == c[i] % 2);
	}

	//Right side
	for(int i = 3; i <= 6; i++){
		REQUIRE(1 == c[i] % 2);
	}
}


TEST_CASE("testShiftNTimes") {
	vector<int> a = {1, 2, 3};
	shiftNTimes(a, 1);
	REQUIRE(2 == a[0]);
	REQUIRE(3 == a[1]);
	REQUIRE(1 == a[2]);

	vector<string> s1{"christian", "Johnny", "soto", "parra"};
	shiftNTimes(s1, 0);
	REQUIRE("christian" == s1[0]);
	REQUIRE("Johnny" == s1[1]);
	REQUIRE("soto" == s1[2]);
	REQUIRE("parra" == s1[3]);

	vector<string> s2{"christian", "Johnny", "soto", "parra"};
	shiftNTimes(s2, 1);
        REQUIRE("christian" == s2[3]);
        REQUIRE("Johnny" == s2[0]);
        REQUIRE("soto" == s2[1]);
        REQUIRE("parra" == s2[2]);

	vector<string> s3{"christian", "Johnny", "soto", "parra"};
	shiftNTimes(s3, 2);
        REQUIRE("soto" == s3[0]);
        REQUIRE("parra" == s3[1]);
        REQUIRE("christian" == s3[2]);
        REQUIRE("Johnny" == s3[3]);

	vector<string> s4{"christian", "Johnny", "soto", "parra"};
	shiftNTimes(s4, 3);
        REQUIRE("christian" == s4[1]);
        REQUIRE("Johnny" == s4[2]);
        REQUIRE("soto" == s4[3]);
        REQUIRE("parra" == s4[0]);

	vector<string> s5{"christian", "Johnny", "soto", "parra"};
	shiftNTimes(s5, 4);
        REQUIRE("christian" == s5[0]);
        REQUIRE("Johnny" == s5[1]);
        REQUIRE("soto" == s5[2]);
        REQUIRE("parra" == s5[3]);

	vector<string> s6{"christian", "Johnny", "soto", "parra"};
	shiftNTimes(s6, 8);
        REQUIRE("christian" == s6[0]);
        REQUIRE("Johnny" == s6[1]);
        REQUIRE("soto" == s6[2]);
        REQUIRE("parra" == s6[3]);

	vector<int> v2{1,2,3,4,5,6,7};
	shiftNTimes(v2, 3);
	REQUIRE(4 == v2[0]);
	REQUIRE(3 == v2[6]);

	vector<int>v3{999};
	shiftNTimes(v3, 10000);
	REQUIRE(999 == v3[0]);

}


TEST_CASE("testRange") {
	vector<int> x = { 4 };
	REQUIRE(0 == range(x));

	vector<int> x1 ={1,2,3,4};
	REQUIRE(3 == range(x1));

	vector <int> x2 = {1,2,-3, 4};
	REQUIRE(7 == range(x2));
}

TEST_CASE("fizzBuzz") {
	vector<string> strs = fizzBuzz(1, 6);
	REQUIRE("1" == strs[0]);
	REQUIRE("2" == strs[1]);
	REQUIRE("Fizz" == strs[2]);
	REQUIRE("4" == strs[3]);
	REQUIRE("Buzz" == strs[4]);

	vector<string> s1 = fizzBuzz(14, 21);
	REQUIRE("14" == s1[0]);
	REQUIRE("FizzBuzz" == s1[1]);
	REQUIRE("16" == s1[2]);
	REQUIRE("Buzz" == s1[6]);
}

