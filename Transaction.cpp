// -------------------------------- Transaction.cpp ---------------------------------
//
// Author Name: Tim Lawton
//
// Creation Date: 07/16/2019
//
// Date of Last Modification: 8/19/2019
//
// Description: a Transaction Class implementation file. Transaction is an abstract class
// functioning as a base class for Transaction style classes
//
// Current derived classes include Borrow, Return, History, and Inventory
// -----------------------------------------------------------------------------

#include "Transaction.h"


// -----------------Transaction()------------------
// Description: this is the defualt constructor.
// preconditions: None.
// postconditions: a transaction is constructed.
// This constructor calls the overloaded constructor
// --------------------------------------------------

Transaction::Transaction() : actionType("Transaction"), mediaType(""), itemType(nullptr)
{
}


// -------------Transaction(const Transaction &newTransaction)--------
// Description: this is the overloaded constructor.
// preconditions: Transaction to set values to.
// postconditions: a transaction is constructed.
// ---------------------------------------------------------------------

Transaction::Transaction(const Transaction &newTransaction)
{
    actionType = newTransaction.actionType;
    mediaType = newTransaction.mediaType;
    itemType = newTransaction.itemType;
}


// -----------------~Transaction()------------------
// Description: this is the deconstructor.
// preconditions: None.
// postconditions: a transaction deconstructed.
// --------------------------------------------------

Transaction::~Transaction()
{}


// -----------------getActionType()------------------
// Description: accesses actionType.
// preconditions: None.
// postconditions: actionType is returned.
// --------------------------------------------------

string Transaction::getActionType()
{
    return actionType;
}


// -----------------getMediaType()------------------
// Description: accesses mediaType.
// preconditions: None.
// postconditions: mediaType is returned.
// --------------------------------------------------

string Transaction::getMediaType()
{
    return mediaType;
}


// -----------------getItem()------------------
// Description: accesses Movie.
// preconditions: None.
// postconditions: Movie is returned.
// --------------------------------------------------

Movie* Transaction::getItem()
{
    return itemType;
}

// -----------------SetRental------------------
// Description: changes Transaction private variables.
// preconditions: actionType, mediaType, *customerInfo, *itemType);
// postconditions: Returns boolean result for changes
// --------------------------------------------------

bool Transaction::SetRental(string &newMediaType, Movie *newItemType, Customer * theCustomer)
{

    mediaType = newMediaType;
    itemType = newItemType;

    return true;
}


// -----------------display()------------------
// Description: displays private variable values.
// preconditions: None.
// postconditions: private variable values are displayed.
// --------------------------------------------

void Transaction::display() const
{
    cout << "Transaction: " << actionType << ", Media: " << mediaType << ", Item: " << itemType << endl;
}
