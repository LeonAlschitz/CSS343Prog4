//
// Created by tglaw on 8/15/2019.
//

#include "CustomerHash.h"
#include "Customer.h"
#include <sstream>

CustomerHash::CustomerHash()
{
    for(int i = 0; i < TABLESIZE; i++)
    {
        this->hashTable[i].cust = nullptr;
        this->hashTable[i].next = nullptr;
    }
}

CustomerHash::~CustomerHash()
{
    CustomerHashNode* temp;

    for(int i = 0; i < TABLESIZE; i++) //TODO: verify no memory leaks
    {
        if(this->hashTable[i].cust != nullptr)
        {
            while(this->hashTable[i].next != nullptr)
            {
                temp = &this->hashTable[i];
                delete this->hashTable[i].cust;
                this->hashTable[i].cust = nullptr;

                delete this->hashTable[i].next;
                this->hashTable[i].next = nullptr;
                temp = temp->next;
            }
        }
    }
}

/////     KEY == CUSTOMER ID NUMBER

Customer *CustomerHash::getCustomer(int key)//TODO parameter incomplete for linked list verification
{
    int index = (key % TABLESIZE);

    CustomerHashNode* trace = &hashTable[index];

    while(trace->cust != nullptr)
    {
        if(trace->cust->getID() == key)
        {
            return trace->cust;
        }

        trace = trace->next;
    }

    cout << "No Customer by that identification" << endl;

    return nullptr;
}



void CustomerHash::addCustomer(Customer *newCustomer)
{
    CustomerHashNode* temp = &hashTable[CustomerHashGenerator(newCustomer)];

    if(temp->cust != nullptr)
    {
        while(temp->next != nullptr)
        {
            temp = temp->next;
        }
    }

    temp->cust = newCustomer;

}

void CustomerHash::loadCustomers(std::ifstream &inFile)
{
    while (!inFile.eof())
    {
        Customer newCustomer(inFile);

        CustomerHashNode newNode;

        newNode.cust = &newCustomer;
    }

}

void CustomerHash::displayCustomers()
{
    for(int i = 0; i < TABLESIZE; i++)
    {
        if(this->hashTable[i].cust != nullptr)
        {
            do
            {
                cout << hashTable[i].cust->getID() << " " << hashTable[i].cust->getLastName() << " " <<  hashTable[i].cust->getFirstName() << endl;
            }
            while(this->hashTable[i].next != nullptr);
        }
    }
}

int CustomerHash::CustomerHashGenerator(const Customer *CustomerHashCust) const
{
    int newCustomerHash = (CustomerHashCust->getID() % TABLESIZE);

    return newCustomerHash;
}

CustomerHash::CustomerHashNode::CustomerHashNode()
{
    this->cust = nullptr;
    this->next = nullptr;
}

CustomerHash::CustomerHashNode::~CustomerHashNode()
{
    this->cust = nullptr;
    this->next = nullptr;
    delete this;
}
