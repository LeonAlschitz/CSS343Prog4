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
#include "Borrow.h"
#include "Return.h"
#include "History.h"
#include "CustomerHash.h"


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

//***********************************************************************
//Possibly remove comQueue as it seems un-needed and directly run commands

void Business::loadCommands(std::ifstream &comFile)
{
    char commandType;
    string newMedia;
    Movie* newMovie = nullptr;
    Customer* newCustomer;
    int customerID;

    while (!comFile.eof())
    {
        comFile >> commandType;

        switch (commandType)
        {
            case 'B': // Borrow Movie
            {
             //   TODO: error checking


                comFile.get();

                comFile >> customerID;
                newCustomer = custTable.getCustomer(customerID);

                if(nullptr == newCustomer) //no customer, prints its own error
                {
                    break;
                }

                /*

                if item is in stock
                     add borrow to customer vector
                    decrease stock AVL by 1
                else
                    find/offer alternate if in stock

                 if movie is not in stock
                      if alternate is in stock
                          offer different movie
                      else
                          error message
                 else
                    run code below
                */


                //TODO: SET newMovie to AVLcomfile.get()

                Borrow* newBorrow = new Borrow;

                if(newBorrow->SetRental(newMedia, newMovie, newCustomer))
                {
                    // TODO: newMovie->updateStock(1);
                }

                break;
            }

            case 'R': // Return Movie
            {
                //TODO: error checking

                Return *newReturn = new Return;
                newReturn->SetRental(newMedia, newMovie, newCustomer);

                comQueue.push(*newReturn);

                // TODO: newMovie->updateStock(-1);

                break;
            }

            case 'H': // Print customer history
            {
                //TODO: error checking

                History *newHistory = new History;

                comFile >> customerID;
                newCustomer = custTable.getCustomer(customerID);

                if(nullptr == newCustomer) //no customer, prints its own error
                {
                    break;
                }

                newHistory->SetRental(newMedia, newMovie, newCustomer);

                break;
            }

            case 'I':  // Print inventory
            {
                //TODO: call AVLTree printInventory();


                break;
            }

            default: // Invalid command
            {
                cout << endl << "**********************************" << endl << endl;

                cout << "Error: Transaction command invalid: " << commandType << endl;

                cout << endl << "**********************************" << endl << endl;

                break;
            }
        }

    }
}




void Business::runCommands()
{
    //pop from comQueue and run each through switch statement

    /*





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
