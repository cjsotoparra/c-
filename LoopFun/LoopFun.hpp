/*
 * LoopFun.cpp
 *
 * LoopFun.cpp contains ten free functions that require a
 * while or a for loop. Some some perform mathematical
 * calculations, some process strings.
 *
 * Programmer Rick Mercer and Christian Soto, 2019
 */
#ifndef LOOPFUN_HPP_
#define LOOPFUN_HPP_

#include <string> // for class string

// 1) isPrime
//
// One evening, while listening intently at the Very Large Array
// (VLA) radio astronomy observatory 333 miles east of Oro
// Valley AZ, Ellie hears a powerful signal: a prime number
// pattern emanating from the star Vega, confirmed by others
// the world over, undeniable and strong in its pulsing power.
// What Ellie recognized was the repeating series of the
// first 26 prime numbers. This is someone near Vega trying
// to contact anyone who is listening:
//
//  2 3 5 7 11 13 17 19 23 29 31 37 41 43 47 53 59 61 67 71
//
// A prime number is a natural number greater than 1 that has
// no positive divisors other than 1 and itself. Complete
// function isPrime that returns true if the argument is a
// prime number. Hint: Consider writing a loop that divides
// the argument num by every integer from 2 to num-1,
// returning false if num was found to be evenly divisible
// by any one of those.
//
//  isPrime(10) returns false
//  isPrime(11) returns true
//
bool isPrime (int num) {

	for(int i = 2; i<num; i++){

		if(num%i == 0){
			return false;
		}
	}//for loop
    return true;
}


// 2) fibonacci
//
// In the movie "The Da Vinci Code" with Tom Hanks, this password
// used to unlock a much sought after artifact: 1 2 3 5 8 13 21.
// These are the 2nd through 8th Fibonacci numbers. Fibonacci numbers
// have so much interest, there exists a Fibonacci Quarterly
//
//   http://www.fq.math.ca/
//
// Implement function fibonacci that returns the nth Fibonacci number.
// Fibonnaci numbers can be computed as the sum of the preceeding two.
// You will find it useful to keep track the two previous Fibonacci
// numbers. This is harder than it looks.
//
//  fibonacci(1) returns 1
//  fibonacci(2) returns 1
//  fibonacci(3) returns 2
//  fibonacci(4) returns 3
//  fibonacci(5) returns 5
//  fibonacci(6) returns 8
//
int fibonacci (int n) {

	if(n == 0){
		return 0;
	}

	if(n == 1 || n == 2){
		return 1;
	}


	return fibonacci(n-1) + fibonacci(n-2);
}


// 3) factorial
//
// Given an integer argument return n factorial, which is written as n!.
// 5! = 5*4*3*2*1 or in general, n! = n*(n-1)*(n-2) …*2*1. Use a for loop.
//
//  factorial(0) returns 1
//  factorial(1) returns 1
//  factorial(2) returns 2, which is 2 * 1
//  factorial(3) returns 6, which is 3 * 2 * 1
//  factorial(4) returns 24, which is 4 * 3 * 2 * 1
//
;// Precondition: n >= 0
//
int factorial (int n) {
	if(n == 0 || n == 1){
		return 1;
	}

	int result = 1;
	for(int i = 1; i<=n ; i++){
		result = result * i;
	}

	return result;
}


// 4) vowelCount
//
// "How much wood could a woodchuck chuck" contains 11 vowels.  How do we
// know? Five of the 26 English alphabet letters are vowels: a, e, i, o,
// and u. By looking at each letter in the woodchuck string, we find
// 11 vowels. Complete function vowelCount that returns the number of vowels
// in the given std::string argument. This is case insensitive. Upper and lower
// case vowels count. We do not consider y to be a vowel.
//
//  vowelCount("a e i o u A E I O U") returns 10
//  vowelCount("y+_x1Y2x!y") returns 0
//
int vowelCount (std::string str) {

	int count = 0;

	for(int i = 0; i<str.length(); i++){

		switch(str[i]){
			case 'a':
			case 'A':
			case 'e':
			case 'E':
			case 'i':
			case 'I':
			case 'o':
			case 'O':
			case 'u':
			case 'U':
				count = count + 1;
		}
	}
    return count;
}


// 5) numberOfPairs
//
// Return the number of times two consecutive characters occur in str.
// This is case sensitive:
//
//  numberOfPairs ("BbB") returns 0
//  numberOfPairs ("") returns 0
//  numberOfPairs ("abc") returns 0
//  numberOfPairs ("aabbcc") returns 3
//  numberOfPairs ("!!!") returns 2
//
int numberOfPairs (std::string str) {
	if(str.length() < 2){
		return 0;
	}

	int pairs = 0;

	for(int i = 0; i<str.length()-1; i++){

		if(str[i] == str[i+1]){
			pairs = pairs + 1;
		}
	}

    return pairs;
}


