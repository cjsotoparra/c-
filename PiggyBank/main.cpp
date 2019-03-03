#include "PiggyBank.h"
#include <iostream>
#include <assert.h>

int main(){

	PiggyBank anAcct{};

	anAcct.addNickels(6);
	anAcct.addPennies(3);
	anAcct.addDimes(4);

	std::cout << anAcct.getTotalCashInBank() <<std::endl;
//	assert(anAcct.getTotalCashInBank() == 0.73);
//	std::cout << anAcct.getTotalCashInBank() <<std::endl;

	anAcct.addDimes(3);
	std::cout << anAcct.getTotalCashInBank() << std::endl;
	return 0;
}
