#ifndef TESTDESIGN_RETURN_H
#define TESTDESIGN_RETURN_H

#include <iostream>
#include "Transaction.h"
//#include "Rentable.h"
using namespace std;

// Author Name: Design Group 8

// Description: a Return Class header.
// Return is a derived class from the Transaction class
//
// when Return class is called, if customer has the item, stock = (stock + 1)

class Return : public Transaction
{

public:

    // -----------------Return()------------------
    // Description: this is the default constructor.
    // preconditions: None.
    // postconditions: a Return is copied
    // --------------------------------------------------
    Return();


    // -----------------Return()------------------
    // Description: this is the overloaded constructor.
    // preconditions: None.
    // postconditions: a Return copy is constructed.
    // --------------------------------------------------
    Return(const Return &newReturn); //overloaded constructor


    // -----------------~Return()------------------
    // Description: this is the deconstructor.
    // preconditions: None.
    // postconditions: a Return is deconstructed
    // --------------------------------------------------
    virtual ~Return();


    //------------setter-------------

    // -SetRental(string actionType, Customer *customerInfo, Item *itemType, string dueDate)-
    // Description: changes Transaction private variables.
    // preconditions: actionType, mediaType, *customerInfo, *itemType, dueDate);
    // postconditions: Returns boolean result for changes
    // --------------------------------------------------
    virtual bool SetRental(string newMediaType, Rentable *newItemType, Customer * theCustomer, string newDueDate);


    // -----------------display()------------------
    // Description: displays private variable values.
    // preconditions: None.
    // postconditions: private variable values are displayed.
    // --------------------------------------------------
    virtual void display() const;
};


#endif //TESTDESIGN_RETURN_H
