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

using namespace std;

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
    Movie* newMovie = nullptr;
    Customer* newCustomer;

    while (!comFile.eof())
    {
        comFile >> commandType;

        switch (commandType)
        {
            case 'B': // Borrow Movie
            {
                //TODO: error checking

                Borrow* newBorrow = new Borrow;
                newBorrow->SetRental(newMedia, newMovie, newCustomer);

                comQueue.push(*newBorrow);

                // TODO: newMovie->updateStock(1);

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
                newHistory->SetRental(newMedia, newMovie, newCustomer);

                comQueue.push(*newHistory);

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
