#include <vector>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;


int main(){


	vector<int> vec = {6,1,8,5,1,3,1,6};

	auto itr = find(vec.begin(), vec.end(), 6);


	// std::find function call 
	if (itr != vec.end()) {
        	std::cout << "Element " << 6 <<" found at position : " ; 
        	std:: cout << itr - vec.begin() + 1 << "\n" ; 
    	}else{
        	std::cout << "Element not found.\n\n";
	}
		cout << "a " << *vec.end() << endl;;
	return 0;
}
