//
// Created by tglaw on 8/6/2019.
//

#include "Borrow.h"

Borrow::Borrow()
{
    actionType = "Borrow";
}

Borrow::Borrow(const Borrow &newBorrow)
{
    actionType = newBorrow.actionType;
    mediaType = newBorrow.mediaType;
    itemType = newBorrow.itemType;
    dueDate = newBorrow.dueDate;
}

Borrow::~Borrow()
{}

bool Borrow::SetRental(string newMediaType, Rentable *newItemType, Customer *theCustomer, string newDueDate)
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
        //TODO: Call to decrease stock in Rentable class
    }

    return true;
}

void Borrow::display() const
{
    Transaction::display();
}

