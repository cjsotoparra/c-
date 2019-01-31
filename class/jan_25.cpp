#include <iostream>

int sum(std::initializer_list<int> list){

	int sum = 0;
	for(int next : list){
		sum+= next;
	}

	return sum;
}
int main(){

	auto str1 {"one"};
	auto str2 {"two"};

	
	std::cout << typeid(num1).name() << std::endl;
return 0;
}
