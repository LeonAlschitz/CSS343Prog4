// -------------------------------- Customer.cpp ---------------------------------
//
// Author Name: Tim Lawton
//
// Creation Date: 07/16/2019
//
// Date of Last Modification: 8/19/2019
//
// Description: a Customer Class implementation file.
// This file is the interface for the Customer class. Each object of this class
// represents a current customer of the business. The objects are hashed into the
// hash table. Each object stores it's own transaction history in a vector, which
// is updated as transactions are processed.
//
// Customers are indexed in a hash table in the class CustomerHash
// -----------------------------------------------------------------------------
#include "Customer.h"
#include "Transaction.h"//check
#include <vector>
using namespace std;


// ------------------------------Customer-------------------------------
// Description: this a default constructor for a Customer
// preconditions: *this is a totally un-initialized Customer
// postconditions: The fields of *this will be initialized, and the
//                 Customer will contain default values for its data
// ---------------------------------------------------------------------

Customer::Customer()
{
    customerID = 0;
    firstName = "";
    lastName = "";
}


// -----------------~Customer()------------------
// Description: this is the deconstructor.
// preconditions: None.
// postconditions: a Customer deconstructed.
// --------------------------------------------------

Customer::~Customer()
{}


// ------------------------------setCustomerInfo-------------------------------
// Description: this a setter for a Customer
//preconditions: a string with valid data format is passed in.
//postconditions: a new instance of customer is created and returned.
// ---------------------------------------------------------------------

void Customer::setCustomerInfo(istream &inFile)
{

    inFile >> customerID; //sets customer ID

    if(inFile.eof())
    {
        return; //end of file
    }

    inFile.get();
    inFile >> lastName; //sets last name

    inFile.get();
    inFile >> firstName; //sets first name
}


// ------------------------------getID-------------------------------
// Description: returns calling object's customerID.
//preconditions: must be called on a valid instance of customer.
//postconditions: instance values remain unchanged.
// ---------------------------------------------------------------------

int Customer::getID() const
{
    return customerID;
}


// ------------------------------getFirstName-------------------------------
// Description: returns calling objects firstName.
//preconditions: must be called on a valid instance of customer.
//postconditions: instance values remain unchanged.
// ---------------------------------------------------------------------

string Customer::getFirstName() const
{
    return firstName;
}


// ------------------------------getLastName-------------------------------
// Description: returns calling objects lastName.
//preconditions: must be called on a valid instance of customer.
//postconditions: instance values remain unchanged.
// ---------------------------------------------------------------------

string Customer::getLastName() const
{
    return lastName;
}


// ------------------------------printHistory-------------------------------
// Description: prints the customers transaction history.
//preconditions: None
//postconditions: prints history vector
// ---------------------------------------------------------------------

void Customer::printHistory() const
{
    cout << "Customer ID: " << customerID << " Last Name: " << lastName << " First Name: " << firstName << endl;

    if(transHistory.size() > 0)
    {

        for (unsigned int i = 0; i < transHistory.size(); i++)
        {
            transHistory[i].display();
        }

        cout << "End of History" << endl;
    }
    else
    {
        cout << "No Customer History" << endl;
    }
}


// ------------------------------StoreTransaction-------------------------------
// Description: stores the passed Transaction param in this objects history
//by inserting it into the vector
//preconditions: proper param passed
//postconditions: the objects tranHistory contains the param Transaction
// ---------------------------------------------------------------------

void Customer::storeTransaction(Transaction &trans)
{
    transHistory.push_back(trans);
}





