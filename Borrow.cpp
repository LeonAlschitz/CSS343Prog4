// -------------------------------- Borrow.cpp ---------------------------------
//
// Author Name: Tim Lawton
//
// Creation Date: 07/16/2019
//
// Date of Last Modification: 8/19/2019
//
// Description: a Borrow Class implementation file.
// Borrow is a derived class from the Transaction class
//
// when Borrow class is called, if Item is in stock, stock = (stock - 1)
// -----------------------------------------------------------------------------
#include "Borrow.h"


// -----------------Borrow()------------------
// Description: this is the default constructor.
// preconditions: None.
// postconditions: a Borrow copy values are constructed
// --------------------------------------------------

Borrow::Borrow()
{
    actionType = "Borrow";
}


// -----------------Borrow()------------------
// Description: this is the overloaded constructor.
// preconditions: a borrow object to set values to.
// postconditions: a Borrow copy is constructed.
// --------------------------------------------------

Borrow::Borrow(const Borrow &newBorrow)
{
    actionType = newBorrow.actionType;
    mediaType = newBorrow.mediaType;
    itemType = newBorrow.itemType;
}


// -----------------~Borrow()------------------
// Description: this is the deconstructor.
// preconditions: None.
// postconditions: a Borrow is deconstructed
// --------------------------------------------------

Borrow::~Borrow()
{}


// ---SetRental(string actionType, Customer *customerInfo, Item *itemType--
// Description: changes Transaction private variables.
// preconditions: preconditions: actionType, mediaType, *customerInfo, *itemType
// postconditions: Returns boolean result for changes
// --------------------------------------------------

bool Borrow::SetRental(string &newMediaType, Movie *newItemType, Customer *theCustomer)
{
    if (nullptr == newItemType)
    {
        return false;
    }

    mediaType = newMediaType;
    itemType = newItemType;

    if (mediaType != "")
    {
        return true;
    }
    else
    {
        return false;
    }

}


// -----------------display()------------------
// Description: displays private variable values.
// preconditions: None.
// postconditions: private variable values are displayed.
// --------------------------------------------------

void Borrow::display() const
{
    Transaction::display();
}

