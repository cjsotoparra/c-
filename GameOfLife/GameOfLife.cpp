/*
 * GameOfLife.cpp
 *
 * Created on: Feb 20, 2019
 * Author: Christian Soto
 */

#include "GameOfLife.hpp" //Get class definitions
#include "catch.hpp"
using namespace std;

TEST_CASE("Wraparound UpperLeft"){

	GameOfLife g(8,9);
	g.growCellAt(0,0);
	g.growCellAt(0,1);
	g.growCellAt(1,0);
	g.growCellAt(1,1);

	REQUIRE(g.neighborCount(0,0) == 3);

	g.growCellAt(0,8);
	g.growCellAt(1,8);
	g.growCellAt(7,1);
	g.growCellAt(7,0);
	g.growCellAt(7,8);
	REQUIRE(g.neighborCount(0,0) == 8);
}

TEST_CASE("stablized_society"){

	GameOfLife g2(6,5);

	g2.growCellAt(2,2);
	g2.growCellAt(2,3);
	g2.growCellAt(2,4);

	g2.update();

	REQUIRE(true == g2.cellAt(1,3));
	REQUIRE(true == g2.cellAt(2,3));
	REQUIRE(true == g2.cellAt(3,3));
	REQUIRE(false == g2.cellAt(2,2));
	REQUIRE(false == g2.cellAt(2,4));

	g2.update();

	REQUIRE(false== g2.cellAt(1,3));
        REQUIRE(true == g2.cellAt(2,3));
        REQUIRE(false == g2.cellAt(3,3));
        REQUIRE(true == g2.cellAt(2,2));
        REQUIRE(true == g2.cellAt(2,4));
}


TEST_CASE("dies_off"){

	GameOfLife g3(6,5);

	g3.growCellAt(1,2);
	g3.growCellAt(1,4);
	g3.growCellAt(2,2);
	g3.growCellAt(2,3);
	g3.growCellAt(2,4);

	g3.update();

	REQUIRE(true == g3.cellAt(1,2));
	REQUIRE(true == g3.cellAt(1,4));
	REQUIRE(true == g3.cellAt(2,2));
	REQUIRE(true == g3.cellAt(2,4));
	REQUIRE(true == g3.cellAt(3,3));

	g3.update();

	REQUIRE(true == g3.cellAt(2,2));
	REQUIRE(true == g3.cellAt(2,4));
	REQUIRE(true == g3.cellAt(3,3));

	g3.update();

	REQUIRE(true == g3.cellAt(2,3));
	REQUIRE(true == g3.cellAt(3,3));

	g3.update();

	REQUIRE(false == g3.cellAt(2,3));
	REQUIRE(false == g3.cellAt(3,3));
}
