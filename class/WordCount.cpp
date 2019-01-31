/*
 * This program determines how often each string occurs in the vector.
 * Use a map<string, int> to store each unique word and how often it
 * exists in the vector. For example, there are 2 "woodchuck"s and 1 "if".
 *
 * Authors Rick Mercer and Christian Soto
 */

#include <iostream>  // cout endl
#include <vector>    // vector<T>
#include <map>       // map<Key, Value>

using namespace std;

// Store all unique words in a map as keys
// and how often each word was found in words.
map<string, int> wordMapping(const vector<string> &words) {

	map<string, int> mapWords;

	for(auto itr = words.begin(); itr!=words.end(); itr++){

		//if doesn't find it, insert it with value 1
		if(mapWords.count(*itr) == 0){
			mapWords.insert({*itr, 1});

		}else{
		//else, + 1 the value at *itr
			mapWords.at(*itr) +=1;
		}//if else

	}//for loop

	return mapWords;
}//wordMapping

int main() {

	vector<string> words { "how", "much", "wood", "could", "a", "woodchuck", "chuck",
                           "if", "a", "woodchuck", "could", "chuck", "wood" };

	map<string, int> result = wordMapping(words);

	cout.width(9);
	cout<<"word";
	cout.width(9); cout << "count\n";
	cout << "=========";
	cout.width(7); cout << "===\n";

	for(auto itr = result.begin(); itr!= result.end(); itr++){

		cout.width(9); cout << itr->first;
		cout.width(4); cout << itr->second << endl;
	}
}
