/*
 * AZ_Holdem.hpp
 *
 * AZ_Holdem.hpp is program that runs a simulation of the game texas holdem.
 * In it's file, it holds three 2 classes header files, Dealer and Player.
 * The Dealer class is in charge of the deck and dealing cards to players.
 * The Player class is in charge of holding it's 2 cards and building the
 * the best hand from community cards.  AZ_Holdem, then takes all that
 * information and determines the winner.
 *
 * Programmer Christian Soto, 2019
*/

#include "Dealer.hpp"
#include "Player.hpp"
#include <iostream>

#ifndef	SRC_AZ_HOLDEM_HPP
#define	SRC_AZ_HOLDEM_HPP

class AZ_Holdem{
private:

	Dealer dealer;
	vector<Player> numOfPlayers;
	vector<Card> communityCards;
	int nameIsSet;
	float pot;
public:

	AZ_Holdem(int numberOfPlayers){

		vector<Player> vec (numberOfPlayers);
		numOfPlayers = vec;
		pot = 0;
		nameIsSet = 0;
	}

	void setNameIsSet(){
		this->nameIsSet = 1;
	}

	void dealCards(){

                auto index{0};

                //give 2 cards to player, bet, add to the pot, and set player names
                for(auto i{0}; i < this->numOfPlayers.size(); i++){

                        index = i;
                        this->numOfPlayers[i].push_card(dealer.getDeck().at(i));

			//check if players name are set already
			if(this->nameIsSet == 0){
				this->numOfPlayers[i].setName(i);
			}
                }

		//set the name set variable to true to indicate all players have names now
		this->nameIsSet = 1;

                for(auto i{0}; i < numOfPlayers.size(); i++){

                        index += 1;
                        this->numOfPlayers[i].push_card(dealer.getDeck().at(index));
                        this->numOfPlayers[i].bet(2);
			pot = pot + 2;
                }

	}//dealCards

	void setCommunityCards(){

		auto index = this->numOfPlayers.size() * 2;

		//add cards to community deck
		for(auto i{0}; i < 5; i++){

			this->communityCards.push_back(dealer.getDeck()[index]);
			index += 1;
		}

	}

	void printCommunityCards(){

		cout << "Community Cards: ";

                for(auto i{0}; i < 5; i++){

                        cout << this->communityCards[i].toString() << " ";
                }

                cout << endl;
        }


	void printPlayerCardsAndMoney(){

		for(auto i{0}; i< this->numOfPlayers.size(); i++){

			this->numOfPlayers[i].printName();
			cout << ": $";
			this->numOfPlayers[i].printMoney();
			cout << " - ";
			this->numOfPlayers[i].printCards();
			cout << "\tBest Hand: ";
			this->numOfPlayers[i].printBestHand();
			cout << endl;
			cout << endl;
		}

	}

	void allCardsInOne(){

		//combine community cards and all players cards
		for(auto i{0}; i < numOfPlayers.size(); i++){

			this->numOfPlayers[i].combineCards(this->communityCards);
		}
	}

	void printAllCards(){

		for(auto i{0}; i < numOfPlayers.size(); i++){

			this->numOfPlayers[i].printComCards();
		}
	}

	void printPlayersBestHand(){

		for(auto i{0}; i < this->numOfPlayers.size(); i++){

			this->numOfPlayers[i].printBestHand();
		}
	}

	void setAllPlayersBestHand(){

		for(auto i{0}; i < numOfPlayers.size(); i++){
			this->numOfPlayers[i].setBestHand();
		}
	}

	int findWinnerIndex(){

		int winnerIndex = 0;

		//sort the players by hand ranking
		sort(this->numOfPlayers.begin(), this->numOfPlayers.end());

		//iterate through the players
		for(auto i{0}; i < numOfPlayers.size()-1; i++){

			winnerIndex = winnerIndex + 1;

			// we know we have a tie if current index is not less than
			// the greatest hand at the end of the index
			if(!(numOfPlayers[i] < numOfPlayers[numOfPlayers.size()-1])){

				return i;
			}
		}

		//else we went throught the whole list, so only one winner
		return winnerIndex;
	}

	void printWinner(int winner){

		float numberOfWinners = 0;

		//check for tie
		if(winner != this->numOfPlayers.size()-1){

			cout << "Winning hands (tie)" << endl;
			cout << "+++++++++++++++++++++++++++++++++++++++++++++" << endl;

			//get number of winners
			numberOfWinners = numOfPlayers.size() - winner;

			//divide the pot between the winners
			this->pot = this->pot / numberOfWinners;

			//give winnings to players and print them out
			for(auto i = winner; i < this->numOfPlayers.size(); i++){

				this->numOfPlayers[i].addMoney(this->pot);
				this->numOfPlayers[i].printBestHand();
				cout << " ";
				this->numOfPlayers[i].printName();
				cout << " $";
				this->numOfPlayers[i].printMoney();
				cout << endl;
			}
		}else{

			cout << "Winner: ";
			//give winnings to winner and print
			this->numOfPlayers[winner].addMoney(this->pot);
			this->numOfPlayers[winner].printName();
			cout << " $";
			this->numOfPlayers[winner].printMoney();

			cout << endl;
			cout << "+++++++++++++++++++++++++++++++++++++++++++++" << endl;

			this->numOfPlayers[winner].printBestHand();
			cout << endl;
		}

		//empty pot
		this->pot = 0.0;
	}

	void clearGame(){

		//clear players cards, poker_hands, best_hand and comCards
		for(auto i{0}; i < numOfPlayers.size(); i++){

			this->numOfPlayers[i].clearPlayer();
		}

		//clear community cards
		this->communityCards.clear();
	}

	void startGame(){

		int winner;
		string choice {""};

		while(true){

			//dealer shuffle deck first
			dealer.shuffleDeck();

			this->dealCards();
			this->setCommunityCards();
			cout << endl;
			this->printCommunityCards();
			cout << "+++++++++++++++++++++++++++++++++++++++++++++" << endl;
			this->allCardsInOne();
			this->setAllPlayersBestHand();
			this->printPlayerCardsAndMoney();
			winner = this->findWinnerIndex();
			this->printWinner(winner);
			cout << endl;
			cout << "Play another game? <y or n> ";
			cin >> choice;

			this->clearGame();

			if(choice == "n"){
				break;
			}
		}
	}//startGame

};

#endif //AZ_Holdem.hpp
