//
// Created by tglaw on 8/15/2019.
//

#include "Customer.h"
#include <vector>
using namespace std;

Customer::Customer()
{
    customerID = 0;
    firstName = "";
    lastName = "";
}

Customer::Customer(stringstream &inFile)
{
    inFile >> customerID; //sets customer ID

    if(inFile.eof())
    {
        return; //end of file
    }

    inFile.get();
    inFile >> lastName; //sets last name

    inFile.get();
    inFile >> firstName; //sets first name
}

Customer::~Customer()
{}

int Customer::getID() const
{
    return customerID;
}

string Customer::getFirstName() const
{
    return firstName;
}

string Customer::getLastName() const
{
    return lastName;
}

void Customer::printHistory() const
{
    cout << "Customer ID: " << customerID << " Last Name: " << lastName << " First Name: " << firstName << endl;

    if(transHistory.size() > 0)
    {

        for (unsigned int i = 0; i < transHistory.size(); i++)
        {
            transHistory[i].display();
        }

        cout << "End of History" << endl;
    }
    else
    {
        cout << "No Customer History" << endl;
    }
}

void Customer::storeTransaction(Transaction &trans)
{
    transHistory.push_back(trans);
}


