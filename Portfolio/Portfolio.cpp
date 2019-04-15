/*
 * Portfolio.cpp
 *
 *  Created on: Oct 31, 2018
 *      Author: mercer and Christian Soto
 */
#include <string>
#include <iostream>
#include <vector>
#include <memory>
#include <cassert>
#include <cmath>
#include <iomanip> // for setprecision
using namespace std;

class Asset {

  // All Assets have a name and a value
protected:
  string name;
  double value;

  // Return amt rounded to 2 decimal places.
  // This function may be used by all subclasses (or write your own in each)
  double rounded(double amt) {
    return ((int) (amt * 100.0)) / 100.0;
  }

public:
  // This constructor must be called from all subclasses like this for BankAccount:
  //
  //   BankAccount(string assetName, double startBalance) :
  //     Asset(assetName), balance(startBalance) {
  //   }
  Asset(string assetName, double currentValue) {
    name = assetName;
    value = currentValue;
  }

  string toString() {
    string part = to_string(rounded(getValue()));
    int dot = part.find(".");
    part = part.substr(0, dot + 3);  // remove trailing zeros
    return name + ": " + part;
  }

  string getName() {
    return name;
  }

  // Abstract methods like getValue must be implemented by any
  // class that is derived by this abstract class Asset.
  virtual double getValue () = 0;

};

/////////////////////////////////////////////////
// TODO: Complete class BankAccount. Add 2 new methods:
// withdraw(double)
// deposit(double)
class BankAccount: public Asset{

public:

	BankAccount(string initName, double initialBalance):Asset(initName, initialBalance){

	}

	void withdraw(double money){

		if(money <= value){

			value -= money;
		}
	}

	void deposit(double amount){

		value += amount;
	}

	double getValue() override{
		return this->value;
	}

};

///////////////////////////////////////////
// TODO: Complete class bond, no new methods here

class Bond: public Asset{

public:

        Bond(string initName, double initialBalance):Asset(initName, initialBalance){

        }

	double getValue() override{
		return this->value;
	}

};//Bond



////////////////////////////////////////////////////////////
// TODO Complete class Stock. Two new methods added here.
// Two new data members added: shares and price
// Override getValue to return shares * price
class Stock: public Asset{

	double shares;
	double price;
public:
        Stock(string initName, double initialShares, double initialPrice):Asset(initName, initialPrice){

                shares = initialShares;
		price = initialPrice;
        }

	void changeShares(double newShares){
		this->shares = newShares;
	}

	void changePrice(double  newPrice){
		this->price = newPrice;
	}

	double getValue() override{
		return this->shares * this->price;
	}
};

//////////////////////////////////////////////
// TODO: Complete class Portfolio. You need a vector
// of smart pointers and two new methods:
//  void add(const std::shared_ptr<Asset> & asset) 
//  std::shared_ptr<Asset> & get(int index)
class Portfolio{

	vector<shared_ptr<Asset>> ports;
	string name;
	double balance;

public:

	Portfolio(string initialName){
		name = initialName;
		balance = 0.0;
	}

	void add(const shared_ptr<Asset> & asset){

		ports.push_back(asset);
	}

	string getName () const{
		return this->name;
	}

	shared_ptr<Asset> & get(int index){
		return this->ports.at(index);
	}

	void showAll(){

		cout << "All Assets" << endl;
		cout << "==========" << endl;
		for(auto port: this->ports){

			cout << port->getName() << ": " << port->getValue();
			cout << endl;
		}
	}

	double getValue(){

		this->balance = 0.0;

		for(auto port: ports){

			this->balance += port->getValue();
		}

		return this->balance;
	}

};
// Add all classes above to get this code to compile
// and generate the output shown at the bottom of this file.
int main () {

  auto acct = shared_ptr<BankAccount>(new BankAccount("account", 50.00));
  auto stock = shared_ptr<Stock>(new Stock("stock", 50, 10.0));
  auto bond = shared_ptr<Bond>(new Bond("bond", 5000));

  Portfolio portfolio("My Portfolio");
  // Just as we can convert an ordinary pointer to a derived
  // type to a pointer to a base-class type, we can also
  // convert a smart pointer to a derived type to a smart
  // pointer to a base-class type.  All of the elements of
  // Portfolio have the same type: shared_ptr<Asset>
  portfolio.add(acct);
  portfolio.add(stock); // void add(std::shared_ptr<Asset> const & asset)
  portfolio.add(bond);  // Now we can call push_back(asset)

  // Show the individual assets
  cout << portfolio.get(0)->getName() << ": " << portfolio.get(0)->getValue() << "\n";
  cout << portfolio.get(1)->getName() << ": " << portfolio.get(1)->getValue() << "\n";
  cout << portfolio.get(2)->getName() << ": " << portfolio.get(2)->getValue() << "\n";
  cout << "\n";

  // Show the total value of the portfolio.
  // getValue() will be a recursive method
  portfolio.showAll();
  cout << endl;
  cout << "Total: ";
  cout << fixed << setprecision(2)
       << portfolio.getValue();
  cout << endl;

  // Change one Asset twice
  acct->withdraw(50.00); // balance 0.0
  acct->deposit(1.23); // balance 1.23

  // Change another Asset twice
  stock->changeShares(10);
  stock->changePrice(7.00); // getValue() 70

  // Access directly
  cout << portfolio.get(0)->getName() << ": "
       << portfolio.get(0)->getValue() << "\n";
  cout << portfolio.get(1)->getName() << ": "
       << portfolio.get(1)->getValue() << "\n";
  cout << portfolio.get(2)->getName() << ": "
       << portfolio.get(2)->getValue() << "\n";
  cout << "\n";

  // Use a loop to show all Assets
  portfolio.showAll();
  cout << "\nPortfolio's Total Value: ";
  std::cout << fixed << setprecision(2)
            << portfolio.getValue() <<  "\n";

  return 0;
}

/* Expected Output:

account: 50
stock: 500
bond: 5000

All Assets
==========
account: 50.00
stock: 500.00
bond: 5000.00

Total: 5550.00
account: 1.23
stock: 70.00
bond: 5000.00

All Assets
==========
account: 1.23
stock: 70.00
bond: 5000.00

Portfolio's Total Value: 5071.23
 */
