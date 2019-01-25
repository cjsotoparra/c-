// The template function indexOf(search, vector) returns
// the index of search in the vector if search is found.
// If search is not found, return -1 (see output below)
//
// Programmers: Rick Mercer and Christian Soto
//
#include <vector>
#include <string>
#include <iostream>
using namespace std;
// TODO: Implement indexOf here so the code in main
// compiles and the output shown in comments appear

template <typename T, typename U >
int indexOf(T a, U b){

	int result = -1;
	int i;

	for(i = 0; i < b.size(); i++){

		if(b[i] == a){
			return i;
		}

	}//for loop

	return result;

}//indexOf

int main () {
	vector <string> names2{ "Alex", "Brett", "Casey", "Devon", "Erin"};

	cout << indexOf<string>("Alex", names2) << "\n";     // 0
	cout << indexOf<string>("Casey", names2) << "\n";    // 2
	cout << indexOf<string>("Erin", names2) << "\n";     // 4
	cout << indexOf<string>("Not Here", names2) << "\n"; // -1
	cout << "\n";

	vector<int> nums{80, 99, 78, 86, 100, 65, 0};

	cout << indexOf<int>(80, nums) << "\n";    // 0
	cout << indexOf<int>(78, nums) << "\n";    // 2
	cout << indexOf<int>(100, nums) << "\n";   // 4
	cout << indexOf<int>(44, nums) << "\n";    // -1

	return 0;
}
