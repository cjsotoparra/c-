/*
 * PiggyBank.h
 *
 *  Created on: Sep 16, 2018
 *      Author: mercer
 */
#ifndef PIGGYBANK_H_
#define PIGGYBANK_H_

// A PiggyBank represents a software model of a real PiggyBank
class PiggyBank {

public: // Member functions

  // Construct an empty PiggyBank that can store pennies, nickels,
  // and/or dimes (no quarters, halves or dollar coins to save time)
  PiggyBank();

  // An addPennies message adds the given number of pennies to this PiggyBank
  // Precondition: penniesEntered >= 1
  void addPennies(int penniesEntered);

  // An addNickels message adds the given number of nickles to this PiggyBank
  // Precondition: numberOfNickels >= 1
  void addNickels(int numberOfNickels);

  // An addSimes message adds the given number of dimes to this PiggyBank
  // Precondition: numberOfDimes >= 1
  void addDimes(int numberOfDimes);

  // A getTotalCashInBank() message should return the total amount of
  // cash in the bank. Pennies are $0.01, nickels are $0.05, and dimes
  // are $0.10  (no quarters, halves, or dollar coins allowed to save time).
  double getTotalCashInBank();

private: // Data Members:
  double pennies, nickels, dimes;
};

#endif /* PIGGYBANK_H_ */
