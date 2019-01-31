#include <string>
#include <vector>
#include <iostream>
using namespace std;

template<typename T>
void sortOfSort(std::vector<T> &vec){

        if(*vec.begin() > *(vec.end()-1)){
		auto temp = *vec.begin();
                *vec.begin() = *(vec.end()-1);
                *(vec.end()-1) = temp;
        }

	auto small{*vec.begin()};
	auto big{*(vec.end()-1)};

	for(auto itr = vec.begin()+1; itr != vec.end()-1; itr++){

		if(*itr < small){
			*vec.begin() = *itr;
			*itr = small;
			small = *vec.begin();

		}else if(*itr > big){
			*(vec.end()-1) = *itr;
			*itr = big;
			big = *(vec.end()-1);
		}
	}

	for(auto itr = vec.begin(); itr != vec.end(); itr++){

		cout << *itr << " ";
	}

	cout << endl;

}

int main(){

	vector<int> x = {2,4,3,1};

	vector<int> y{4,3,2,0,1,2};
	vector<int> z{-1,3,2,4};
	vector<int> a{4,3,2,1};

	sortOfSort(x);
	sortOfSort(y);
	sortOfSort(z);
	sortOfSort(a);
	return 0;
}
