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
#include <iostream>
#include <fstream>
#include <queue>
#include "Business.h"
#include "Borrow.h"
#include "Return.h"
#include "History.h"
#include "CustomerHash.h"
#include "Movie.h"
#include "AVLTree.h"
#include "Transaction.h"


Business::Business()
{
    tree = new AVLTree();
}

Business::~Business()
{
    delete(tree);
}

int main()
{
    Business *movieStore = new Business();
    cout << "Welcome user to Tim and Leon Program 4!" << endl;
    bool exitUserMenu = false;
    string userInput = "";

    movieStore->printMenu();
    while(!exitUserMenu)
    {
        userInput = "";
        cout << "----------------------------" << endl;
        cout << "Please enter a new command: ";
        getline(cin, userInput);

        if(userInput == "quit")
        {
            exitUserMenu = true;
        }
        else if(userInput == "menu")movieStore->printMenu();
        else if(userInput == "default")
        {
            ifstream movieFile("C:\\Users\\Leon\\Desktop\\CSS343Prog4\\data4Movies.txt");
            movieStore->loadMovies(movieFile);
            movieFile.close();
            movieStore->getTree()->printInventory();

            ifstream customerFile("C:\\Users\\Leon\\Desktop\\CSS343Prog4\\data4customers.txt");
            movieStore->loadCustomers(customerFile);
            customerFile.close();

            ifstream actionFile("C:\\Users\\Leon\\Desktop\\CSS343Prog4\\data4commands.txt");
            movieStore->loadCommands(actionFile);
            movieFile.close();

        }
        else if(userInput == "custom")
        {

        }
        else cout << "That input was invalid." << endl;


    }





    cout << "Goodbye! Thank you for running Tim and Leon's Program 4!" << endl;
    cout << "----------------------------" << endl;

    return 0;
}

void Business::printMenu()
{
    cout << "List of valid commands:" << endl;
    cout << "quit, to quit the program" << endl;
    cout << "menu, to re-print the menu" << endl;
    cout << "default, to take as input the starting homework txt's: data4commands.txt, data4customers.txt, data4movies.txt" << endl;
    cout << "custom, to enter custom inputs" << endl;
}

void Business::loadCustomers(std::ifstream &custFile)
{
    custTable.loadCustomers(custFile);
}

void Business::loadMovies(std::ifstream &movieFile)
{
    string input = "";
    while(!movieFile.eof())
    {
        getline(movieFile, input);
        if(input.length() < 2)return;

        tree->insertNode(input);
        input = "";
    }
}

//***********************************************************************
//Possibly remove comQueue as it seems un-needed and directly run commands

void Business::loadCommands(std::ifstream &comFile)
{
    char commandType;
    string newMedia;
    string movieData;// for searching the AVL tree
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

                if(nullptr == newCustomer) //no customer
                {
                    cout << endl << "There is no customer by the ID number: " << customerID <<endl << endl;
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

                          *** implementation below   ***

                */

                //possibly have a findMovie() method to search in your AVL tree
                //TODO: SET newMovie to AVLcomfile.get()     see bellow

                getline(comFile, movieData); ////TODO verify no errors in second run of Borrow
                tree->getMovie(movieData);





                if(newMovie->getStock() < 1) //TODO ERROR: SEGSEGV (segmentation fault) without newMovie assignment
                {
                    break; //TODO: print error message or offer alternate
                }


                Borrow* newBorrow = new Borrow;

                if(newBorrow->SetRental(newMedia, newMovie, newCustomer))
                {
                    newCustomer->storeTransaction(*newBorrow);
                    newCustomer->addToCustomerInventory(newMovie);

                    newMovie->updateStock(-1);
                }

                break;
            }

            case 'R': // Return Movie
            {
                //   TODO: error checking


                comFile.get();

                comFile >> customerID;
                newCustomer = custTable.getCustomer(customerID);

                if(nullptr == newCustomer) //no customer
                {
                    cout << endl << "There is no customer by the ID number: " << customerID <<endl << endl;
                    break;
                }

                /*

                if customer has item
                     add Return to customer vector
                    increase stock AVL by 1

                else
                          error message

                          *** implementation below   ***

                */


                //TODO: SET newMovie to AVLcomfile.get()

                getline(comFile, movieData); ////TODO verify no errors in second run of Borrow
                tree->getMovie(movieData);


                if(newMovie->getStock() < 1) //TODO ERROR: SEGSEGV (segmentation fault) without newMovie assignment
                {
                    break; //TODO: print error message or offer alternate
                }

                if(newCustomer->removeFromCustomerInventory(newMovie))
                {
                    Return* newReturn = new Return;

                    if(newReturn->SetRental(newMedia, newMovie, newCustomer))
                    {
                        newCustomer->storeTransaction(*newReturn);
                        newCustomer->addToCustomerInventory(newMovie);

                        newMovie->updateStock(1);
                    }
                }

                break;
            }

            case 'H': // Print customer history
            {
                //TODO: error checking

                History *newHistory = new History;

                comFile >> customerID;
                newCustomer = custTable.getCustomer(customerID);

                if(nullptr == newCustomer) //no customer
                {
                    cout << endl << "There is no customer by the ID number: " << customerID <<endl << endl;
                    break;
                }

                newHistory->SetRental(newMedia, newMovie, newCustomer); //prints customer history

                break;
            }

            case 'I':  // Print inventory
            {
                tree->printInventory();
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

void Business::displayBusiness()
{

    cout << "********* Inventory **********" << endl << endl;
    // Call displayMovies method;
    cout << endl << "***************************" << endl << endl;


    cout << "********* Customers **********" << endl << endl;
    custTable.displayCustomers();
    cout << endl << "***************************" << endl << endl;
}
