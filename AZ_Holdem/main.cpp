#include <iostream>
#include "AZ_Holdem.hpp"

int main(){

	int players;
	std::cout << "How many players will play? ";
	std::cin >> players;

	AZ_Holdem newGame(players);

	newGame.startGame();

	return 0;
}
