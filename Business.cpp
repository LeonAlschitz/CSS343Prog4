// -------------------------------- Business.cpp ---------------------------------
//
// Author Name: Tim Lawton
//
// Creation Date: 07/16/2019
//
// Date of Last Modification: 8/19/2019
//
// Description: a Business Class header.
// -----------------------------------------------------------------------------

#include "Business.h"

Business::Business()
{

}

Business::~Business()
{

}

void Business::loadCustomers(std::ifstream &custFile)
{
    custTable.loadCustomers(custFile);
}

void Business::loadMovies(std::ifstream &movieFile)
{
    //call load movies in movie class
}

void Business::loadCommands(std::ifstream &comFile)
{
    //pull in from file load into comQueue
}

void Business::runCommands()
{
    //pop from comQueue and run each through switch statement

    /*
    switch statement
     case 'B'

          if customer exists           <--- displays its own error message getCustomer()
                if item is in stock
                     add borrow to customer vector
                    decrease stock AVL by 1
                else
                    find/offer alternate if in stock




     case 'R'

        if customer exists
            if customer has item?
              add return to customer history vector
              increase AVL stock by 1

          else
              display error message


     case 'H'

        if customer exists    <--- displays its own error message getCustomer()
            display history





     case 'I'
        display current inventory



     case 'default'

        display error message: transaction command does not exist

*/
}

void Business::displayBusiness()
{

    cout << "********* Inventory **********" << endl << endl;
    // Call displayMovies method;
    cout << endl << "***************************" << endl << endl;


    cout << "********* Customers **********" << endl << endl;
    custTable.displayCustomers();
    cout << endl << "***************************" << endl << endl;
}
