/*
 * PiggyBank.cpp
 *
 * Created on: Feb, 11, 2019
 * Author: Christian Soto
 */

#include "PiggyBank.h" //Get the class definitiion

PiggyBank::PiggyBank(){

	this->pennies = 0.0;
	this->dimes = 0.0;
	this->nickels = 0.0;
}

// An addPennies message adds the given number of pennies to this PiggyBank
// Precondition: penniesEntered >= 1
void PiggyBank::addPennies(int penniesEntered){

	//add the number of pennies
	for(auto i{0}; i < penniesEntered; i++){

		this->pennies+= .01;
	}

}//addPennies

// An addNickels message adds the given number of nickles to this PiggyBank
// Precondition: numberOfNickels >= 1
void PiggyBank::addNickels(int numberOfNickels){

	//add the number of nickels
	for(auto i{0}; i < numberOfNickels; i++){
		this->nickels += .05;
	}

}//addNickels


// An addSimes message adds the given number of dimes to this PiggyBank
// Precondition: numberOfDimes >= 1
void PiggyBank::addDimes(int numberOfDimes){

	//add the number of dimes
	for(auto i {0}; i < numberOfDimes; i++){
		this->dimes += .10;
	}

}//addDimes

// A getTotalCashInBank() message should return the total amount of
// cash in the bank. Pennies are $0.01, nickels are $0.05, and dimes
// are $0.10  (no quarters, halves, or dollar coins allowed to save time).
double PiggyBank::getTotalCashInBank(){

	return pennies + dimes + nickels;

}//getTotalCashInBank