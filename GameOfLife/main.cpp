#include "GameOfLife.hpp"
#include <assert.h>
#include <vector>
#include <string>

int main(){

	GameOfLife world (5,7);

	world.growCellAt(1,2);
	world.growCellAt(1,4);
	world.growCellAt(2,2);
	world.growCellAt(2,3);
	world.growCellAt(2,4);

	std::string worldStr = world.toString();

	std::cout << "T-0" << std::endl;
	std::cout << worldStr << std::endl;

	world.update();

	worldStr = world.toString();

	std::cout << "T-1" << std::endl;
	std::cout << worldStr << std::endl;

        world.update();

        worldStr = world.toString();

        std::cout << "T-2" << std::endl;
        std::cout << worldStr << std::endl;

        world.update();

        worldStr = world.toString();

        std::cout << "T-3" << std::endl;
        std::cout << worldStr << std::endl;

        world.update();

        worldStr = world.toString();

        std::cout << "T-4" << std::endl;
        std::cout << worldStr << std::endl;

	return 0;
}
