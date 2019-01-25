
/*
 * This file has 12 free functions related by the fact that
 * CSC 382 students are reviewing C, functions, and algorithmic
 * patterns such as Guarded Selection, Alternative Selection,
 * and Multiple Selection using C++. You will also be learning
 * std::string objects and messages that you probably did not
 * study in a C course.
 *
 * The functions will specifically use the if and if..else
 * statements written is virtually all languages because these
 * algorithmic patterns occur so frequently while developing software.
 *
 * @author Rick Mercer and Christian Soto
 */

#ifndef SELECTIONFUN_HPP_
#define SELECTIONFUN_HPP_

#include <string>
#include <iostream>

/////////////////////////////////////////////////////
// Some Calendar functions with primitive types

/*
 * In the US, Thanksgiving falls on the 4th Thursday of each November.
 *
 * Function thanksDate determines the day of the month that Thanksgiving falls on,
 *    no matter the day on which November begins.
 *
 * November can begin on ANY named day where 1 represents Monday, through 7 that represents Sunday.
 *
 * A valid call would be thanksDate(2) to indicate the first day of November is Tuesday.
 *
 * thanksDate should then return the day of the month upon which Thanksgiving falls,
 *    which is 24 (as shown in the calendar below).
 *
 * Arguments can only be 1 (for Monday) through 7 (for Sunday).
 *
 * If the argument is out of the range of 1 through 7, return -1.
 *
 * thanksDate(2) returns 24 // 1-Nov is Tue
 * thanksDate(5) returns 28 // 1-Nov is Fri
 * thanksDate(7) returns 26 // 1-Nov is Sun
 */
int thanksDate (int d) {

	switch(d){
		case 1:
			return 25;
		case 2:
			return 24;
		case 3:
			return 23;
		case 4:
			return 22;
		case 5:
			return 28;
		case 6:
			return 27;
		case 7:
			return 26;
		default:
			return -1;
	}
}

/*
 * Return the std::string "Monday" if the int argument
 * passed to the parameter dayNumber is 1.
 *   return "Unknown" if the argument is not 1 through 7
 *   return "Tuesday" if the argument 2
 *   And so on up through returning "Sunday" if argument == 7

 * dayOfWeek(0) returns "Unknown"
 * dayOfWeek(3) returns "Wednesday"
 * dayOfWeek(4) returns "Thursday"
 * dayOfWeek(6) returns "Saturday"
 * dayOfWeek(8) returns "Unknown"
 */
std::string dayOfWeek (int dayNumber) {

	switch(dayNumber){
		case 1:
			return "Monday";
		case 2:
			return "Tuesday";
		case 3:
			return "Wednesday";
		case 4:
			return "Thursday";
		case 5:
			return "Friday";
		case 6:
			return "Saturday";
		case 7:
			return "Sunday";
		default:
			return "Unknown";
	}
}


/*
 * Complete function daysInMonth to return the number of
 * days in a month for the given year. There are 30 days in
 * the months September, April, June, and November (or months
 * 9, 4, 6, and 11). All other months 1, 3, 5, 7, 8, 10,
 * and 12 (December) have 31 days.
 *
 * February has 28 days unless it is a leap year when it
 * has 29 (Google leap year definition. Assume the year is
 * always >= 1582, which is the first year in the Gregorian Calendar.
 *
 * Return -1 if month is not in the range of 1 through 12.
 * daysInMonth(1, 2020) returns 31
 * daysInMonth(2, 2019) returns 28
 * daysInMonth(2, 2000) returns 29
 * daysInMonth(2, 2100) returns 28 // 2100 is not a leap year.
 *
 */
int daysInMonth (int m, int year) {

	switch(m){
		case 9:
		case 4:
		case 6:
		case 11:
			return 30;
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			return 31;
		case 2:
			if(year%400 == 0){
				return 29;
			}else if(year%100 == 0){
				return 28;
			}else if(year%4 == 0){
        			return 29;
    			}else{
				return 28;
			}
		default:
			return -1;

	}//switch
}


/*
* You are given an integer for the month as on 1 for January
* and 12 is December. You are also given a bool argument.
* When the boolean argument is true, it means the month is
* happening in the northern hemisphere.
* Return the current season in that hemisphere using this table:
*
* month        inNorthernHemisphere   !inNorthernHemisphere
* ============ ====================   =====================
* 12, 1, or 2    "Winter"               "Summer"
*  3, 4, or 5    "Spring"               "Fall"
*  6, 7, or 8    "Summer"               "Winter"
* 9, 10, or 11   "Fall"                "Spring"
*/

std::string season (int month, bool inNorthernHemisphere) {

	if(inNorthernHemisphere){

		switch(month){
			case 12:
			case 1:
			case 2:
				return "Winter";
			case 3:
			case 4:
			case 5:
				return "Spring";
			case 6:
			case 7:
			case 8:
				return "Summer";
			default:
				return "Fall";
		}//switch 1
	}else{
			switch(month){
				case 12:
				case 1:
				case 2:
					return "Summer";
				case 3:
				case 4:
				case 5:
					return "Fall";
				case 6:
				case 7:
				case 8:
					return "Winter";
				default:
					return "Spring";
			}//switch 2
	}
}

