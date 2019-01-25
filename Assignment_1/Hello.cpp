/* File: Hello.cpp
 * Programmer: Christian Soto, 2019
 * Note: Tells the difference between two departures of trains
	 in hours and minutes.  This is a simple program and does
	 not error check.  All imputs are military times.
*/

#include <iostream>
#include <cmath>

int main()
{
	//train variables
	int train1 = 0, train2 =0;
	std::cin >> train1 >> train2;

	//Get total minutes of train A and B
	int totalMA = (train1 / 100) * 60 + (train1 % 100);
	int totalMB = (train2 /100) * 60 + ( train2 % 100);

	//Output dialog
	std::cout << "Train A departs at: " << train1 << std::endl
		  << "Train B departs at: " << train2 << std::endl;

	std::cout << "Difference: " << (std::abs(train1 - train2)) / 100 << " hours"
		  << " and " << std::abs(totalMA - totalMB) % 60 << " minutes "
		  << std::endl;

	return 0;
}
