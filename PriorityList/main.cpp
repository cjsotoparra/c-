#include "LinkedPriorityList.cpp"
#include <iostream>
using namespace std;


int main(){

	LinkedPriorityList<int> list;

	list.insertElementAt(0, 2); //size is 1
	list.insertElementAt(0,3);
	list.insertElementAt(0,4);
	list.insertElementAt(1,1); //list = (4,1,3,2)
	cout << list.getElementAt(0) << endl;
	cout << list.getElementAt(1) << endl;;
	cout << list.getElementAt(2) << endl;
	cout << list.getElementAt(3) << endl << endl;

	list.removeElementAt(0);

	cout << list.getElementAt(0) << endl;
	cout << list.getElementAt(1) << endl;
	cout << list.getElementAt(2) << endl << endl;

//	list.removeElementAt(2);

//	cout << list.getElementAt(0) << endl;
//	cout << list.getElementAt(1) << endl << endl;

	list.lowerPriorityOf(0);

	cout << list.getElementAt(0) << endl;
	cout << list.getElementAt(1) << endl;
	cout << list.getElementAt(2) << endl << endl;

	list.lowerPriorityOf(1);

	cout << list.getElementAt(0) << endl;
        cout << list.getElementAt(1) << endl;
        cout << list.getElementAt(2) << endl << endl;

	list.lowerPriorityOf(2);

	cout << list.getElementAt(0) << endl;
        cout << list.getElementAt(1) << endl;
        cout << list.getElementAt(2) << endl << endl;

	list.raisePriorityOf(2);

	cout << list.getElementAt(0) << endl;
        cout << list.getElementAt(1) << endl;
        cout << list.getElementAt(2) << endl << endl;

	list.raisePriorityOf(1);

        cout << list.getElementAt(0) << endl;
        cout << list.getElementAt(1) << endl;
        cout << list.getElementAt(2) << endl << endl;

        list.raisePriorityOf(1);

        cout << list.getElementAt(0) << endl;
        cout << list.getElementAt(1) << endl;
        cout << list.getElementAt(2) << endl << endl;

	list.moveToLast(0);

	cout << list.getElementAt(0) << endl;
        cout << list.getElementAt(1) << endl;
        cout << list.getElementAt(2) << endl << endl;

        list.moveToLast(2);

        cout << list.getElementAt(0) << endl;
        cout << list.getElementAt(1) << endl;
        cout << list.getElementAt(2) << endl << endl;

	list.moveToTop(2);

	cout << list.getElementAt(0) << endl;
        cout << list.getElementAt(1) << endl;
        cout << list.getElementAt(2) << endl << endl;

        list.moveToTop(1);

        cout << list.getElementAt(0) << endl;
        cout << list.getElementAt(1) << endl;
        cout << list.getElementAt(2) << endl << endl;

        list.moveToTop(2);

        cout << list.getElementAt(0) << endl;
        cout << list.getElementAt(1) << endl;
        cout << list.getElementAt(2) << endl << endl;

	list.removeElementAt(0);
	list.removeElementAt(0);
	list.removeElementAt(0);

	list.getElementAt(0);
	return 0;
}
