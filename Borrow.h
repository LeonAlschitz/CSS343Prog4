// -------------------------------- Borrow.h ---------------------------------
//
// Author Name: Tim Lawton
//
// Creation Date: 07/16/2019
//
// Date of Last Modification: 8/19/2019
//
// Description: a Borrow Class header.
// Borrow is a derived class from the Transaction class
//
// when Borrow class is called, if Item is in stock, stock = (stock - 1)
// -----------------------------------------------------------------------------

#ifndef TESTDESIGN_BORROW_H
#define TESTDESIGN_BORROW_H


#include <iostream>
#include "Transaction.h"
//#include "Movie.h"
//#include "Customer.h" no but call the class //missing a virtual Transaction* create();
using namespace std;


class Borrow : public Transaction
{

public:

    // -----------------Borrow()------------------
    // Description: this is the default constructor.
    // preconditions: None.
    // postconditions: a Borrow copy values are constructed
    // --------------------------------------------------
    Borrow();


    // -------------Borrow()--------
    // Description: this is the overloaded constructor.
    // preconditions: Borrow to set values to.
    // postconditions: a Borrow is constructed.
    // ---------------------------------------------
    Borrow(const Borrow &newBorrow);


    // -----------------~Borrow------------------
    // Description: this is the deconstructor.
    // preconditions: None.
    // postconditions: a Borrow is deconstructed
    // --------------------------------------------------
    virtual ~Borrow();


    //------------setter-------------//

    // ---SetRental(string actionType, Customer *customerInfo, Item *itemType)--
    // Description: changes Transaction private variables.
    // preconditions: preconditions: actionType, mediaType, *customerInfo, *itemType
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


#endif //TESTDESIGN_BORROW_H
