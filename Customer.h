// -------------------------------- Customer.h ---------------------------------
//
// Author Name: Tim Lawton
//
// Creation Date: 07/16/2019
//
// Date of Last Modification: 8/19/2019
//
// Description: a Customer Class header.
// This file is the interface for the Customer class. Each object of this class
// represents a current customer of the business. The objects are hashed into the
// hash table. Each object stores it's own transaction history in a vector, which
// is updated as transactions are processed.
//
// Customers are indexed in a hash table in the class CustomerHash
// -----------------------------------------------------------------------------


#ifndef IMPLEMENTATION_CUSTOMER_H
#define IMPLEMENTATION_CUSTOMER_H


#include<string>
#include<iostream>
#include<vector>
#include<sstream>
#include "Transaction.h"
#include "Movie.h"
#include "AVLTree.h"

using namespace std;

class Transaction; //forward reference


class Customer
{
public:

	// ------------------------------Customer-------------------------------
	// Description: this a default constructor for a Customer
	// preconditions: *this is a totally un-initialized Customer
	// postconditions: The fields of *this will be initialized, and the
	//                 Customer will contain default values for its data
	// ---------------------------------------------------------------------
	Customer();

	// -----------------~Customer()------------------
	// Description: this is the deconstructor.
	// preconditions: None.
	// postconditions: a Customer deconstructed.
	// --------------------------------------------------
	~Customer();

	// ------------------------------setCustomerInfo-------------------------------
	// Description: this a setter for a Customer
	//preconditions: a string with valid data format is passed in.
	//postconditions: a new instance of customer is created and returned.
	// ---------------------------------------------------------------------
	void setCustomerInfo(istream& inFile);

	// ------------------------------getID-------------------------------
	// Description: returns calling object's customerID.
	//preconditions: must be called on a valid instance of customer.
	//postconditions: instance values remain unchanged.
	// ---------------------------------------------------------------------
	int getID() const;

	// ------------------------------getFirstName-------------------------------
	// Description: returns calling objects firstName.
	//preconditions: must be called on a valid instance of customer.
	//postconditions: instance values remain unchanged.
	// ---------------------------------------------------------------------
	string getFirstName() const;

	// ------------------------------getLastName-------------------------------
	// Description: returns calling objects lastName.
	//preconditions: must be called on a valid instance of customer.
	//postconditions: instance values remain unchanged.
	// ---------------------------------------------------------------------
	string getLastName() const;

	// ------------------------------printHistory-------------------------------
	// Description: prints the customers transaction history.
	//preconditions: None
	//postconditions: None
	// ---------------------------------------------------------------------
	void printHistory() const;

	// ------------------------------StoreTransaction-------------------------------
	// Description: stores the passed Transaction param in this objects history
	//by inserting it into the vector
	//preconditions: proper param passed
	//postconditions: the objects tranHistory contains the param Transaction
	// ---------------------------------------------------------------------
	void storeTransaction(Transaction& trans); // const);

	// ------------------------------addToCustomerInventory-------------------------------
	// Description: Adds movie to customer's current inventory.
	//preconditions: the movie being added
	//postconditions: customer inventory vector updated
	// ---------------------------------------------------------------------
	void addToCustomerInventory(Movie *theMovie);

	// ------------------------------removeFromCustomerInventory-------------------------------
	// Description: removes movie from customer's current inventory.
	//preconditions: the movie being removed
	//postconditions: customer inventory vector updated
	// ---------------------------------------------------------------------
	bool removeFromCustomerInventory(Movie *theMovie);


private:

	int customerID;						//customer's ID.
	string firstName;					//customer's first name.
	string lastName;					//customer's last name.
	vector<Transaction> transHistory;	//vector to store this customer's transaction history.
	vector<Movie> currentCheckOut;		//vector of currently checked out movies.
};

#endif //IMPLEMENTATION_CUSTOMER_H

