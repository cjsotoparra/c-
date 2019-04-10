/*
 * PokerHand.hpp
 *
 * This header files contains the implementation of creating a poker hand
 * and determining what the hand rank is based on the cards it has.
 * It also determine whether a hand is greater or less than another hand 
 * based on the rules of Traditional Poker.
 *
 * @Programmer: Christian Soto, 2019
*/

#ifndef SRC_POKERHAND_HPP_
#define SRC_POKERHAND_HPP_

#include <bits/stdc++.h>
#include <string>
#include <vector>
#include <iostream>
#include "../CLion/catch.hpp"
#include "52Cards.hpp"
using namespace std;

enum class HandRanking{
	HIGH_CARD = 1,
	ONE_PAIR = 2,
	TWO_PAIR = 3,
	THREE_OF_A_KIND = 4,
	STRAIGHT = 5,
	FLUSH = 6,
	FULL_HOUSE = 7,
	FOUR_OF_A_KIND = 8,
	STRAIGHT_FLUSH = 9,
	ROYAL_FLUSH = 10
};

class PokerHand{
private:

	//Private varibles
	HandRanking hRank;
	vector<Card> myHand;
public:
	//Constructor
	PokerHand(const Card &one, const Card &two, const Card &three, const Card &four, const Card &five){

		//put the four cards into the hand
		myHand.push_back(one);
		myHand.push_back(two);
		myHand.push_back(three);
		myHand.push_back(four);
		myHand.push_back(five);

		//sort for easy comparsion later
		sort(myHand.begin(), myHand.end());

		//all hands start with being a highCard
		hRank = setHand();
	}

	/****************************************
        *               Getters			*
        *****************************************/

        vector<Card> getMyHand() const{

                return this->myHand;
        }

        HandRanking getHandRank ()const{
                return this->hRank;
        }


	/****************************************************************
	*  Method: printHRank()						*
	*								*
	*  Purpose: This function prints the Rank of the hand		*
	*								*
	*  Parameters: none.						*
	*								*
	*  PreConditions: This method assumes the Hand ranking has been	*
	*		  set already.					*
	*								*
	*  Returns: none.						*
	****************************************************************/
	void printHRank(){

		if(this->getHandRank() == HandRanking::HIGH_CARD){

			cout << "High Card";

		}else if(this->getHandRank() == HandRanking::ONE_PAIR){

			cout << "One Pair";

		}else if(this->getHandRank() == HandRanking::TWO_PAIR){

			cout << "Two Pair";

		}else if(this->getHandRank() == HandRanking::THREE_OF_A_KIND){

			cout << "Three of a kind";

		}else if(this->getHandRank() == HandRanking::STRAIGHT){

			cout << "Straight";

		}else if(this->getHandRank() == HandRanking::FLUSH){

			cout << "Flush";

		}else if(this->getHandRank() == HandRanking::FULL_HOUSE){

			cout << "Full House";

		}else if(this->getHandRank() == HandRanking::FOUR_OF_A_KIND){

			cout << "Four of a kind";

		}else if(this->getHandRank() == HandRanking::STRAIGHT_FLUSH){

			cout << "Straight Flush";
		}else {

			cout << "Royal Flush";

		}
	}//printHRank

        /****************************************************************
        *  Method: isPair	                                        *
        *                                                               *
        *  Purpose: This function simple checks if there is pair in the *
	*	    hand by iterating.					*
        *                                                               *
        *  Parameters: vector<Card>                                     *
        *                                                               *
        *  PreConditions: a sorted vector of Type Cards			*
        *                 		                                *
	*  Returns: true if a pair is found or false if not		*
        ****************************************************************/
	bool isPair(const vector<Card> &myHand){

		for(auto i{0}; i < 4; i++){

			if(myHand.at(i).getValue() == myHand.at(i+1).getValue()){

				return true;
			}
		}

		return false;
	}//isPair

        /****************************************************************
        *  Method: is2Pair                                              *
        *                                                               *
        *  Purpose: This function checks if there are 2 pairs in the    *
        *           the hand by iterating.                              *
        *                                                               *
        *  Parameters: vector<Card>                                     *
        *                                                               *
        *  PreConditions: a sorted vector of Type Cards                 *
        *                                                               *
        *  Returns: true if 2 pairs are found or false if not           *
        ****************************************************************/
	bool is2Pair(const vector<Card> &myHand){

		auto pair{0};

		for(auto i{0}; i<4; i++){

			//check if two cards are the same
			if(myHand.at(i).getValue() == myHand.at(i+1).getValue()){

				//incrment pair
				pair += 1;

				//found two pair
				if(pair == 2){
					return true;
				}
			}
		}

		//return false if pair is <2
		return false;
	}//is2Pair

