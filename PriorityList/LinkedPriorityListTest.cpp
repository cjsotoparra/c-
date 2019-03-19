#include "catch.hpp"
#include "LinkedPriorityList.cpp"
using namespace std;

// The beginning of a Unit test for LinkedPriorityList
TEST_CASE ("testSizeAndIsEmptyWithInsertElementAt") {

	LinkedPriorityList<int> list;

	REQUIRE(list.isEmpty());

	list.insertElementAt(0, 55);
	REQUIRE(!list.isEmpty());
	list.insertElementAt(1, 77);
 	 REQUIRE(!list.isEmpty());
 	 REQUIRE(2 == list.size());
}

//--------------------------------------------------------

// Make sure all functions throw exceptions
// when they are supposed to!
TEST_CASE ("testInsertExceptUpperAndLower") { // index out of bounds
	LinkedPriorityList<string> list;
	//  index can only be 0. With 1, an exception must be thrown
	CHECK_THROWS( list.insertElementAt(1, "2nd") );
	CHECK_THROWS(list.insertElementAt(-1, "Neg"));

	list.insertElementAt(0, "1st");

	REQUIRE(!list.isEmpty());

	list.insertElementAt(0, "2nd");

	list.insertElementAt(2, "3rd");

	REQUIRE("2nd" == list.getElementAt(0));
}

