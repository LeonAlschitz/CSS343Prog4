#ifndef TESTDESIGN_HISTORY_H
#define TESTDESIGN_HISTORY_H

#include <iostream>
#include "Transaction.h"
//#include "Movie.h" //TODO yes

class Customer;//forward reference

using namespace std;

// Author Name: Design Group 8

// Description: a History Class header.
// History is a derived class from the Transaction class
//
// calls Customer class to print out history vector

class Customer; //forward reference

class History : public Transaction
{

public:

    friend class Customer;

    //constructors
    History();
    History(const History& newHistory); //overloaded constructor

    //deconstructor
    virtual ~History() override;

    //setter

    // -SetRental(string actionType, Customer *customerInfo, Item *itemType, string dueDate)-
    // Description: changes Transaction private variables.
    // preconditions: actionType, mediaType, *customerInfo, *itemType, dueDate);
    // postconditions: Returns boolean result for changes
    // --------------------------------------------------
    virtual bool SetRental(string newMediaType, Movie *newItemType, Customer * theCustomer, string newDueDatee);

    // -----------------displayHistory()------------------
    // Description: displays customer class history.
    // preconditions: None.
    // postconditions: customer history is displayed.
    // --------------------------------------------------
   // void displayHistory(); //call to Customer class to display history vector

    //TODO virtual Transaction* create(); return new History();
};


#endif //TESTDESIGN_HISTORY_H
