//
// Created by tglaw on 8/6/2019.
//

#include "Transaction.h"

Transaction::Transaction() : actionType("Transaction"), mediaType(""), itemType(nullptr), dueDate("")
{
}

Transaction::Transaction(const Transaction &newTransaction)
{
    actionType = newTransaction.actionType;
    mediaType = newTransaction.mediaType;
    itemType = newTransaction.itemType;
    dueDate = newTransaction.dueDate;
}

Transaction::~Transaction()
{}

string Transaction::getActionType()
{
    return actionType;
}

string Transaction::getMediaType()
{
    return mediaType;
}

Movie* Transaction::getItem()
{
    return itemType;
}

string Transaction::getDueDate()
{
    return dueDate;
}

bool Transaction::SetRental(string newMediaType, Movie *newItemType, Customer * theCustomer, string newDueDate)
{

    mediaType = newMediaType;
    itemType = newItemType;
    dueDate = newDueDate;

    return true;
}

void Transaction::display() const
{
    cout << "Transaction: " << actionType << ", Media: " << mediaType << ", Item: " << itemType;

    if(!dueDate.empty())
    {
        cout << ", Due Date: " << dueDate;
    }

    cout << endl;
}
