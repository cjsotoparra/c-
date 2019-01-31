/*
 * VectorFun.hpp
 *
 * This cpp file implements 10 functions related by the fact
 * that CSC 382 students are learning how to use std::vector
 * and template functions. There are several silly contrived
 * methods, some actually helpful like FizzBuzz, a question
 * often asked in job interviews.
 *
 * @Programmers Rick Mercer and Christian Soto, 2019
 */
#ifndef SRC_VECTORFUN_HPP_
#define SRC_VECTORFUN_HPP_

#include <string>
#include <vector>
#include <iostream>

// You may not use an existing sort function for this.
// If you do, you will lose all points!
//
// Precondition: The type of vector has the < operation
// Your code can only compare with <
//
// Write method sortOfSort that modifies the parameter vector
// to place the largest element at vec(size()-1) and the
// smallest element at vec[0]. The other elements must still
// be in the vector, but not in any particular order. You
// must modify the given vector argument by changing array
// in method sortOfSort. The order may differ except the first and last.
//
// Original vector . . . . . Modified vector (middle elements may differ in order)
// { 4, 3, 2, 0, 1, 2 } . .  { 0, 3, 2, 1, 2, 4 }
// { 4, 3, 2, 1 } . . . . .  { 1, 3, 2, 4 }
// { -1, 3, 2, 4 } . . . . . { -1, 3, 2, 4 }
//
// The vector must be passed by reference so the argument is changed.
// It is also more efficient.
//
// You may not use an existing sort function for this.
// If you do, you will lose 10 points!
//
// Precondition T must overload > and <
template<typename T>
void sortOfSort (std::vector<T> &vec) {

	//check lengths
	if(vec.size() <= 1){
		return;
	}

	//check the ends of the vector to swap if needed
	if(*vec.begin() > *(vec.end()-1)){
		auto temp = *vec.begin();
		*vec.begin() = *(vec.end()-1);
		*(vec.end()-1) = temp;
	}

	//check of vector being just 2 elements
	if(vec.size() <=2){
		return;
	}

	//assign smallest and biggest values with no ends
	auto small{*vec.begin()};
	auto big{*(vec.end()-1)};

	//iterate over the vector and check both ends
	for(auto itr = vec.begin()+1; itr != vec.end()-1; itr++){

		//check if the current values is smaller than smallest
		if(*itr < small){
			*vec.begin() = *itr;
			*itr = small;
			small = *vec.begin();

		//check if current value is bigger than big
		}else if(*itr > big){
			*(vec.end()-1) = *itr;
			*itr = big;
			big = *(vec.end()-1);

		}//if else

	}//for loop

}

// Return the number of times a pair occurs in a vector.
// A pair is any two vector element that are == in
// consecutive vector elements. The vector may be empty or
// have only one element, in these cases two cases, return 0.
//
// numberOfPairs( 1, 1, 1 ) returns 2
// numberOfPairs( 1, 2, 1, 2, 1 ) returns 0
// numberOfPairs( {"a", "b", "c" } ) returns 0
// numberOfPairs( {"a", "a", "a"} ) returns 2
// numberOfPairs( {"a", "a", "b", "b" } ) returns 2
// numberOfPairs( { } ) returns 0
// numberOfPairs( {"a"} ) returns 0
//
// Precondition T must overload ==
template<typename T>
int numberOfPairs (std::vector<T> const &vec) {

	//check length first before any calculations
	if(vec.size() <= 1){
		return 0;
	}

	auto pairs{0};
	auto next = vec.begin()+1;

	for(auto itr = vec.begin(); itr != vec.end()-1; itr++){

		if(*itr == *next){

			pairs+=1;
		}

		next++;

	}

	return pairs;
}


// Given a filled vector of double elements, return true if
// the sum of all elements is greater than sum. Sum may be
// negative. An empty vector's sum is zero.
//
// sumGreaterThan( { 1.1, 2.2, 3.3 }, 4.0) returns true
// sumGreaterThan( { 1.1, 2.2, 3.3 }, 6.6) returns false
// sumGreaterThan( { }, -1.0) returns true
//
bool sumGreaterThan (std::vector<double> const &numbers,
                     double sum) {

	//check empty vector
	if(numbers.size() == 0){
		return 0>sum;
	}

	//check length of one
	if(numbers.size() ==1){
		return *(numbers.begin()) > sum;
	}

	//length more than 1, iterate
	auto sumOfVector{0};

	for(auto itr = numbers.begin(); itr != numbers.end(); itr++){

		sumOfVector += *itr;
	}

    return sumOfVector > sum;
}

