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

    //constructors
    History();
    History(const History& newHistory); //overloaded constructor

    //deconstructor
    virtual ~History() override;

    //setter

    // -SetRental(string actionType, Customer *customerInfo, Item *itemType)-
    // Description: changes Transaction private variables.
    // preconditions: actionType, mediaType, *customerInfo, *itemType);
    // postconditions: Returns boolean result for changes
    // --------------------------------------------------
    virtual bool SetRental(string &newMediaType, Movie *newItemType, Customer * theCustomer);

    // -----------------displayHistory()------------------
    // Description: displays customer class history.
    // preconditions: None.
    // postconditions: customer history is displayed.
    // --------------------------------------------------
   // void displayHistory(); //call to Customer class to display history vector

};


#endif //TESTDESIGN_HISTORY_H
