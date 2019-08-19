// -------------------------------- Business.h ---------------------------------

// Student: Tim Lawton

// Creation Date: 07/16/2019

// Date of Last Modification: 8/19/2019

// -----------------------------------------------------------------------------
// Purpose -

// -----------------------------------------------------------------------------
#ifndef TESTDESIGN_BUSINESS_H
#define TESTDESIGN_BUSINESS_H

#include <iostream>
#include <fstream>
#include <queue>

#include "CustomerHash.h"
#include "Movie.h"
#include "AVLTree.h"
#include "Transaction.h"

class Business
{
public:
    // ------------------------------Business-------------------------------
    // Description: this creates a new Business
    // preconditions: *this is a totally un-initialized Business
    // postconditions: The fields of *this will be initialized, and the
    //                 Business will contain default values for its data
    // ---------------------------------------------------------------------
    Business();

    // ------------------------------~Business------------------------------
    // Description: destroys and decomposes Business memory, as-needed
    // preconditions: *this is in any valid state
    // postconditions: all dynamically allocated memory is freed, and the
    //                 Business is in a deletable state
    // ---------------------------------------------------------------------
    virtual ~Business();

    // ---------------------------loadCustomers-----------------------------
    // Description: loads Customer into CustomerHash table
    // preconditions: *this has already been initialized, and is valid
    // postconditions: The file will have been read, &
    //                 The customers will be in the CustomerHash table
    //@param custFile is the ifstream object of the file
    // ---------------------------------------------------------------------
    void loadCustomers(std::ifstream& custFile);

    // -----------------------------loadMovies------------------------------
    // Description: loads the movies from movieFile into the Movie database
    // preconditions: *this has already been initialized, and is valid
    // postconditions: The file will have been read, &
    //                 The Movies will be in the database
    //@param movieFile is the ifstream object of the file
    // ---------------------------------------------------------------------
    void loadMovies(std::ifstream& movieFile);

    // ----------------------------loadCommands-----------------------------
    // Description: loads the commmands from comFile into a Queue
    // preconditions: *this has already been initialized
    // postconditions: The file will have been read, and the commands stored
    //                 in the comQueue
    //@param comFile is the ifstream object of the file
    // ---------------------------------------------------------------------
    void loadCommands(std::ifstream& comFile);

    // ----------------------------runCommands------------------------------
    // Description: runs the commands loaded via loadCommands
    // preconditions: *this has been initialized, and commands loaded
    // postconditions: The commands will have been execusted, &
    //                 The command queue will be emptied.
    // ---------------------------------------------------------------------
    void runCommands();

    // --------------------------displayBusiness----------------------------
    // Description: uses couts to output business information
    // preconditions: *this has already been initialized, and is valid
    // postconditions: data from the Business will have been put to cout
    // ---------------------------------------------------------------------
    void displayBusiness();

    void printMenu();

    AVLTree* getTree(){return tree;}
protected:

private:
    queue<Transaction> comQueue;
    CustomerHash       custTable;  //CustomerHash table of the customers
    AVLTree *tree = NULL;
};


#endif //TESTDESIGN_BUSINESS_H
