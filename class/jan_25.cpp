#include <iostream>
#include <fstream>
using namespace std;

int main(){

	int n;
	double x;
	string str;
	ifstream inFile;
	inFile.open("input.txt");
	cout << "Good? " << inFile.good() << endl;
	inFile >> n >> x >> str;
	cout << " n: " << n << endl;
	cout << " x: " << x << endl;
	cout << "str: " << str << endl;

return 0;
}
