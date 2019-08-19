// -------------------------------- History.h ---------------------------------
//
// Author Name: Tim Lawton
//
// Creation Date: 07/16/2019
//
// Date of Last Modification: 8/19/2019
//
// Description: a History Class header.
// History is a derived class from the Transaction class
//
// when History class is called. the customer history vector is printed
// -----------------------------------------------------------------------------


#ifndef TESTDESIGN_HISTORY_H
#define TESTDESIGN_HISTORY_H

#include <iostream>
#include "Transaction.h"
//#include "Movie.h" //TODO yes

using namespace std;

class Customer; //forward reference

class History : public Transaction
{

public:

    friend class Customer;

    // -----------------History()------------------
    // Description: this is the default constructor.
    // preconditions: None.
    // postconditions: a History copy values are constructed
    // --------------------------------------------------
    History();

    // -------------History()--------
    // Description: this is the overloaded constructor.
    // preconditions: History to set values to.
    // postconditions: a History is constructed.
    // ------------------------------------------------
    History(const History& newHistory);

    // -----------------~History------------------
    // Description: this is the deconstructor.
    // preconditions: None.
    // postconditions: a History is deconstructed
    // --------------------------------------------------
    virtual ~History() override;

    //setter

    // -SetRental(string actionType, Customer *customerInfo, Item *itemType)-
    // Description: displays customer class history. // setter name for overridden commands
    // preconditions: actionType, mediaType, *customerInfo, *itemType);
    // postconditions: Returns boolean result for changes
    // calls to customer class to print out history vector
    // --------------------------------------------------
    virtual bool SetRental(string &newMediaType, Movie *newItemType, Customer * theCustomer);
};


#endif //TESTDESIGN_HISTORY_H
