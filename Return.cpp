//
// Created by tglaw on 8/6/2019.
//

#include "Return.h"

Return::Return()
{
    actionType = "Return";
}

Return::Return(const Return &newReturn)
{
    actionType = newReturn.actionType;
    mediaType = newReturn.mediaType;
    itemType = newReturn.itemType;
    dueDate = newReturn.dueDate;
}

Return::~Return()
{}

bool Return::SetRental(string newMediaType, Movie *newItemType, Customer *theCustomer, string newDueDate)
{
    if (nullptr == newItemType)
    {
        return false;
    }

    mediaType = newMediaType;
    itemType = newItemType;

    if (newDueDate != "")
    {
        dueDate = newDueDate;
    }

    if (mediaType != "")
    {
        //TODO: Call to increase stock in Rentable class
    }

    return true;
}

void Return::display() const
{
    Transaction::display();
}
