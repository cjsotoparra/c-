#include <string>
#include <vector>
#include <iostream>

template<typename T>
void shiftNTimes (std::vector<T> &vec, int &&numShifts) {

	auto n = numShifts%vec.size();

	std::vector<T> temp;

	for(auto index{0}; index < n; index++){
		temp.push_back(vec[index]);
	}

	auto temp2{0};

	for(auto itr = vec.begin()+n; itr != vec.end(); itr++){
		vec.at(temp2) = *itr;
		temp2+=1;
	}

	temp2 = vec.size() -n;

	for(auto itr = temp.begin(); itr != temp.end(); itr++){
		vec.at(temp2) = *itr;
		temp2+= 1;
	}
}

int range(std::vector<int> const&x){

        //check length first
        if(x.size() <=1){
                return 0;
        }

        //find max value first
        auto max{*x.begin()};

        for(auto itr : x){
                if(itr > max){
                        max = itr;
                }
        }

        //find min
        auto min{*x.begin()};

        for(auto itr : x){
                if(itr < min){
                        min = itr;
                }
        }

        //return range
        return max - min;
}

std::vector<std::string>
fizzBuzz (unsigned long &&start, unsigned long &&end) {

        std::vector<std::string> result;

        result.push_back(std::to_string(start));
        /*for(start; start<end-1; start++){

                if(start%3 ==0 && start%5 ==0){
                        result.push_back("FizzBuzz");
                }else if(start%3==0){
                        result.push_back("Fizz");
                }else if(start%5 == 0){
                        result.push_back("Buzz");
                }else{
                        result.push_back(std::to_string(start));
                }

        }*/

      return result;
}

int main(){

	std::vector<std::string> s1 = fizzBuzz(1,6);
	return 0;
}
