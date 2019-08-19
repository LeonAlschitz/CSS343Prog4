//
// Created by tglaw on 8/15/2019.
//

#include "CustomerHash.h"
#include "Customer.h"
#include <sstream>


// ------------------------------CustomerHash-------------------------------
// Description: this creates an unfilled CustomerHash
// preconditions: *this is a totally un-initialized CustomerHash
// postconditions: The fields of *this will be initialized, and the
//                 CustomerHash will contain default values for its data
// ---------------------------------------------------------------------

CustomerHash::CustomerHash()
{
    for(int i = 0; i < TABLESIZE; i++)
    {
        this->hashTable[i].cust = nullptr;
        this->hashTable[i].next = nullptr;
    }
}


// ------------------------------~CustomerHash-------------------------------
// Description: destroys and decomposes CustomerHash memory, as-needed
// preconditions: *this is in any valid state
// postconditions: all dynamically allocated memory is freed, and the
//                 CustomerHash is in a deletable state
// ---------------------------------------------------------------------

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


// ------------------------------getCustomer-------------------------------
// Description: gets the Customer with the customerID key
// preconditions: *this has already been initialized
// postconditions: nothing; just grants access to the Customer object
// @return a pointer to THE Customer object in the CustomerHash table
// ---------------------------------------------------------------------

Customer *CustomerHash::getCustomer(int key)//KEY == CUSTOMER ID NUMBER
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


// -----------------------------addCustomer-----------------------------
// Description: adds a customer object into the CustomerHash table
// preconditions: *this has already been initialized
// postconditions: a pointer to THE Customer object will be stored
// @param newCustomer is the new Customer
// ---------------------------------------------------------------------

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


// --------------------------loadCustomers---------------------------
// Description: builds up CustomerHash by reading from a data file.
// preconditions: *this has already been initialized
// postconditions: The file will have been read, and the CustomerHash
//                 built in memory
//@param input is the ifstream object of the file
// ---------------------------------------------------------------------

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


// --------------------------displayCustomers---------------------------
// Description: uses couts to display the Customers
// preconditions: *this has already been initialized, & has valid state
// postconditions: data of the CustomerHash will have been put to cout
// ---------------------------------------------------------------------

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


// ------------------------CustomerHashGenerator------------------------
// Description: generate CustomerHash value to use as a storage address
// preconditions: *this is initialized, & Customer* is valid
// postconditions: nothing is changed
// @param CustomerHashCust is the Customer to generate has for
// @return int of CustomerHash address to store at in the CustomerHash
//             table array hashTable
// ---------------------------------------------------------------------

int CustomerHash::CustomerHashGenerator(const Customer *CustomerHashCust) const
{
    int newCustomerHash = (CustomerHashCust->getID() % TABLESIZE);

    return newCustomerHash;
}


// -----------------------CustomerHashNode--------------------------
// Description: constructor, so the heap can mange these
// preconditions: *this is a totally un-initialized CustomerHashNode
// postconditions: The fields of *this will be initialized, and
//                 will contain:
//                 * cust = nullptr
//                 * next = nullptr
// -----------------------------------------------------------------

CustomerHash::CustomerHashNode::CustomerHashNode()
{
    this->cust = nullptr;
    this->next = nullptr;
}


// -----------------------~CustomerHashNode-------------------------
// Description: destructor, so the heap can mange these
// preconditions: *this is a CustomerHashNode of any valid state
// postconditions: all dynamically allocated memory is freed, and
//                 the CustomerHashNode is in a deletable state
// -----------------------------------------------------------------

CustomerHash::CustomerHashNode::~CustomerHashNode()
{
    this->cust = nullptr;
    this->next = nullptr;
    //delete this;
}