        /****************************************************************
        *  Method: isThreeOfAKind                                       *
        *                                                               *
        *  Purpose: This function checks if there are 3 of a kind in the*
        *           the hand by iterating.                              *
        *                                                               *
        *  Parameters: vector<Card>                                     *
        *                                                               *
        *  PreConditions: a sorted vector of Type Cards                 *
        *                                                               *
        *  Returns: true if 3 cards are the same or false if no         *
        ****************************************************************/
	bool isThreeOfAKind(const vector<Card> &myHand){

		for(auto i{0}; i< 3; i++){

			if(myHand.at(i).getValue() == myHand.at(i+1).getValue() && myHand.at(i).getValue() == myHand.at(i+2).getValue()){

				return true;
			}

		}
		return false;
	}//isThreeOfAKind

        /****************************************************************
        *  Method: isStraght                                            *
        *                                                               *
        *  Purpose: This function checks if the current hand is a	*
        *           straight.  It also checks for low ACE, High ACE and *
	*	    regular straight.					*
        *                                                               *
        *  Parameters: vector<Card>                                     *
        *                                                               *
        *  PreConditions: a sorted vector of Type Cards                 *
        *                                                               *
        *  Returns: true if it goes throught the vector, else false     *
        ****************************************************************/
        bool isStraight(const vector<Card> &myHand){

                //check high ace
		if(myHand.at(0).getValue() == 10){

			for(auto i{0}; i < 4; i++){

				//check if the cards match the last card
				if(myHand.at(i).getValue() != myHand.at(i+1).getValue()-1){
					return false;
				}
			}

			return true;
		//check low ace
		}else if(myHand.at(4).getValue() == 14){

			//there is an ace at the end

			//check to see if the first card starts with 2
			if(myHand.at(0).getValue() != 2){
				return false;
			}


			for(auto i{0}; i <3; i++){

				//check the sequence
				if(myHand.at(i).getValue() != myHand.at(i+1).getValue()-1){

					return false;
				}
			}

			return true;

		//check regular straght
		}else{

			for(auto i{0}; i< 4; i++){

				if(myHand.at(i).getValue() != myHand.at(i+1).getValue()-1){

					return false;
				}

			}

			return true;
		}
        }//isStraight

        /****************************************************************
        *  Method: isFlush                                              *
        *                                                               *
        *  Purpose: This function checks if the cards have the same	*
        *           suit.		                                *
        *                                                               *
        *  Parameters: vector<Card>                                     *
        *                                                               *
        *  PreConditions: a sorted vector of Type Cards                 *
        *                                                               *
        *  Returns: true if it makes through the vector, else false     *
        ****************************************************************/
	bool isFlush(const vector<Card> &myHand){

		//go through the whole hand and check the suits
		for(auto i{0}; i<4; i++){

			if(myHand.at(i).getSuit() != myHand.at(i+1).getSuit()){
				return false;
			}
		}

		return true;
	}//isFlush

        /****************************************************************
        *  Method: isPair                                               *
        *                                                               *
        *  Purpose: This function checks if there are 2 pairs in the    *
        *           the hand by iterating.                              *
        *                                                               *
        *  Parameters: vector<Card>                                     *
        *                                                               *
        *  PreConditions: a sorted vector of Type Cards                 *
        *                                                               *
        *  Returns: true if 2 pairs are found or false if not           *
        ****************************************************************/
	bool isFullHouse(const vector<Card> &myHand){

		auto index{0};

		//find the first 3 cards, and update index
		for(auto i{0}; i<3; i++){
			index = i;

			if((myHand.at(i).getValue() != myHand.at(i+1).getValue()) && i == 0){
				return false;
			}

			if((myHand.at(i).getValue() != myHand.at(i+1).getValue()) && i != 0){

				break;
			}
		}

		//check the rest of the cards
		for(auto i = index+1; i< 4; i++){

			if(myHand.at(i).getValue() != myHand.at(i+1).getValue()){
				return false;
			}
		}

		//we know we have a full house if all conditions pass
		return true;
	}

        /****************************************************************
        *  Method: isStraightFlush                                      *
        *                                                               *
        *  Purpose: This function checks if the hand is a straight flush*
        *           by calling the two functions isStraight and isFlush.*
        *                                                               *
        *  Parameters: vector<Card>                                     *
        *                                                               *
        *  PreConditions: a sorted vector of Type Cards                 *
        *                                                               *
        *  Returns: true if both if statements pass, else false         *
        ****************************************************************/
	bool isStraightFlush(const vector<Card> &myHand){

		//check to see if it is a flush
		if(!isFlush(myHand)){
			return false;
		}

		//check to see if it is a straight
		if(!isStraight(myHand)){
			return false;
		}

		//we know that we have a striaght flush,
		return true;
	}

