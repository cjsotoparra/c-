#include "GameOfLife.hpp"
#include <assert.h>
#include <vector>
#include <string>

int main(){

	GameOfLife world (5,9);

	world.growCellAt(0,5);
	world.growCellAt(4,4);
	world.growCellAt(4,6);
	world.growCellAt(1,0);
	world.growCellAt(2,0);
	world.growCellAt(3,0);
	world.growCellAt(0,8);
	world.growCellAt(2,8);
	world.growCellAt(3,8);
//	world.growCellAt(4,8);
	std::string worldStr = world.toString();

	std::cout << worldStr << std::endl;
	std::cout << "0,5: " << world.neighborCount(0,5) << std::endl;
        std::cout << "3,8: " << world.neighborCount(3,8) << std::endl;
  //      std::cout << "4,8: " << world.neighborCount(4,8) << std::endl;
	std::cout << "2,8: " << world.neighborCount(2,8) << std::endl;
	std::cout << "2,0: " << world.neighborCount(2,0) << std::endl;
	std::cout << "1,0: " << world.neighborCount(1,0) << std::endl;

	return 0;
}
