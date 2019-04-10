/*
 *
 * Player.hpp
 *
 *The Player.hpp file is a class that holds Cards, community cards
 * and determines what their best hand is.  It then returns this information to
 * AZ_Holdem class.  Within this class, it holds a PokerHand.hpp class and
 * Card.cpp class.
 *
 * Programmer: Christian Soto, 2019
 *
 */

#ifndef SRC_PLAYER_HPP_
#define SRC_PLAYER_HPP

#include <vector>
#include <iostream>
#include <bits/stdc++.h>
#include "52Cards.hpp"
#include "PokerHand.hpp"
using namespace std;

class Player{
private:

	double player_money;
	vector<Card> player_cards;
	vector<Card> best_hand;
	vector<Card> comCards;
	vector<PokerHand> poker_cards;
	string player_name;
public:

	//Construtor
		Player(){

		player_money = 100.00;
	}

	/********************************
	*		Getters		*
	********************************/
	double getMoney() const{
		return this->player_money;
	}

	vector<Card> getCards() const{
                return this->player_cards;
        }

	vector<Card> getBestHand() const{
		return this->best_hand;
	}

	vector<Card> getComCards() const{
		return this->comCards;
	}

	vector<PokerHand> getPHand() const{
		return this->poker_cards;
	}

        /********************************
        *               setters         *
        ********************************/

	void setName(int i){
		i += 1;
		this->player_name = "Player " + to_string(i);
	}

	void setBestHand(){

		//build 21 possible hands
		PokerHand h(this->comCards[0], this->comCards[1], this->comCards[2], this->comCards[3], this->comCards[4]);
		PokerHand h2(this->comCards[5], this->comCards[0], this->comCards[1], this->comCards[2], this->comCards[3]);
		PokerHand h3(this->comCards[5], this->comCards[1], this->comCards[2], this->comCards[3], this->comCards[4]);
		PokerHand h4(this->comCards[5], this->comCards[0], this->comCards[2], this->comCards[3], this->comCards[4]);
                PokerHand h5(this->comCards[5], this->comCards[0], this->comCards[1], this->comCards[3], this->comCards[4]);
		PokerHand h6(this->comCards[5], this->comCards[0], this->comCards[1], this->comCards[2], this->comCards[4]);
                PokerHand h7(this->comCards[6], this->comCards[0], this->comCards[1], this->comCards[2], this->comCards[3]);
		PokerHand h8(this->comCards[6], this->comCards[1], this->comCards[2], this->comCards[3], this->comCards[4]);
                PokerHand h9(this->comCards[6], this->comCards[0], this->comCards[2], this->comCards[3], this->comCards[4]);
		PokerHand h10(this->comCards[6], this->comCards[0], this->comCards[1], this->comCards[3], this->comCards[4]);
                PokerHand h11(this->comCards[6], this->comCards[0], this->comCards[1], this->comCards[2], this->comCards[4]);
		PokerHand h12(this->comCards[6], this->comCards[5], this->comCards[1], this->comCards[2], this->comCards[3]);
                PokerHand h13(this->comCards[6], this->comCards[5], this->comCards[0], this->comCards[2], this->comCards[3]);
		PokerHand h14(this->comCards[6], this->comCards[5], this->comCards[0], this->comCards[1], this->comCards[3]);
                PokerHand h15(this->comCards[6], this->comCards[5], this->comCards[0], this->comCards[1], this->comCards[2]);
		PokerHand h16(this->comCards[6], this->comCards[5], this->comCards[0], this->comCards[1], this->comCards[4]);
                PokerHand h17(this->comCards[6], this->comCards[5], this->comCards[1], this->comCards[2], this->comCards[4]);
		PokerHand h18(this->comCards[6], this->comCards[5], this->comCards[0], this->comCards[2], this->comCards[4]);
                PokerHand h19(this->comCards[6], this->comCards[5], this->comCards[1], this->comCards[3], this->comCards[4]);
		PokerHand h20(this->comCards[6], this->comCards[5], this->comCards[0], this->comCards[3], this->comCards[4]);
                PokerHand h21(this->comCards[6], this->comCards[5], this->comCards[2], this->comCards[3], this->comCards[4]);

		//add all poker hands to vector
		poker_cards.push_back(h);
		poker_cards.push_back(h2);
                poker_cards.push_back(h3);
                poker_cards.push_back(h4);
                poker_cards.push_back(h5);
                poker_cards.push_back(h6);
                poker_cards.push_back(h7);
                poker_cards.push_back(h8);
                poker_cards.push_back(h9);
                poker_cards.push_back(h10);
                poker_cards.push_back(h11);
                poker_cards.push_back(h12);
                poker_cards.push_back(h13);
                poker_cards.push_back(h14);
                poker_cards.push_back(h15);
                poker_cards.push_back(h16);
                poker_cards.push_back(h17);
                poker_cards.push_back(h18);
                poker_cards.push_back(h19);
                poker_cards.push_back(h20);
                poker_cards.push_back(h21);

		//sort the vector
		sort(poker_cards.begin(), poker_cards.end());

		//the poker hand at the end is the best possible hand
		this->best_hand = poker_cards[20].getMyHand();
	}

