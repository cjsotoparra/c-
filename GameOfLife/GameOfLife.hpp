/*
 * GameOfLife.cpp
 *
 *  Created on: Feb 18, 2019
 *      Author: mercer
 *
 * This class models a society of cells growing according
 * to the rules of John Conway's Game of Life.
 *
 */
#ifndef GAMEOFLIFE_HPP_
#define GAMEOFLIFE_HPP_
#include <string>
#include <vector>
#include <iostream>
using namespace std;

// This class allows a society of cells to grow according
// to the rules from John Conway's Game of Life
class GameOfLife {

// --Data Member(s)
private:
    std::vector<std::vector<bool>> theSociety;

public:
    // Construct a board that is rows by cols size
    // with all elements set to false
    GameOfLife (unsigned long rows, unsigned long cols) {

	//make a 2d vector of size rows and cols
	std::vector<std::vector<bool> > s(rows, std::vector<bool> (cols, false));
	this->theSociety = s;
    }

    // Grow a cell at the given location
    void growCellAt (unsigned long row, unsigned long col) {

	//error check
	if(row < 0 || col < 0 || row >= theSociety.size() || col >= theSociety[0].size()){
		return;
	}

	//else grow a cell at the location row and col
        theSociety[row][col] = true;
    }

    // Check to see if a cell is at the given location
    bool cellAt (unsigned long row, unsigned long col) const {
        // TODO: Complete this method
        return theSociety[row][col] == true;
    }

    // Returns the colony as one big string
    std::string toString () const {
        // TODO: Complete this method

	std::string myStr;
	for(unsigned long  row = 0; row < theSociety.size(); row++){
		for(unsigned long col = 0; col <= theSociety[0].size(); col++){

			if(col != 0 && col % this->theSociety[0].size() == 0){

				if(row == theSociety.size()-1){
					break;
				}

				myStr += "\n";

			}else if(theSociety[row][col] == false){
				myStr += ".";
			}else{
				myStr+= "O";
			}
		}

	}
        return myStr;
    }

    // Count the neighbors around the given location.
    // Use wraparound. A cell in row 0 has neighbors in
    // the last row if a cell is in the same column, or
    // the column to the left or right. In this example,
    // cell 0,5 has two neighbors in the last row, cell 2,8
    // has four neighbors, cell 2,0 has four neighbors,
    // cell 1,0 has three neighbors. The cell at 3,8 has
    // 3 neighbors. The potential location for a cell at 4,8
    // would have three neighbors.
    //
    // .....O..O
    // O........
    // O.......O
    // O.......O
    // ....O.O..
    //
    // The return values should always be in the range of 0 through 8.
    // return the number of neighbors around any cell using wrap around.
    int neighborCount (int row, int col) const {
        // TODO: Complete this method
        return theSociety.size();
    }

    // Change the state to the next society of cells
    void update () {
        // TODO: Complete this method
    }

};

#endif
