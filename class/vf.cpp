#include <string>
#include <vector>
#include <iostream>

std::vector<int> frequency (std::vector<int> const &vec) {

	auto zero{0};
	auto one{0};
	auto two{0};
	auto three{0};
	auto four{0};
	auto five{0};
	auto six{0};
	auto seven{0};
	auto eight{0};
	auto nine{0};
	auto ten{0};

	for(auto itr : vec){

		if(itr == 0){
			zero+=1;
		}else if(itr == 1){
			one+= 1;
		}else if(itr == 2){
			two += 1;
		}else if(itr == 3){
			three += 1;
		}else if(itr == 4){
			four += 1;
		}else if(itr == 5){
			five += 1;
		}else if(itr == 6){
			six += 1;
		}else if(itr == 7){
			seven += 1;
		}else if(itr == 8){
			eight += 1;
		}else if(itr == 9){
			nine += 1;
		}else{
			ten += 1;
		}

	}//for loop

	auto result = {zero, one, two, three, four, five, six, seven, eight, nine, ten};

    return result;
}

int main(){

	std::vector<int> nums{1, 1, 1, 3, 3, 5, 6, 6, 10, 10, 10};
	std::vector<int> result = frequency(nums);
	return 0;
}
