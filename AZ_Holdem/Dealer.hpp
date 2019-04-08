/*
 *
 * Dealer.hpp
 *
 *Programmer: Christian Soto, 2019
 *
 *
 */

#ifndef SRC_DEALER_HPP_
#define SRC_DEALER_HPP_

#include <vector>
#include <iostream>
#include <bits/stdc++.h>
#include "52Cards.hpp"
using namespace std;

class Dealer{
private:

	vector<Card> deck;

public:

	Dealer(){

		deck = {C2, C3, C4, C5, C6, C7, C8, C9, C10, CJ, CQ, CK, CA,
			D2, D3, D4, D5, D6, D7, D8, D9, D10, DJ, DQ, DK, DA,
			H2, H3, H4, H5, H6, H7, H8, H9, H10, HJ, HQ, HK, HA,
			S2, S3, S4, S5, S6, S7, S8, S9, S10, SJ, SQ, SK, SA};
	}

	vector<Card> getDeck() const{
		return this->deck;
	}

	void shuffleDeck(){

		random_shuffle(this->deck.begin(), this->deck.end());
	}

	void printDeck(){

		for(auto i = 0; i < this->deck.size(); i++){

			cout << this->getDeck().at(i).toString() << " ";
		}

			cout << endl;
	}

};
#endif //Dealer.hpp
