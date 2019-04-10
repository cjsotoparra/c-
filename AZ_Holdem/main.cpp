/*
 * main.cpp
 *
 * This program holds a AZ_Holdem.hpp file.  Within this class, it class
 * it's startGame() function which then runs a simulation of a game of Poker
 * between however many players the user wants to play with.  If the num of
 * players is less than one it then prints an error message.  Over than 22
 * and it also prints and error and exits.
 *
 * @Programmer: Christian Soto, 2019
*/


#include <iostream>
#include "AZ_Holdem.hpp"

int main(){

	int players;
	std::cout << "How many players will play? ";
	std::cin >> players;

	//error checking for the number of players playing
	if(players < 2){
		std::cout << "Error, can player with less than 1 player" << std::endl;
		return -1;
	}

	if(players > 22){
		std::cout << "Error, can't have more than 22 players" << std::endl;
		return -1;
	}

	//create AZ_Holdem object
	AZ_Holdem newGame(players);

	//start new game
	newGame.startGame();

	return 0;
}