// Complete method howMany to return the number of elements
// in a vector of strings that equals valueToFind. The vector
// may be empty.
//
// howMany({"A", "a", "A", "a" }, "A") returns 2
// howMany({"And", "there", "goes", "another"}, "another") returns 1
// howMany({"And", "there", "goes", "another"}, "Not Here") returns 0
// howMany({ }, "empty array") returns 0
//
int howMany (std::vector<std::string> const &array,
             std::string const &valueToFind) {

	//check empty array
	if(array.size() == 0){
		return 0;
	}

	auto num{0};

	for(auto itr : array){

		if(itr == valueToFind){
			num += 1;
		}
	}

    return num;
}

/*
// Given a vector containing a stream of integers in the
// range of 0..10 (like quiz scores), return an array of 11
// integers where the first value (at index 0) is the number
// of 0s in the vector, the second value (at index 1) is the
// number of ones on the vector, and the 11th value
// (at index 10) is the number of tens in the vector.
// The following assertions must pass.
//
// Given the argument vector<int> arg {5,0,7,7,7,9,9,5,8,10};,
// frequency must return a vector that looks like this
// {1,0,0,0,0,2,0,3,1,2,1}
//
// Precondition: The vector argument has ints only in
// the range of 0..10 only.
std::vector<int> frequency (std::vector<int> const &vec) {
    // TODO: Complete this function
    return { -1, -2, -3 };
}


// Modify the argument associated with array so it still
// contains the exact same numbers as the given array,
// but rearranged so that all the even numbers come before
// all the odd numbers. Other than that, the numbers can be
// in any order. You must modify the array argument by
// changing array in method evensLeft.  The array may be
// empty or have only 1 element so no change should be made.
//
// Original Array. . . . . Modified Array, return by reference,
// Do not have a return statement
// {1, 0, 1, 0, 0, 1, 1} . { 0, 0, 0, 1, 1, 1, 1 }
// {3, 3, 2} . . . . . . . { 2, 3, 3 }
// {3, -2, -2} . . . . . . . { -2, -2, 3}
//
// vec Must be a reference parameter with & so changes made here
// are made to the argument array is referencing in the unit test.
//
// Do NOT use a return statement
void evensLeft (std::vector<int> &vec) {
    // TODO: Complete this function
}


// Modify numbers so it is "left shifted" n times --
// so shiftNTimes({6, 2, 5, 3}, 1) changes the vector
// argument to {2, 5, 3, 6} and shiftNTimes({6, 2, 5, 3}, 2)
// changes the array argument to {5, 3, 6, 2}. You must
// modify the vector argument by changing the parameter
// array inside method shiftNTimes. Remember, a change to
// the parameter inside the method shiftNTimes changes
// the argument inside the test function.
//
// shiftNTimes( { 1, 2, 3, 4, 5, 6, 7 }, 3 )
// modifies the argument to { 4, 5, 6, 7, 1, 2, 3 }
//
// shiftNTimes( { 1, 2, 3, 4, 5, 6, 7 }, 0 )
// does not modify the array
//
// shiftNTimes( { 1, 2, 3 }, 5)
// modifies the array argument to { 3, 1, 2 }
//
// shiftNTimes( { 3 }, 5) modifies array to { 3 }
//
// Do NOT return anything
template<typename T>
void shiftNTimes (std::vector<T> &vec, int &&numShifts) {
    // TODO: Complete this function
}


// Return the range of the numbers in an array[].
// The range is the maximum value - minimum value
//
// range ({1, 2, 3, 4}) returns 4 - 1 or 3
// range ({1, 2, -3, 4}) returns 4 - -3 or 7
// range ({ 99 }) returns 0
//
// Precondition: x.length >= 1
int range (std::vector<int> const &x) {
    // Do NOT use a return statement
    return -999;
}

// Consider the series of numbers beginning at start and
// running up to but not including end, so for example
// start=1 and end=5 gives the series 1, 2, 3, 4. Return a
// new std::vector<std:string> containing the string form
// of these numbers. However for multiples of 3, store "Fizz"
// instead of the number. For multiples of 5 use "Buzz".
// For multiples of both 3 and 5 use "FizzBuzz". In C++,
// std::to_string will make a str::string from an int.
// std::to_string(12) returns the string literal "12"
//
// fizzBuzz(1, 6) returns ["1", "2", "Fizz", "4", "Buzz"]
// fizzBuzz(1, 8) returns ["1", "2", "Fizz", "4", "Buzz", "Fizz", "7"]
// fizzBuzz(14, 21) returns ["14", "FizzBuzz", "16", "17", "Fizz", "19"]
//
// Precondition: end > start so the return so vector's size() >= 1
std::vector<std::string>
fizzBuzz (unsigned long &&start, unsigned long &&end) {
    // Do NOT use a return statement
    return { "X", "Y", "Z" };
}
*/
#endif // SRC_VECTORFUN_HPP_
