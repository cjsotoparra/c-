/*
 * probableText.cpp
 *
 * probableText.cpp is program that takes three inputs from the user.
 * One input is the file from which the program is going to read,
 * another one is the inGramLength to help build the map and the last
 * input is the number of the characters to print out.
 *
 * Programmer Christian Soto, 2019
*/

/* Libraries needed */
#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstdlib>

/* 1) readFile
 *
 * This function takes a string as a parameter.  The string is the
 * name of the file that is going to be used to read from.  Once
 * it starts reading from the file, it builds one large string to
 * store all the characters.  Once it reaches the EOF, it returns
 * the large string.
 *
 * readFile(Alice.txt) returns theText
 */
std::string readFile(std::string file){

	//read file and assign it to a string
	std::ifstream inFile { file };
	std::string oneLine { "" };
	std::string theText { "" };

	//build string
	while(std::getline(inFile, oneLine)){
		theText = theText + oneLine;
	}

	return theText;
}//readFile

/* 2) createMap
 *
 * This function takes a string and inGramLength as parameters to build
 * unordered_map<string, vector<char>>. It goes throught the whole book
 * or string and builds a map of nGrams where each nGram maps to a
 * vector that contains all the characters that come after the nGram,
 * and then returns the unordered_map.
 *
 * createMap(theText, nGram) returns myMap
 */
std::unordered_map<std::string, std::vector<char> > createMap(std::string theText, int nGram){

	//create map and key varaibles to use
	std::unordered_map<std::string, std::vector<char> > myMap;
	std::string key;

	for(auto index = 0; index < theText.length()-nGram; index++){

		//build key
		key = theText.substr(index, nGram);

		//if no keys exists, create vector and add char to vector
		if(myMap.count(key) == 0){
			myMap[key] = std::vector<char>();
			myMap[key].push_back(theText.at(index+nGram));

		//else, add char to vector at key
		}else{
			myMap[key].push_back(theText.at(index+nGram));
		}//if else
	}//for loop

	return myMap;

}// createMap

/* 3) pickNGram
 *
 * This function takes a string and an nGram as parameters, and
 * uses the two parameters to select or generate an nGram from
 * the theText.
 *
 * pickNGram(theText, nGram) returns nGram
 */
std::string pickNGram(std::string theText, int nGram){

	//generate a random nGram to start
	srand((int) time(nullptr));

	int c = (rand() % (theText.length()-nGram)) + 1;

	return theText.substr(c, nGram);
}//pickNGram

/* 4) main
 *
 * This main function is the driver of the whole program.  It
 * starts by asking the user for three inputs and uses those
 * inputs.  It then uses the three functions above to print
 * the most likely character that after the nGram.
 *
 */
int main(){

	//varables to store from input
	std::string myFile;
	int inGramLength;
	int lettersToGen;

	//ask user for inputs and store inputs in varaibles
	std::cout << "File name: ";
	std::cin >> myFile;

	myFile = myFile + ".txt";

	std::cout << "Enter ngram length: ";
	std::cin >> inGramLength;
	std::cout << "Letters to generate: ";
	std::cin >> lettersToGen;

	//assign mybook and myMap the returns from functions
	auto myBook {readFile(myFile)};
	auto myMap = createMap(myBook, inGramLength);
	auto key = pickNGram(myBook, inGramLength);

	//this is needed to generate random variable
	srand((int) time(nullptr));

	//temp varibles needed to store random index, character, and
  	//a count to know where to add a newline
	auto randIndex {0};
        auto count {0};
        std::string word {""};

	//generate lettersToGen
        for(auto i{0}; i< lettersToGen; i++){

		//if key exits in the map, print a random char from vector
		//where nGram maps to it.
                if(myMap.count(key) != 0){

			//generate random index at myMap[key]
                        randIndex = (rand()%(myMap[key].size()));
			word = myMap[key].at(randIndex);

			//make new key with word
                        key = key.substr(1) + word;
                        count += 1;

			//make a newline if more than 60 words have been printed
			//and current word is whitespace
                        if(count >= 60 && word == " "){
                                std::cout << std::endl;
				count = 0;
                        }

                        std::cout << word;

		//key is not in our map, generate another key
                }else{

			key = pickNGram(myBook, inGramLength);
			randIndex = (rand()%(myMap[key].size()));
			word = myMap[key].at(randIndex);
			key = key.substr(1) + word;
			count += 1;

			if(count >= 60 && word == " "){
				std::cout<< std::endl;
				count = 0;
			}

			std::cout << word;
		}//if else

        }//for loop

	std::cout << std::endl;

	return 0;
}//main
