/*
 * main.cpp
 *
 * This files contains a small inheritance hierarchy where
 * RegularAccount is a subclass of Account. You job is
 * to have SafeAccount be a subclass of Account also.
 *
 * Author: Rick Mercer and Christian Soto
 */
#include <string>
#include <iostream>
#include <cmath>
#include <memory>
#include <cassert>
using namespace std;

class Account {

protected:
    string name;
    double balance;

public:
    Account(string name, double balance) : name(name), balance(balance) {
    }

    string getName() {
        return name;
    }

    double getBalance() {
        return balance;
    }

    void deposit(double amount) {
        balance += amount;
    }

    virtual void withdraw(double amount) = 0;
};

/////////////////////////////////////////////////
class RegularAccount : public Account {

public:
    RegularAccount(string initName, double initialBalance) :
         Account(initName, initialBalance) {
    }

    void withdraw(double amount) override {
        if (amount <= balance)
            balance -= amount;
    }

};

/////////////////////////////////////////////////
// TODO: Using good design, implement SafeAccount
// as a subclass of Account so the code in main
// compiles and and the asserts pass

class SafeAccount : public Account {

protected:

	double loan;
public:

    	SafeAccount(string initName, double initialBalance) :
        	 Account(initName, initialBalance) {

		loan = 0;
    	}

	void withdraw(double amount) override {
        	if (amount <= balance){
            		balance -= amount;
		}else{
			this->loan = amount - this->balance;
			this->balance = this->balance + this->loan;
			this->balance = this->balance - amount;
		}
    	}

	double getLoanAmount(){

		return this->loan;
	}
};

int main() {
    // Use a smart pointer just for the fun of it
    unique_ptr<RegularAccount> a = make_unique<RegularAccount>("Five", 5.55);
    assert("Five" == a->getName());
    assert (5.55 == a->getBalance());

    RegularAccount reg{"Kim", 7777.77};
    reg.deposit(44.00);
    assert("Kim" == reg.getName());
    assert(7821.77 == reg.getBalance());

    SafeAccount saf{"Chris", 111.11};
    saf.deposit(33.00);
    assert("Chris" == saf.getName());
    assert( 144.11 == saf.getBalance());
    assert(0.00 == saf.getLoanAmount());

    saf.withdraw(55.00);
    assert(0.0 == saf.getLoanAmount());
    assert(std::abs(89.11 - saf.getBalance()) < 0.1e-8);
    saf.withdraw(200.00);
    assert(std::abs(110.89 - saf.getLoanAmount()) < 0.1e-8);
    assert(0.0 == saf.getBalance());
}