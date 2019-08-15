
#ifndef TESTDESIGN_INVENTORY_H
#define TESTDESIGN_INVENTORY_H

#include "Transaction.h"

// Author Name: Design Group 8

// Description: a Inventory Class header.
// Inventory is a derived class from the Transaction class
//
// calls AVLTree class to print out current inventory


class AVLTree; //forward reference

class Inventory : public Transaction
{

public:

    friend class AVLTree;

    // -----------------displayInventory()------------------
    // Description: calls the printInventory method from the AVLTree
    // class to display the current store inventory
    // preconditions: None.
    // postconditions: store inventory values are displayed.
    // --------------------------------------------------
    void displayInventory() const; //calls to the Buisness class to print out stock;
};

#endif //TESTDESIGN_INVENTORY_H
