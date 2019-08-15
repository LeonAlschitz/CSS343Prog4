#ifndef TESTDESIGN_BORROW_H
#define TESTDESIGN_BORROW_H

// Author Name: Design Group 8

// Description: a Borrow Class header.
// Borrow is a derived class from the Transaction class
//
// when Borrow class is called, if Item is in stock, stock = (stock - 1)

#include <iostream>
#include "Transaction.h"
//#include "Rentable.h"
//#include "Customer.h" no but call the class //missing a virtual Transaction* create();
using namespace std;


class Borrow : public Transaction
{

public:

    // -----------------Borrow()------------------
    // Description: this is the default constructor.
    // preconditions: None.
    // postconditions: a Borrow is copied
    // --------------------------------------------------
    Borrow();


    // -----------------Borrow()------------------
    // Description: this is the overloaded constructor.
    // preconditions: None.
    // postconditions: a Borrow copy is constructed.
    // --------------------------------------------------
    Borrow(const Borrow &newBorrow); //overloaded constructor


    // -----------------~Borrow()------------------
    // Description: this is the deconstructor.
    // preconditions: None.
    // postconditions: a Borrow is deconstructed
    // --------------------------------------------------
    virtual ~Borrow();


    //------------setter-------------//

    // ---SetRental(string actionType, Customer *customerInfo, Item *itemType, string dueDate)--
    // Description: changes Transaction private variables.
    // preconditions: preconditions: actionType, mediaType, *customerInfo, *itemType, dueDate);
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


#endif //TESTDESIGN_BORROW_H
