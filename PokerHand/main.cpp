#include "52Cards.hpp"
#include "PokerHand.hpp"
#include <iostream>
using namespace std;

int main(){

	PokerHand sF(C5, C6, C7, C9, C8);       //straight flush

        PokerHand lSF(H2, H4, HA, H3, H5); //wheel straight flush 

	cout << (lSF < sF) << endl;
	return 0;
}
