/*
 *
 * Dealer.hpp
 *
 * This file is a class that acts like a dealer.  It starts out with a deck
 * of cards.  It can shuffle the cards, and deal the cards to dealers.
 *
 *Programmer: Christian Soto, 2019
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

        /********************************
        *               Getters         *
        ********************************/
	vector<Card> getDeck() const{
		return this->deck;
	}

        /****************************************************************
        *  Method: shuffledeck                                          *
        *                                                               *
        *  Purpose: This function takes the deck of cards and randomly  *
        *           shuffles them.                                      *
        *                                                               *
        *  Parameters: none.                                            *
        *                                                               *
        *  PreConditions: a deck of cards                               *
        *                                                               *
        *  Returns: none.                                               *
        ****************************************************************/
	void shuffleDeck(){

		random_shuffle(this->deck.begin(), this->deck.end());
	}

        /****************************************************************
        *  Method: printDeck                                            *
        *                                                               *
        *  Purpose: This function prints the dealer's deck of cards. It *
        *           is mostly used for debugging purposes.              *
        *                                                               *
        *  Parameters: none.                                            *
        *                                                               *
        *  PreConditions: none.                                         *
        *                                                               *
        *  Returns: none.                                               *
        ****************************************************************/
	void printDeck(){

		for(auto i = 0; i < this->deck.size(); i++){

			cout << this->getDeck().at(i).toString() << " ";
		}

			cout << endl;
	}
};
#endif //Dealer.hpp
