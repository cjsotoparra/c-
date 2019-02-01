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

int main(){

	std::vector<std::string> v1{"c", "j", "s", "p"};
	shiftNTimes(v1, 2);
	return 0;
}
