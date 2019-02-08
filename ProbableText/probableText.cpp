#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstdlib>

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
}

std::unordered_map<std::string, std::vector<char> > createMap(std::string theText, int nGram){

	std::unordered_map<std::string, std::vector<char> > myMap;

	std::string key;
	for(auto index = 0; index < theText.length()-nGram; index++){

		key = theText.substr(index, nGram);

		if(myMap.count(key) == 0){
			myMap[key] = std::vector<char>();
			myMap[key].push_back(theText.at(index+nGram));
		}else{
			myMap[key].push_back(theText.at(index+nGram));
		}
	}

	return myMap;
}

std::string pickNGram(std::string theText, int nGram){

	srand((int) time(nullptr));

	int c = (rand() % (theText.length()-nGram)) + 1;

	return theText.substr(c, nGram);
}

/*void printNGram(std::unordered_map<std::string, std::vector<char> > myMap, int lettersToGen, std::string key){

	srand((int) time(nullptr));

	auto randIndex {0};
	int count {0};
	std::string word {""};

	for(auto i{0}; i < lettersToGen; i++){

		if(myMap.count(key) != 0){

			randIndex = (rand()%(myMap[key].size()-1)) + 1;
			word = key + myMap[key].at(randIndex);
			key = word.substr(1);
			count += word.length();

			if(count >= 60){
				std::cout << std::endl;
			}

			std::cout << word;
		}
	}
}*/

int main(){

	std::string myFile;
	int inGramLength;
	int lettersToGen;

	std::cout << "File name: ";
	std::cin >> myFile;

	myFile = myFile + ".txt";

	std::cout << "Enter ngram length: ";
	std::cin >> inGramLength;
	std::cout << "Letters to generate: ";
	std::cin >> lettersToGen;

	auto myBook {readFile(myFile)};
	auto myMap = createMap(myBook, inGramLength);

	srand((int) time(nullptr));

	auto key = pickNGram(myBook, inGramLength);
	auto randIndex {0};
        auto count {0};
        std::string word {""};

        for(auto i{0}; i< lettersToGen; i++){

                if(myMap.count(key) != 0){

                        randIndex = (rand()%(myMap[key].size()));
			word = myMap[key].at(randIndex);
                        key = key.substr(1) + word;
                        count += 1;

                        if(count >= 60 && word == " "){
                                std::cout << std::endl;
				count = 0;
                        }

                        std::cout << word;

		//key is not in our map
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
}
