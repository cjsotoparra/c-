// File name: OneFunction.cpp
// Programmer: Christian Soto, 2019
// This #define tells Catch to provide a main(). Only do this in one cpp file.
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

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
//  howSwedish("AbBa") returns 1
//  howSwedish("aBbAbBa") returns 2


//TODO 1: Write function howSwedish here
int howSwedish(std::string  str){

	int howSwed = 0;
	bool firstA = false;
	bool firstB = false;
	bool secondB = false;

	if(str.length() < 4){
		return 0;
	}

	for(int i = 0; i < str.length(); i++){

		if((str[i] == 'a' || str[i] == 'A') && firstA == false){ //found first A so start counting
			firstA = true;

		}else if((str[i] == 'a' || str[i] == 'A') && (firstB == false || secondB == false)){ //two a's next to eachother or not enough b's
			firstA =true;

		}else if((str[i] == 'a' || str[i] == 'A') && firstB == true && secondB == true && firstA == true){//satifies all conditions
			howSwed = 1 + howSwed;								 	  //increment and reset all conditions
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
			firstA = false;
			firstB = false;
			secondB = false;
		}//if else

	}//for loop

	return howSwed;
}

//TODO 2: Write a TEST_CASE for howSwedish that completely tests your function

TEST_CASE ("howSwed_length_3") {
     REQUIRE(0 == howSwedish("aba"));
}

TEST_CASE ("howSwed_no_length") {
     REQUIRE(0 == howSwedish(""));
}

TEST_CASE ("one_Swed") {
     REQUIRE(1 == howSwedish("abBa"));
}

TEST_CASE("Overlapping_abba"){
     REQUIRE(2 == howSwedish("aBbAbBa"));
}

TEST_CASE("2_abba"){
     REQUIRE(2 == howSwedish("aBbAabBa"));
}

TEST_CASE("no_abba"){
     REQUIRE(0 == howSwedish("aBbbBa"));
}

TEST_CASE("3_abba"){
     REQUIRE(3 == howSwedish("aBbAbBabba"));
}

TEST_CASE("more_3_abba"){
     REQUIRE(3 == howSwedish("aBbaAbBaabba"));
}

TEST_CASE("Some_TESTS"){
	REQUIRE(1 == howSwedish("AbBa a B b a"));
	REQUIRE(2 == howSwedish("!abbaABba!"));
	REQUIRE(2 == howSwedish("abbABba"));
}
