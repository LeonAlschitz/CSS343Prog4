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

    if(temp->cust == nullptr) //first item in table
    {
        temp->cust = newCustomer;
        return;
    }
    else // collision with open hashing
    {
        while(temp->next != nullptr)
        {
            temp = temp->next;
        }
    }

    CustomerHashNode* newNode = new CustomerHashNode;

    temp->next = newNode;
    temp->next->cust = newCustomer;

}

void CustomerHash::loadCustomers(std::ifstream &inFile)
{
    while (!inFile.eof())
    {
        Customer* newCustomer = new Customer();
        newCustomer->setCustomerInfo(inFile);
        //Customer newCustomer(inFile);

        if(inFile.eof())
        {
            delete newCustomer;
            newCustomer = nullptr;
            break;
        }

        addCustomer(newCustomer);

        //delete newCustomer;
        //newCustomer = nullptr;
    }

}

void CustomerHash::displayCustomers()
{

    for(int i = 0; i < TABLESIZE; i++)
    {
        CustomerHashNode* tracer = &this->hashTable[i];

        while((nullptr != tracer) && (nullptr != tracer->cust))
        {
            cout <<tracer->cust->getID() << " " << tracer->cust->getLastName() << " " <<  tracer->cust->getFirstName() << endl;
            tracer = tracer->next;
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
    //delete this;
}
