#include "PiggyBank.h"
#include <iostream>
#include <assert.h>

int main(){

	PiggyBank anAcct{};

	anAcct.addNickels(6);
	anAcct.addPennies(3);
	anAcct.addDimes(4);

	assert(anAcct.getTotalCashInBank() == .73);
	std::cout << anAcct.getTotalCashInBank() <<std::endl;
	return 0;
}