// int howSwedish(string)
//
// ABBA is a band, they have many songs including Fernando
// and Dancing Queen. ABBA is actually a Swedish band. If we
// wanted to find out howSwedish a std::string is, we could
// find out how many times the std::string contains the
// std::string "abba".  We want to look for this str::string
// in a case insensitive manner. So "abba" counts, and so
// does "aBbA". We also want to check for overlapping abba's
// such as in the std::string "abbAbba" that contains "abba" twice.
//
//  howSwedish("") returns 0
//  howSwedish("ABB") returns 0
//  howSwedish("AbBa") returns 1
//  howSwedish("AbBa a B b a") returns 1
//  howSwedish("!abbABba!") returns 2
//  howSwedish("abbAbba") returns 2
//
int howSwedish (std::string str) {

	if(str.length() <= 3){
		return 0;
	}

	bool firstA = false;
	bool firstB = false;
	bool secondB = false;
	int howSwed = 0;

        for(int i = 0; i < str.length(); i++){

                if((str[i] == 'a' || str[i] == 'A') && firstA == false){ //found first A so start counting
                        firstA = true;

                }else if((str[i] == 'a' || str[i] == 'A') && (firstB == false || secondB == false)){ //two a's next to eachother or not enough b's
                        firstA =true;

                }else if((str[i] == 'a' || str[i] == 'A') && firstB == true && secondB == true && firstA == true){//satifies all conditions
                        howSwed = 1 + howSwed;                                                                    //increment and reset all conditions
                        firstA = true;
                        firstB = false;
                        secondB = false;

                }else if((str[i] == 'B' || str[i] == 'b') && firstA == true && firstB == false){//found first b after a
                        firstB = true;

                }else if((str[i] == 'B' || str[i] == 'b') && firstA == true && firstB == true && secondB == false){//found second B
                        secondB = true;

                }else if(str[i] == 'B' || str[i] == 'b'){

                        if(secondB == true){ //found too many b's in between a's, reset all conditions
                                firstA = false;
                                firstB = false;
				secondB = false;
			}

		}else{
			//found no A's or B's, reset all conditions
			firstA = false;
			firstB = false;
			secondB = false;
		}//if else

	}//for loop


   return howSwed;
}


// 7) allAsLeft
//
// Given a String, return the same characters in the std::string in the same
// order except all upper case 'A's are to the left.
//
//  allAsLeft("") returns ""
//  allAsLeft("A") returns "A"
//  allAsLeft("G") returns "G"
//  allAsLeft("AB") returns "AB"
//  allAsLeft("BA") returns "AB"
//  allAsLeft("ABCaDEFGaA") returns "AABCaDEFGa";
//
std::string allAsLeft (std::string str) {

	//too short of a string so just return
	if(str.length() <= 1){
		return str;
	}

	std::string strA = "";
	std::string newStr = "";

	//get A's into strA
	for(int i = 0; i<str.length(); i++){

		//concatenate A to strA
		if(str[i] == 'A'){
			strA = strA + str[i];
		}

	}//for loop

	//add all other chars to newStr
	for(int j = 0; j<str.length(); j++){

		if(str[j] != 'A'){
			newStr = newStr + str[j];
		}

	}//for loop

	//return strA + newStr
	return strA + newStr;
}


// 8) isSorted
//
// Given a String, return true of the letters are in ascending order.
// Note:  'a' < 'b' and  '5' < '8'
//
//  isSorted("") returns true
//  isSorted("a") returns true
//  isSorted("abbcddef") returns true
//  isSorted("123456") returns true
//  isSorted("12321") returns false
//
bool isSorted (std::string str) {

	if(str.length() <= 1){
		return true;
	}

	for(int i = 0; i <str.length()-1; i++){

		if(str[i] > str[i+1]){
			return false;
		}

	}//for loop

    return true;
}


// 9) mirrorEnds
//
// Given a string, look for a mirror image (backwards) string at both the beginning
// and end of the given string. In other words, zero or more characters at the very
// beginning of the given string, and at the very end of the string in reverse order
// (possibly overlapping). For example, the string "abXYZba" has the mirror end "ab".
//
//  mirrorEnds("abXYZba") return "ab"
//  mirrorEnds("abca") returns "a"
//  mirrorEnds("aba") returns "aba"
//
std::string mirrorEnds (std::string str) {

	if(str.length() <= 1){
		return str;
	}

	std::string mirrorStr = "";
	int index2 = str.length()-1;

	for(int i = 0; i<(str.length()+1)/2; i++){

		if(i == index2){
			return str;
		} else if(str[i] == str[index2]){
			mirrorStr = mirrorStr + str[i];
		}else{
			return mirrorStr;
		}

		index2 = index2 - 1;
	}

    return mirrorStr;
}


// 10) starOut
//
// Return a version of the given string, where for every star (*) in the string
// the star and the chars immediately to its left and right are gone.
// So "ab*cd" yields "ad" and "ab**cd" also yields "ad".
//
//  starOut("ab*cd") returns "ad"
//  starOut("ab**cd") returns "ad"
//  starOut("sm*eilly") returns "silly"
//
std::string starOut (std::string str) {

	//check if string is shorter than 3
	if(str.length() <=2 ){

		//any * will return empty string
		for(int j = 0; j<str.length(); j++){

			if(str[j] == '*'){
				return "";
			}
		}

		//no * found then just return string
		return str;

	}//if statement

	//this part is for strings length 3 or longer
	std::string newStr = "";

	for(int i = 0; i<str.length(); i++){

		//as long as the current char is not * and there is no *
		// next the left and right of the char, then add it to the string
		if(i == 0 && str[i+1] != '*' && str[i] != '*'){ //edege case: start of string
			newStr = newStr + str[i];

		//edge case end of string
		}else if(i == str.length()-1 && str[i] != '*' && str[i-1] != '*'){
			newStr = newStr + str[i];

		//normal
		}else if(str[i] != '*' && str[i-1] != '*' && str[i+1] != '*'){
			newStr = newStr + str[i];
		}

	}//for loop

    return newStr;
}

#endif  // LOOPFUN_HPP_