bool isLeap(int year){

	if(year%400 == 0){
		return true;
	}else if(year%100 == 0){
		return false;
        }else if(year%4 == 0){
                return true;
        }else{
                return false;
        }

}

// Write free function validDate so it returns true if the
// std::string argument is a valid calendar date.
//
// The arguments always take the form of month, day, and year
//    as positive integers separated by / as in "mm/dd/yyyy".
//
// If the std::string argument does not express a proper date, return FALSE.
//
// Use static function std::stoi(std::string possibleInt)
//    that returns the integer value of the std::string argument
//    with the precondition that the std::string argument is a valid integer.

// Example of stoi:
// std::stoi("08") returns 8 and std::stoi("2021") returns 2021.
//
// Examples of valid function returns:
// validDate("01/31/2016") returns true
// validDate("12/31/2017") returns true
// validDate("06/15/2018") returns true
// validDate("02/28/2019") returns true
// validDate("02/29/2019") returns false
// validDate("2019/06/06") returns false
bool validDate (std::string const &date){

	int month = std::stoi(date.substr(0,2));
	int day = std::stoi(date.substr(3,5));
	int year = std::stoi(date.substr(6));

	if(month < 1 || month > 12){
		return false;
	}else if(day < 1 || day >31){
		return false;
	}else if(year < 1){
		return false;
	}else if(month == 9 || month == 4 || month == 6 || month == 11){

		if(day < 30){
			return true;
		}else{
			return false;
		}

	}else if(month == 2){

		if(isLeap(year) == false && day > 28){
			return false;
		}else if(isLeap(year) == true && day < 29){
			return true;
		}
	}else{
		return true;
	}

return true;
}

// Complete function dayNumber.
// Return how many days a valid date is into the year.
//
// If the std::string argument is not a value date, return -1.
//
// dayNumber("01/03/2016")returns 3
// dayNumber("12/31/2017")returns 365
// dayNumber("12/31/2020") returns 366
// dayNumber("13/11/2020") returns -1
int dayNumber (std::string const &date) {
	if(validDate(date) == false){
		return -1;
	}

	int month = std::stoi(date.substr(0,2));
	int day = std::stoi(date.substr(3,5));
	int year = std::stoi(date.substr(6));
	int dayNumber = 0;

	int i = 1;

	while(i != month){

		dayNumber = dayNumber + daysInMonth(month, year);
		std::cout << dayNumber << std::endl;
		i++;
	}

	dayNumber = dayNumber + day;

	return dayNumber;
}


/*
 * You are given 2 std::strings, a and b.
 * Return a std::string of the form short+long+short.
 * The shorter std::string is on the outside.
 * The longer std::string is on the inside.
 * The std::strings WILL not be the same length.
 * The std::strings MAY be empty (length 0).
 *
 * combo("Hello", "hi") returns "hiHellohi"
 * combo("hi", "Hello") returns "hiHellohi"
 * combo("aaa", "b")    returns "baaab"
 *
 * precondition: a.length() != b.length()
 */
std::string combo (std::string const &a, std::string const &b) {

	std::string newStr = "";
	if(a.length() > b.length()){
		newStr = b + a + b;
	}else {
		newStr = a + b + a;
	}

	return newStr;
}


/*
 * You are given two std::strings.
 * Append them together ("concatenation").
 * a is left most and b is rightmost.
 * b is appended to a.
 * Under the following condition, return the result.
 *
 * If the std::strings are different lengths,
 *    omit chars FROM THE FRONT of the longer std::string so
 *    it is the same length as the shorter std::string.
 *
 * So "Hello" and "Hi" yield "loHi".
 *
 * The std::strings may be any length.
 *
 * concatMin("Hello", "Hi") returns "loHi"
 * concatMin("Hello", "java") returns "ellojava"
 * concatMin("java", "Hello") returns "javaello"
 */
std::string concatMin (std::string const &a, std::string const &b) {

	std::string newStr = "";

	if(a.length() == b.length()){
		newStr.append(a);
		newStr.append(b);
		return newStr;
	}else if(a.length() > b.length()){
		int i = a.length() - b.length();
		newStr.append(a,i);
		newStr.append(b);
		return newStr;
	}else{
		int i = b.length() - a.length();
		newStr.append(a,i);
		newStr.append(b);
		return newStr;
	}
}

/*
 * You are given three std::string arguments.
 * Return the std::string that alphabetically precedes
 * OR is equal to the other two std::string arguments
 *
 * std::string("a", "b", "c") returns "a"
 * std::string("X", "b", "c") returns "X"
 * std::string("123", "1232", "123 0") returns "123"
 */
std::string firstOf3 (std::string const &a, std::string const &b,
          std::string const &c) {
    return "Under Construction";
}

/*
 * You are given a std::string str.
 * If the std::string STARTS WITH "f" return "Fizz".
 * If the std::string ENDS   WITH "b" return "Buzz".
 * If BOTH the "f" and "b" conditions are true, return "FizzBuzz".
 * If NEITHER the "f" and "b" conditions are true, return the std::string unchanged.
 *
 * fizzBuzz("fig") returns "Fizz"
 * fizzBuzz("dib") returns "Buzz"
 * fizzBuzz("fib") returns "FizzBuzz"
 */
std::string fizzBuzz (std::string const &str) {
    return "Under Construction";
}


#endif