        /****************************************************************
        *  Method: clearPlayer                                          *
        *                                                               *
        *  Purpose: This function clears the player's vectors to get 	*
        *           ready for the round of poker.                       *
        *                                                               *
        *  Parameters: none.	                                        *
        *                                                               *
        *  PreConditions: none.                 			*
        *                                                               *
        *  Returns: none.					        *
        ****************************************************************/
	void clearPlayer(){

		this->best_hand.clear();
		this->player_cards.clear();
		this->comCards.clear();
		this->poker_cards.clear();
	}

        /****************************************************************
        *  Method: operator<		                                *
        *                                                               *
        *  Purpose: This function overrides the operand less than to see*
        *           if another player poker hand is less.  This also    *
       	*	    helps with sorting the poker hands			*
	*                                                               *
        *  Parameters: Player 		                                *
        *                                                               *
        *  PreConditions: a sorted vector of a player's poker hand.     *
        *                                                               *
        *  Returns: true if this player's poker hand is less, else false*
        ****************************************************************/
	bool operator<( const Player &other) const{
		return this->poker_cards[20] < other.getPHand()[20];
	}

        /****************************************************************
        *  Method: addMoney	                                        *
        *                                                               *
        *  Purpose: This function is to add money to the player's money.*
        *                                                               *
        *  Parameters: double	                                        *
        *                                                               *
        *  PreConditions: none.			                        *
        *                                                               *
        *  Returns: none.				                *
        ****************************************************************/
	void addMoney(double money){
		this->player_money += money;
	}

        /****************************************************************
        *  Method: printMoney 	                                        *
        *                                                               *
        *  Purpose: This function prints the player's current money	*
        *           balance		                                *
        *                                                               *
        *  Parameters: none.	                                        *
        *                                                               *
        *  PreConditions: none.			  	                *
        *                                                               *
        *  Returns: none.					        *
        ****************************************************************/
	void printMoney(){
		cout << this->player_money;
	}

        /****************************************************************
        *  Method: printName	                                        *
        *                                                               *
        *  Purpose: This function prints the player's name.		*
        *                                                               *
        *  Parameters: none.	                                        *
        *                                                               *
        *  PreConditions: none.				                *
        *                                                               *
        *  Returns: none.					        *
        ****************************************************************/
	void printName(){
		cout << this->player_name;
	}

        /****************************************************************
        *  Method: bet		                                        *
        *                                                               *
        *  Purpose: This function takes money out of the player's money *
        *                                                               *
        *  Parameters: double	                                        *
        *                                                               *
        *  PreConditions: none.				                *
        *                                                               *
        *  Returns: none.					        *
        ****************************************************************/
	void bet(double money){
		this->player_money = this->player_money - money;
	}

        /****************************************************************
        *  Method: printCards                                           *
        *                                                               *
        *  Purpose: This function print's the players cards		*
        *                                                               *
        *  Parameters: none.                                            *
        *                                                               *
        *  PreConditions: none.                                         *
        *                                                               *
        *  Returns: none.                                               *
        ****************************************************************/
	void printCards(){

		for(auto i = 0; i < this->getCards().size(); i++){

			cout << this->getCards().at(i).toString() << " ";
		}

		cout << endl;
	}

        /****************************************************************
        *  Method: printBestHand                                        *
        *                                                               *
        *  Purpose: This function print's the players best poker hand   *
	*	    and hand rank					*
        *                                                               *
        *  Parameters: none.                                            *
        *                                                               *
        *  PreConditions: none.                                         *
        *                                                               *
        *  Returns: none.                                               *
        ****************************************************************/
	void printBestHand(){

                for(auto i = 0; i < this->getBestHand().size(); i++){

                        cout << this->getBestHand().at(i).toString() << " ";
                }

                cout << "\t";
                this->poker_cards[20].printHRank();

	}

        /****************************************************************
        *  Method: printComCards                                        *
        *                                                               *
        *  Purpose: This function print's the players community cards   *
        *                                                               *
        *  Parameters: none.                                            *
        *                                                               *
        *  PreConditions: none.                                         *
        *                                                               *
        *  Returns: none.                                               *
        ****************************************************************/
	void printComCards(){

		for(auto i{0}; i < this->comCards.size(); i++){

			cout << this->comCards[i].toString() << " ";
		}

		cout << endl;
	}

        /****************************************************************
        *  Method: push_card                                            *
        *                                                               *
        *  Purpose: This function puts cards into the player's card     *
	*	    vector.						*
        *                                                               *
        *  Parameters: Card                                             *
        *                                                               *
        *  PreConditions: none.                                         *
        *                                                               *
        *  Returns: none.                                               *
        ****************************************************************/
	void push_card(Card someCard){
		this->player_cards.push_back(someCard);
	}

        /****************************************************************
        *  Method: combineCards                                         *
        *                                                               *
        *  Purpose: This function puts all the community cards and the  *
        *	    player's cards into the same vector.		*
	*								*
        *  Parameters: vector<Card>                                     *
        *                                                               *
        *  PreConditions: none.                                         *
        *                                                               *
        *  Returns: none.                                               *
        ****************************************************************/
	void combineCards(vector<Card> b){

		//combine the community cards and player cards
		this->comCards.insert(comCards.begin(), b.begin(), b.end());
		this->comCards.push_back(this->player_cards[0]);
		this->comCards.push_back(this->player_cards[1]);

		//sort the vector
		sort(this->comCards.begin(), this->comCards.end());
	}
};

#endif //Player.hpp
