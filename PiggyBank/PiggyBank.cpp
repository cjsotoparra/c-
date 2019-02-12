#include "PiggyBank.h" //Get the class definitiion

PiggyBank::PiggyBank(){

	this->pennies = 0.0;
	this->dimes = 0.0;
	this->nickels = 0.0;
}

void PiggyBank::addPennies(int penniesEntered){

	for(auto i{0}; i < penniesEntered; i++){

		this->pennies+= .01;
	}
}

void PiggyBank::addNickels(int numberOfNickels){


	for(auto i{0}; i < numberOfNickels; i++){
		this->nickels += .05;
	}
}

void PiggyBank::addDimes(int numberOfDimes){

	for(auto i {0}; i < numberOfDimes; i++){
		this->dimes += .10;
	}
}

double PiggyBank::getTotalCashInBank(){
	return pennies + dimes + nickels;
}