        /****************************************************************
        *  Method: isFourOfAKind                                        *
        *                                                               *
        *  Purpose: This function checks if there are 4 cards that are  *
        *           the same in the vector.                             *
        *                                                               *
        *  Parameters: vector<Card>                                     *
        *                                                               *
        *  PreConditions: a sorted vector of Type Cards                 *
        *                                                               *
        *  Returns: true if 4 are found to be the same, else false      *
        ****************************************************************/
	bool isFourOfAKind(const vector<Card> &myHand){

		for(auto i{0}; i<2; i++){

			if(myHand.at(i).getValue() == myHand.at(i+1).getValue()
				&& myHand.at(i).getValue() == myHand.at(i+2).getValue()
				&& myHand.at(i).getValue() == myHand.at(i+3).getValue()){
				return true;
			}
		}

		return false;
	}

        /****************************************************************
        *  Method: findKicker                                           *
        *                                                               *
        *  Purpose: This function is a helper function that finds the   *
        *           kicker in the vector for 2 pairs cards.             *
        *                                                               *
        *  Parameters: vector<Card>                                     *
        *                                                               *
        *  PreConditions: a sorted vector of Type Cards                 *
        *                                                               *
        *  Returns: The index of where the kicker card is.	        *
        ****************************************************************/
	int findKicker(vector<Card> aHand) const{

		if(aHand.at(0).getValue() != aHand.at(1).getValue()){

			return 0;
		}else if(aHand.at(2).getValue() != aHand.at(3).getValue()){
			return 2;
		}else {
			return 4;
		}
	}//findKicker

        /****************************************************************
        *  Method: findHKicker                                          *
        *                                                               *
        *  Purpose: This function finds the high kicker card in a hand  *
        *                                                               *
        *  Parameters: vector<Card>                                     *
        *                                                               *
        *  PreConditions: a sorted vector of Type Cards                 *
        *                                                               *
        *  Returns: The index of where the high kicker is.	        *
        ****************************************************************/
	int findHKicker(int index) const{

		if(index == 3){
			return 2;
		}else {
			return 4;
		}
	}

        /****************************************************************
        *  Method: findMKicker                                          *
        *                                                               *
        *  Purpose: This function finds the mid kicker card in a hand   *
        *                                                               *
        *  Parameters: vector<Card>                                     *
        *                                                               *
        *  PreConditions: a sorted vector of Type Cards                 *
        *                                                               *
        *  Returns: The index of where the mid card kicker is.          *
        ****************************************************************/
        int findMKicker(int index) const{

                if(index >= 2){
                        return 1;
                }else {
                        return 3;
                }
        }

        /****************************************************************
        *  Method: findLKicker                                          *
        *                                                               *
        *  Purpose: This function finds the low kicker card in a hand   *
        *                                                               *
        *  Parameters: vector<Card>                                     *
        *                                                               *
        *  PreConditions: a sorted vector of Type Cards                 *
        *                                                               *
        *  Returns: The index of where the low kicker card  is.         *
        ****************************************************************/
        int findLKicker(int index) const{

                if(index >= 1){
                        return 0;
                }else {
                        return 2;
                }
        }

        /****************************************************************
        *  Method: indexOfPair                                          *
        *                                                               *
        *  Purpose: This function finds the index of where the pair of  *
	*	    cards begin.					*
        *                                                               *
        *  Parameters: vector<Card>                                     *
        *                                                               *
        *  PreConditions: a sorted vector of Type Cards                 *
        *                                                               *
        *  Returns: The index of where the high kicker is.              *
        ****************************************************************/
	int indexOfPair(vector<Card> aHand) const{

		for(auto i{0}; i<4; i++){

			//we found where our pair begins
			if(aHand.at(i).getValue() == aHand.at(i+1).getValue()){

				return i;
			}
		}
	}

