//
// Created by tglaw on 8/6/2019.
//

#include "History.h"
#include "Customer.h"

History::History()
{
    actionType = "History";
}

History::History(const History &newHistory)
{
    actionType = newHistory.actionType;
    mediaType = newHistory.mediaType;
    itemType = newHistory.itemType;
    dueDate = newHistory.dueDate;
}

History::~History()
{}

bool History::SetRental(string newMediaType, Movie *newItemType, Customer *theCustomer, string newDueDatee)
{
    theCustomer->printHistory();

    return false;
}


