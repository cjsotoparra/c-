#include "52Cards.hpp"
#include "PokerHand.hpp"
#include <iostream>
using namespace std;

int main(){

	PokerHand fullHouse(CA, DA, C3, D3, H3); /* NOLINT */
	PokerHand fullHouse2(C2, D2, C4, D4, H4);/* NOLINT */
	PokerHand fullHouse3(HK, DK, SK, CA, HA);/* NOLINT */
	PokerHand fullHouseLow(C2, D2, H2, C3, H3);/* NOLINT */
	PokerHand fullHouseHigh(CA, DA, HA, CK, HK);/* NOLINT */

	cout << (fullHouse2 < fullHouse3) << endl;

	cout << 9/3(5-2) << endl;
	return 0;
}
