/* File: main.cpp
 * Programmer: Christian Soto, 2019
 * Note:  Use Grid object class to escape from the Grid
 *        using abstraction methods only.
 */


#include "Grid.hpp"
#include <iostream>

int main()
{

	Grid grid (10,10);

	while(grid.frontIsClear()){
		grid.move();
	}

	if(grid.row()==0 || grid.row() == grid.nRows()-1 || grid.column() == 0 || grid.column() == grid.nColumns()-1){
		grid.display();
		return 0;
	}

	if(!grid.rightIsClear()){
		grid.turnLeft();
	}else{
		while(grid.rightIsClear()){
			grid.turnRight();
		}
	}

	if(grid.row()==0 || grid.row() == grid.nRows()-1 || grid.column() == 0 || grid.column() == grid.nColumns()-1){
                grid.display();
                return 0;
        }


	while(grid.frontIsClear() && !grid.rightIsClear()){
		grid.move();

		if(grid.row()==0 || grid.row() == grid.nRows()-1 || grid.column() == 0 || grid.column() == grid.nColumns()-1){
                	grid.display();
        	        return 0;
	        }

		if(!grid.frontIsClear() && !grid.rightIsClear()){
                                grid.turnLeft();
                }

	}

	if(grid.row()==0 || grid.row() == grid.nRows()-1 || grid.column() == 0 || grid.column() == grid.nColumns()-1){
                        grid.display();
                        return 0;
        }

	grid.turnRight();
	grid.move();
	grid.display();


	return 0;
}
