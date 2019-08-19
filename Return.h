// -------------------------------- Return.h ---------------------------------
//
// Author Name: Tim Lawton
//
// Creation Date: 07/16/2019
//
// Date of Last Modification: 8/19/2019
//
// Description: a Return Class header.
// Return is a derived class from the Transaction class
//
// when Return class is called, if customer has the item, stock = (stock + 1)
// -----------------------------------------------------------------------------

#ifndef TESTDESIGN_RETURN_H
#define TESTDESIGN_RETURN_H

#include <iostream>
#include "Transaction.h"
//#include "Movie.h"
using namespace std;


class Return : public Transaction
{

public:

    // -----------------Return------------------
    // Description: this is the default constructor.
    // preconditions: None.
    // postconditions: a Return copy values are constructed
    // --------------------------------------------------
    Return();


    // -------------Return--------
    // Description: this is the overloaded constructor.
    // preconditions: Return to set values to.
    // postconditions: a Return is constructed.
    // --------------------------------------------------
    Return(const Return &newReturn); //overloaded constructor


    // -----------------~Return-----------------
    // Description: this is the deconstructor.
    // preconditions: None.
    // postconditions: a Return is deconstructed
    // --------------------------------------------------
    virtual ~Return();


    //------------setter-------------

    // --- SetRental(string actionType, Customer *customerInfo, Item *itemType ----
    // Description: changes Transaction private variables.
    // preconditions: mediaType, *customerInfo, *newItemType
    // postconditions: Returns boolean result for changes
    // --------------------------------------------------
    virtual bool SetRental(string &newMediaType, Movie *newItemType, Customer * theCustomer);


    // -----------------display()------------------
    // Description: displays private variable values.
    // preconditions: None.
    // postconditions: private variable values are displayed.
    // --------------------------------------------------
    virtual void display() const;
};


#endif //TESTDESIGN_RETURN_H
