#include "GameOfLife.hpp"
#include <assert.h>
#include <vector>
#include <string>

int main(){

	GameOfLife world (5,9);

	world.growCellAt(0,0);
	world.growCellAt(100,100);
	std::string worldStr = world.toString();

	std::cout << worldStr << std::endl;
	std::cout << world.neighborCount(5,9);

	return 0;
}