	/****************************************
        *               Setters                 *
        *****************************************/
	 HandRanking setHand(){

		//set the what kind of hand it is, start with the highest
		if(isStraightFlush(this->myHand)){

			//check royal flush
			if(this->myHand.at(0).getValue() == 10){
				return HandRanking::ROYAL_FLUSH;
			}else{
				return HandRanking::STRAIGHT_FLUSH;
			}

		//check four of a kind
		}else if(isFourOfAKind(this->myHand)){
			return HandRanking::FOUR_OF_A_KIND;

		//check full_house
		}else if(isFullHouse(this->myHand)){
			return HandRanking::FULL_HOUSE;

		//check flush
		}else if(isFlush(this->myHand)){
			return HandRanking::FLUSH;

		//check straight
		}else if(isStraight(this->myHand)){

			return HandRanking::STRAIGHT;
		}else if(isThreeOfAKind(this->myHand)){
			return HandRanking::THREE_OF_A_KIND;

		//check 2 pair
		}else if(is2Pair(this->myHand)){
			return HandRanking::TWO_PAIR;

		//check one pair
		}else if(isPair(this->myHand)){
			return HandRanking::ONE_PAIR;

		//else if there is nothing, then it's just a high card
		}else{
			return HandRanking::HIGH_CARD;
		}
	}//setHandRanking

