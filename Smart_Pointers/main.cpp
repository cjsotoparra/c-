#include <iostream>
#include <cstdio>
#include <string>
#include <memory>
using namespace std;

void aFunction(){
	unique_ptr <string> str { new string {"abc"}};

	cout << &str << endl;
	cout << str->length() << std::endl;
	std::cout << *str << std::endl;
}

int main(){


	aFunction();
	return 0;
}
