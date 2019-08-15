#ifndef TESTDESIGN_TRANSACTION_H
#define TESTDESIGN_TRANSACTION_H

// Author Name: Design Group 8

// Description: a Transaction Class header. Transaction is an abstract class
// functioning as a base class for Transaction style classes
//
// Current derived classes include Borrow, Return, History, and Inventory


//#include "Rentable.h"
//#include "Customer.h"
class Rentable;
class Customer;

#include <iostream>
using namespace std;


class Transaction
{

public:

    // -----------------Transaction()------------------
    // Description: this is the defualt constructor.
    // preconditions: None.
    // postconditions: a transaction is constructed.
    // --------------------------------------------------
    Transaction();


    // -------------Transaction(const Transaction &newTransaction)--------
    // Description: this is the overloaded constructor.
    // preconditions: Transaction to copy.
    // postconditions: a transaction is copied.
    // ---------------------------------------------------------------------
    Transaction(const Transaction &newTransaction);


    // -----------------~Transaction()------------------
    // Description: this is the deconstructor.
    // preconditions: None.
    // postconditions: a transaction deconstructed.
    // --------------------------------------------------
    virtual ~Transaction();



    //---------------getters-----------------

    // -----------------getActionType()------------------
    // Description: accesses actionType.
    // preconditions: None.
    // postconditions: actionType is returned.
    // --------------------------------------------------
    string getActionType();


    // -----------------getMediaType()------------------
    // Description: accesses mediaType.
    // preconditions: None.
    // postconditions: mediaType is returned.
    // --------------------------------------------------
    string getMediaType();


    // -----------------getItem()------------------
    // Description: accesses itemType.
    // preconditions: None.
    // postconditions: itemType is returned.
    // --------------------------------------------------
    Rentable* getItem(); //base class of Movie class


    // -----------------getDueDate()------------------
    // Description: accesses dueDate.
    // preconditions: None.
    // postconditions: dueDate is returned.
    // --------------------------------------------------
    string getDueDate();


    //---------------------setters--------------------


    //possibly add cutomer pointer for history class.


    // -----------------SetRental------------------
    // Description: changes Transaction private variables.
    // preconditions: actionType, mediaType, *customerInfo, *itemType, dueDate);
    // postconditions: Returns boolean result for changes
    // --------------------------------------------------
    virtual bool SetRental(string newMediaType, Rentable *newItemType, Customer * theCustomer, string newDueDate); //TODO no action type? mediaType, itemType, CustomerInfo  //virtual bool SetRental(string actionType, Customer *customerInfo, string mediaType, Rentable *itemType, string dueDate);


    // -----------------display()------------------
    // Description: displays private variable values.
    // preconditions: None.
    // postconditions: private variable values are displayed.
    // --------------------------------------------------
    virtual void display() const;


protected:
    string actionType; // the action will be able to identify itself

    string mediaType; // the media type i.e. D for DVD

    Rentable* itemType; // Item class is base class of derived Movies class

    string dueDate; //date that rented item is expected to be returned
};


#endif //TESTDESIGN_TRANSACTION_H
