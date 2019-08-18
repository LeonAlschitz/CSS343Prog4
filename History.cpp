//
// Created by tglaw on 8/6/2019.
//

#include "History.h"
#include "Customer.h"


// -----------------History()------------------
// Description: this is the default constructor.
// preconditions: None.
// postconditions: a History copy values are constructed
// --------------------------------------------------

History::History()
{
    actionType = "History";
}


// -------------History()--------
// Description: this is the overloaded constructor.
// preconditions: History to set values to.
// postconditions: a History is constructed.
// ------------------------------------------------

History::History(const History &newHistory)
{
    actionType = newHistory.actionType;
    mediaType = newHistory.mediaType;
    itemType = newHistory.itemType;
}


// -----------------~History------------------
// Description: this is the deconstructor.
// preconditions: None.
// postconditions: a History is deconstructed
// --------------------------------------------------

History::~History()
{}


// -SetRental(string actionType, Customer *customerInfo, Movie *newItemType)-
// Description: displays customer class history. // setter name for overridden commands
// preconditions: actionType, mediaType, *customerInfo, *Movie);
// postconditions: Returns boolean result for changes
// calls to customer class to print out history vector
// --------------------------------------------------

bool History::SetRental(string &newMediaType, Movie *newItemType, Customer *theCustomer)
{
    theCustomer->printHistory();

    return false;
}