        /****************************************************************
        *  Method: operator<	                                        *
        *                                                               *
        *  Purpose: This function overloads the operator < to know      *
        *           which pokerhand is less and to help with sorting in *
	*	    other classes.					*
	*								*
        *  Parameters: vector<Card>                                     *
        *                                                               *
        *  PreConditions: a sorted vector of Type Cards                 *
        *                                                               *
        *  Returns: The index of where the high kicker is.              *
        ****************************************************************/
	bool operator<( const PokerHand &other) const{


		//see if they are equal first
		if(getHandRank() == other.getHandRank()){

			//only tie that can't be broken is Royal Flush
			if(getHandRank() == HandRanking::ROYAL_FLUSH){

				return false;

			}else if(getHandRank() == HandRanking::STRAIGHT_FLUSH){

                                //check tie
                                if(getMyHand().at(0).getValue() == other.getMyHand().at(0).getValue()
                                        && getMyHand().at(4).getValue() == other.getMyHand().at(4).getValue()){
                                        return false;
                                }

                                //check to see if we have a low ace straight flush
                                if(getMyHand().at(0).getValue() == 2 && getMyHand().at(4).getValue() == 14){
                                        return true;
                                } else if(other.getMyHand().at(0).getValue() == 2 && other.getMyHand().at(4).getValue() == 14){
                                        return false;
                                } else{

                                        for(auto i{4}; i>= 0; i--){

                                                //walk backwards and compare cards
                                                if(getMyHand().at(i).getValue() != other.getMyHand().at(i).getValue()){

                                                        return getMyHand().at(i).getValue() < other.getMyHand().at(i).getValue();
                                                }
                                        }

                                        return false;
				}

			}else if(getHandRank() == HandRanking::FOUR_OF_A_KIND){

				//compare their 4 of a kind cards if they are
				//not equal, else, check their kicker
				if(getMyHand().at(2).getValue() == other.getMyHand().at(2).getValue()){

					//check kickers, should be at index 0 or 4
					if(getMyHand().at(0).getValue() == other.getMyHand().at(0).getValue()){
						return getMyHand().at(4).getValue() < other.getMyHand().at(4).getValue();
					}else{
						return getMyHand().at(0).getValue() < other.getMyHand().at(0).getValue();
					}//kicker check

				}else{

					//check the four of a kind cards at the middle
					return getMyHand().at(2).getValue() < other.getMyHand().at(2).getValue();

				}

			//check full house values
			}else if(getHandRank() == HandRanking::FULL_HOUSE){

				//check the middle card and
				//if its still equal, check last and first index
				if(getMyHand().at(2).getValue() == other.getMyHand().at(2).getValue()){

					//check both index 0 or 4
					if(getMyHand().at(0).getValue() == other.getMyHand().at(0).getValue()){

						return getMyHand().at(4).getValue() < other.getMyHand().at(4).getValue();
					} else{
						return getMyHand().at(0).getValue() < other.getMyHand().at(0).getValue();
					}
				} else{

					return getMyHand().at(2).getValue() < other.getMyHand().at(2).getValue();

				}

			//check flush
			}else if(getHandRank() == HandRanking::FLUSH){


				//for loop to until we find a card that is not equal
				for(auto i{0}; i<5; i++){

					//no more cards to check
					if(i == 4){

						return getMyHand().at(i).getValue() < other.getMyHand().at(i).getValue();
					}

					//if not equal then just check the values
					if(getMyHand().at(i).getValue() != other.getMyHand().at(i).getValue()){

						return getMyHand().at(i).getValue() < other.getMyHand().at(i).getValue();
					}
				}//for loop

			//check straight
			}else if(getHandRank() == HandRanking::STRAIGHT){

				//check tie
				if(getMyHand().at(0).getValue() == other.getMyHand().at(0).getValue()
					&& getMyHand().at(4).getValue() == other.getMyHand().at(4).getValue()){
					return false;
				}

				//check to see if we have a low ace straight
				if(getMyHand().at(0).getValue() == 2 && getMyHand().at(4).getValue() == 14){

					return true;
				} else if(other.getMyHand().at(0).getValue() == 2 && other.getMyHand().at(4).getValue() == 14){
					return false;

				} else{

					for(auto i{4}; i>= 0; i--){

						//walk backwards and compare cards
						if(getMyHand().at(i).getValue() != other.getMyHand().at(i).getValue()){

							return getMyHand().at(i).getValue() < other.getMyHand().at(i).getValue();
						}
					}

					return false;
				}

			//check three of a kind
			}else if(getHandRank() == HandRanking::THREE_OF_A_KIND){

				//check the highest middle card,
				//if still, tie, check highest or 2nd highest card
				if(getMyHand().at(2).getValue() == other.getMyHand().at(2).getValue()){

					//still tied, get for loop until there is a different 
					//card or jsut return false

					for(auto i{4}; i>=0; i--){

						//if at the beginging, then return false
						if(i == 0){
							return getMyHand().at(i).getValue() < other.getMyHand().at(i).getValue();
						}

						//look until cards are different
						if(getMyHand().at(i).getValue() != other.getMyHand().at(i).getValue()){

							return getMyHand().at(i).getValue() < other.getMyHand().at(i).getValue();
						}
					}//for loop
				}else{

					return getMyHand().at(2).getValue() < other.getMyHand().at(2).getValue();

				}

			//check two pair
			}else if(getHandRank() == HandRanking::TWO_PAIR){

				//High value pair always at index 3
				if(getMyHand().at(3).getValue() != other.getMyHand().at(3).getValue()){

					return getMyHand().at(3).getValue() < other.getMyHand().at(3).getValue();
				}else{

					//check low value pair, at index 1
					if(getMyHand().at(1).getValue() != other.getMyHand().at(1).getValue()){

						return getMyHand().at(1).getValue() < other.getMyHand().at(1).getValue();
					} else{

						//else compare kickers
						auto kicker1 = findKicker(getMyHand());
						auto kicker2 = findKicker(other.getMyHand());

						return getMyHand().at(kicker1).getValue() < other.getMyHand().at(kicker2).getValue();
					}//check kicker and low pair
				}//check high pair

			//check pair
			}else if(getHandRank() == HandRanking::ONE_PAIR){


				auto index1 = indexOfPair(getMyHand());
				auto index2 = indexOfPair(other.getMyHand());

				if(getMyHand().at(index1).getValue() != other.getMyHand().at(index2).getValue()){

					//not equal, just compare
					return getMyHand().at(index1).getValue() < other.getMyHand().at(index2).getValue();
				}else{

					//start checking their kicker cards
					auto hKick = findHKicker(index1);
					auto hKick2 = findHKicker(index2);

					if(getMyHand().at(hKick).getValue() != other.getMyHand().at(hKick2).getValue()){

						return getMyHand().at(hKick).getValue() < other.getMyHand().at(hKick2).getValue();
					}

					//medium kicker
                                        auto mKick = findMKicker(index1);
                                        auto mKick2 = findMKicker(index2);

                                        if(getMyHand().at(mKick).getValue() != other.getMyHand().at(mKick2).getValue()){

                                                return getMyHand().at(mKick).getValue() < other.getMyHand().at(mKick2).getValue();
                                        }

                                        //start checking their kicker cards
                                        auto lKick = findLKicker(index1);
                                        auto lKick2 = findLKicker(index2);

                                        if(getMyHand().at(lKick).getValue() != other.getMyHand().at(lKick2).getValue()){

                                                return getMyHand().at(lKick).getValue() < other.getMyHand().at(lKick2).getValue();
                                        }

                                        //still tied, so just return false
					return false;


				}//One pair

			}else{

				//no hand Ranking, so just iterate through their high cards
				for(auto i{4}; i >= 0; i--){

					//not equal, then compare
					if(getMyHand().at(i).getValue() != other.getMyHand().at(i).getValue()){
						return getMyHand().at(i).getValue() < other.getMyHand().at(i).getValue();
					}
				}

				//same cards
				return false;

			}//Hand Ranking if else when tied

		}//original if else


		//not equal, so just check hand ranking
		return getHandRank() < other.getHandRank();
	}

};

#endif //POKERHAND_HPP_
