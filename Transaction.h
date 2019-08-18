#ifndef TESTDESIGN_TRANSACTION_H
#define TESTDESIGN_TRANSACTION_H

// -------------------------------- Transaction.h ---------------------------------
//
// Author Name: Tim Lawton
//
// Creation Date: 07/16/2019
//
// Date of Last Modification: 8/19/2019
//
// Description: a Transaction Class header. Transaction is an abstract class
// functioning as a base class for Transaction style classes
//
// Current derived classes include Borrow, Return, and History
// -----------------------------------------------------------------------------

//#include "Movie.h"
#include "Customer.h"
class Movie;
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
    // preconditions: Transaction to set values to.
    // postconditions: a transaction is constructed.
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
    // Description: accesses Movie.
    // preconditions: None.
    // postconditions: Movie is returned.
    // --------------------------------------------------
    Movie* getItem(); //base class of Movie class


    //---------------------setters--------------------

    //TODO: possibly add customer pointer for history class.


    // -----------------SetRental------------------
    // Description: changes Transaction private variables.
    // preconditions: actionType, mediaType, *customerInfo, *itemType);
    // postconditions: Returns boolean result for changes
    // --------------------------------------------------
    virtual bool SetRental(string &newMediaType, Movie *newItemType, Customer * theCustomer); //TODO no action type? mediaType, itemType, CustomerInfo  //virtual bool SetRental(string actionType, Customer *customerInfo, string mediaType, Rentable *itemType);


    // -----------------display()------------------
    // Description: displays private variable values.
    // preconditions: None.
    // postconditions: private variable values are displayed.
    // --------------------------------------------------
    virtual void display() const;


protected:
    string actionType; // the action will be able to identify itself

    string mediaType; // the media type i.e. D for DVD

    Movie* itemType; // Item class is base class of derived Movies class//TODO Check here for movie/itemtype
};


#endif //TESTDESIGN_TRANSACTION_H
