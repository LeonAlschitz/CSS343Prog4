
#ifndef IMPLEMENTATION_CUSTOMER_H
#define IMPLEMENTATION_CUSTOMER_H


#include<string>
#include<iostream>
#include<vector>
#include<sstream>
#include "Transaction.h"
using namespace std;

/*
PURPOSE:
This file is the interface for the Customer class. Each object of this class
represents a current customer of the business. The objects are hashed into the
hash table. Each object stores it's own transaction history in a vector, which
is updated as transactions are processed.
*/

class Customer
{
public:

	//default constructor.
	Customer();

	//parameterized constructor.
	//sstream param is parsed to initialize instance data fields.
	//preconditions: a string with valid data format is passed in.
	//postconditions: a new instance of customer is created and returned.
	Customer(stringstream& inFile);

	//destructor.
	~Customer();

	//returns calling objects customerID.
	//preconditions: must be called on a valid instance of customer.
	//postconditions: instance values remain unchanged.
	int getID() const;

	//returns calling objects firstName.
	//preconditions: must be called on a valid instance of customer.
	//postconditions: instance values remain unchanged.
	string getFirstName() const;

	//returns calling objects lastName.
	//preconditions: must be called on a valid instance of customer.
	//postconditions: instance values remain unchanged.
	string getLastName() const;

	//prints the customers transaction history.
	void printHistory() const;

	//stores the passed Transaction param in this objects history
	//by inserting it into the vector
	//preconditions: proper param passed
	//postconditions: the objects tranHistory contains the param Transaction
	void storeTransaction(Transaction& trans); // const);

private:

	int customerID;						//customer's ID.
	string firstName;					//customer's first name.
	string lastName;					//customer's last name.
	vector<Transaction> transHistory;	//vector to store this customer's transaction history.
};

#endif //IMPLEMENTATION_CUSTOMER_H

