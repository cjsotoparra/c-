#include "GameOfLife.hpp"
#include <assert.h>
#include <vector>
#include <string>

int main(){

	GameOfLife world (100,100);

	world.growCellAt(0,0);
	world.growCellAt(100,100);
	std::string worldStr = world.toString();

	std::cout << worldStr << std::endl;

	return 0;
}
