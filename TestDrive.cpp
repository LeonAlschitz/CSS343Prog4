#include <iostream>
#include "Transaction.h"
#include "Borrow.h"
#include "History.h"
#include "Return.h"
#include "Customer.h"
#include "CustomerHash.h"

using namespace std;

class Movie
{
    int stock = 0;

    virtual void updateStock(int newStock){ stock += newStock;}


};

int main()
{

    cout << "********START OF TEST HARNESS********" << endl << endl;

    ifstream inFile("C:\\Users\\tglaw\\OneDrive\\Documents\\UW BOTHELL\\SUMMER 2019\\CSS 343\\Assignment 4\\implementation\\Lab 4\\data4customers.txt");

    if(!inFile)
    {
        cout << "File could not be opened." << endl;
        return 1;
    }

    CustomerHash testHash;

    testHash.loadCustomers(inFile);

    testHash.displayCustomers();

    History testH;

    Movie newMovie;

    // ************TRANSACTION TESTS**************



    cout << endl << "********END OF TEST HARNESS********" << endl;

    return 0;
}