// -------------------------------- Return.cpp ---------------------------------
//
// Author Name: Tim Lawton
//
// Creation Date: 07/16/2019
//
// Date of Last Modification: 8/19/2019
//
// Description: a Return Class implementation file.
// Return is a derived class from the Transaction class
//
// when Return class is called, if customer has the item, stock = (stock + 1)
// -----------------------------------------------------------------------------

#include "Return.h"


// -----------------Return------------------
// Description: this is the default constructor.
// preconditions: None.
// postconditions: a Return copy values are constructed
// --------------------------------------------------

Return::Return()
{
    actionType = "Return";
}


// -------------Return--------
// Description: this is the overloaded constructor.
// preconditions: Return to set values to.
// postconditions: a Return is constructed.
// --------------------------------------------------

Return::Return(const Return &newReturn)
{
    actionType = newReturn.actionType;
    mediaType = newReturn.mediaType;
    itemType = newReturn.itemType;
}


// -----------------~Return-----------------
// Description: this is the deconstructor.
// preconditions: None.
// postconditions: a Return is deconstructed
// --------------------------------------------------

Return::~Return()
{}


// -SetRental(string actionType, Customer *customerInfo, Item *itemType -
// Description: changes Transaction private variables.
// preconditions: actionType, mediaType, *customerInfo, *itemType
// postconditions: Returns boolean result for changes

bool Return::SetRental(string &newMediaType, Movie *newItemType, Customer *theCustomer)
{
    if (nullptr == newItemType)
    {
        return false;
    }

    mediaType = newMediaType;
    itemType = newItemType;

    if (mediaType != "")
    {
        //TODO: Call to increase stock in Rentable class
    }

    return true;
}


// -----------------display()------------------
// Description: displays private variable values.
// preconditions: None.
// postconditions: private variable values are displayed.
// --------------------------------------------------

void Return::display() const
{
    Transaction::display();
}
