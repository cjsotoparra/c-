#include <vector>
using namespace std;

template<typename T>
class Matrx {

	//data fields
	private:
		vector<vector<T>> table;
		int rows, cols;

	//constructor
	public:
		Matrix(vector<vector<T>> const & table){

			this->table = table;
			rows = table.size();
			cols = table[0].size();
		}

	//Getters
	int nRows const(){
		return rows;
	}

	int nColumns const(){
		return cols;
	}

	T get(int row, int col) const {

		table.at(row).at(cols);
	}

	//Modifers
	void operator += (Matrix const &other){

		for(auto r{0} ; r<rows; r++){
			for(auto c{0}; c< cols; c++){

				this->table.at(r).at(c) += other.table.at(r).at(c);
			}

		}
	}

	void operator *= (int num){

		for(auto r{0}; r< rows; r++){
			for(auto c{0}; c< cols; c++){
				table.at(r).at(c) = table.at(r).at(c) * num;
			}
		}
	}

	void operator + (Matrix const &other){

		Matrix temp = *this;

		/*for(auto r{0} ; r<rows; r++){

			for(auto c{0}; c<cols; c++){

				temp.table.at(r).at(c) += this->table.at(r).at(c);
			}
		}*/

		temp += other;
		return temp;
	}
};
