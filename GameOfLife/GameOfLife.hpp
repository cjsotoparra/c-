/*
 * GameOfLife.cpp
 *
 *  Created on: Feb 18, 2019
 *      Author: mercer and Christian Soto
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
    std::vector<unsigned long> cells;

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

	//store cell cordinates
        cells.push_back(row);
        cells.push_back(col);

	//else grow a cell at the location row and col
        theSociety[row][col] = true;
    }

    // Check to see if a cell is at the given location
    bool cellAt (unsigned long row, unsigned long col) const {

	//make cell alive
        return theSociety[row][col] == true;
    }

    // Returns the colony as one big string
    std::string toString () const {

	//empty string that will be built
	std::string myStr = "";

	//iterate through the 2d vector
	for(auto  row = 0; row < theSociety.size(); row++){
		for(auto col = 0; col <= theSociety[0].size(); col++){

			//if col is at the end, insert a newline char
			if(col != 0 && col % this->theSociety[0].size() == 0){

				if(row == theSociety.size()-1){
					break;
				}

				myStr += "\n";

			//if theSociety[row][col] is false, insert "." else "O"
			}else if(theSociety[row][col] == false){
				myStr += ".";
			}else{
				myStr+= "O";

			}//if else

		}//inner loop

	}//outer loop

        return myStr;

    }//toString

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

	auto count {0};

	//check left of row and col
	auto upRow = ((theSociety.size() + row) -1) % theSociety.size();
	auto downRow = ((theSociety.size() + row) + 1) % theSociety.size();
	auto leftCol = ((theSociety[0].size() + col) - 1) % theSociety[0].size();

	//left side
	if(theSociety[upRow][leftCol] == true){
		count += 1;
	}

	if(theSociety[row][leftCol] == true){
		count+= 1;
	}

	if(theSociety[downRow][leftCol] == true){
		count += 1;
	}

	//check middle of row and col
	if(theSociety[upRow][col] == true){
		count += 1;
	}

	if(theSociety[downRow][col] == true){
		count += 1;
	}

	//check right of row and col
	auto rightCol = ((theSociety[0].size() + col) + 1) % theSociety[0].size();

	if(theSociety[row][rightCol] == true){
		count += 1;
	}

	if(theSociety[upRow][rightCol] == true){
		count += 1;
	}

	if(theSociety[downRow][rightCol] == true){
		count += 1;
	}

	//return neighborCount
        return count;

    }//neighborCount

    // Change the state to the next society of cells
    void update () {

	//make row and col varaibles for new 2d vector
	unsigned long row = theSociety.size();
	unsigned long col = theSociety[0].size();

	//new 2d vector represents T = t + 1 or new time;
	std::vector<std::vector<bool>> t1(row, std::vector<bool> (col, false));

	//iterate through the matirx
        for(auto  row = 0; row < theSociety.size(); row++){
                for(auto col = 0; col < theSociety[0].size(); col++){

			//a cell is born  if 3 it has exactly three nieghbors
			if(neighborCount(row,col) == 3 && theSociety[row][col] == false){

				t1[row][col] = true;

			//a cell dies from isolation if it has less than 2 neighbors
			//or more dies from overcrowding if there are more than 3 neighbors
			} else if((neighborCount(row, col) < 2 || neighborCount(row, col) > 3) && theSociety[row][col] == true){

				t1[row][col] = false;

			//cell stays alive if there are at least 2 or 3 neighbors
			}else if(theSociety[row][col] == true && (neighborCount(row, col) == 2 || neighborCount(row, col) == 3)){

				t1[row][col] = true;
			}
		}//for loop 2

	}//for loop1

	//theSociety now equals t1 indicating time T-t+1 has passed
	theSociety = t1;

    }//update

};

#endif
