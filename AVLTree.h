#ifndef AVLTREE_H
#define AVLTREE_H

#include <string>
#include <vector>

#include "NodeData.h"
using namespace std;

class AVLTree
{
	private:
	NodeData* head = NULL;
	vector<char> validGenres = {'F', 'C', 'D'};

	NodeData* parent = NULL;
	NodeData* unbalancedNode = NULL;

	NodeData* childOne = NULL;
	NodeData* childTwo = NULL;
	int childOneValue = 0;


	public:

	//Description: This creates a new AVLTree
	//Preconditions: This object is un-initialized
	//Postconditions: This Object is initialized
	AVLTree(){};

	//Description: This destroys the AVLTree
	//Preconditions: This Object is initialized
	//Postconditions: This Object is un-initialized
	~AVLTree()
	{
		clearTree();
	};

	//Description: This makes the NodeData object a child of a different node
	//Preconditions: This Object is initialized
	//Postconditions: The AVLTree will have one more node in the tree
	void insertNode(NodeData* newNode, NodeData* curr)
	{
		if(curr == NULL)
		{
			curr = newNode;
			return;
		}

		char newMovieType = newNode->getMovie()->getMovieType();
		char currMovieType = curr->getMovie()->getMovieType();

		if(newMovieType == currMovieType)
		{
			if(*curr == *newNode)
			{
				curr->getMovie()->updateStock(newNode->getMovie()->getStock());
				cout << "Item already existed, stock updated" << endl;
				return;
			}
			else
			{
				if(*curr < *newNode)
				{
					if(curr->getRight() == NULL)
					{
						curr->setRight(newNode);
						return;
					}
					insertNode(newNode, curr->getRight());
				}
				else
				{
					if(curr->getLeft() == NULL)
					{
						curr->setLeft(newNode);
						return;
					}
					insertNode(newNode, curr->getLeft());
				}
			}
		}
		else
		{
			if(newMovieType < currMovieType)
			{
				if(curr->getRight() == NULL)
				{
					curr->setRight(newNode);
					return;
				}
				insertNode(newNode, curr->getRight());
			}
			else
			{
				if(curr->getLeft() == NULL)
				{
					curr->setLeft(newNode);
					return;
				}
				insertNode(newNode, curr->getLeft());
			}
		}
	}

	//Description: This creates a new NodeData object using the newInput, and then calls insertNode(NodeData*), and then balances the tree
	//Preconditions: The String has a valid movie type, as well as a non-negative stock amount.
	//Postconditions: The AVLTree will have one more node in the tree
	void insertNode(string newInput)
	{
		int curr = 0;
		int count = 0;

        char temp;
        if(curr == 0)temp = newInput.at(curr);

        bool valid = false;
        for(int i = 0; i < validGenres.size(); i++)
        {
            if(temp == validGenres.at(i))
            {
                valid = true;
                break;
            }
        }


        if (!valid)
        {
            cout << "The movie genre isn't recognized, input ignored" << endl;
            return;
        }
        NodeData* newNode = new NodeData( newInput.substr(3, newInput.length() - 3) , temp);
        //cout << *newNode;

        if(head == NULL)
		{
        	head = newNode;
        	return;
		}

		insertNode( newNode, head);

        checkBalance();
	}


	//Description: Checks the balance of the AVLTree, and calls rebalanceTree if nessecary
	//Preconditions: A newNode has just been inserted
	//Postconditions: The AVLTree is balanced
	void checkBalance()
	{
		if(head == NULL)
		{
			cout << "There isn't anything to balance" << endl;
			return;
		}


		checkBalance(head);
		if(unbalancedNode != NULL)rebalanceTree();
		unbalancedNode = NULL;


	}

	int checkBalance(NodeData *curr)
	{
		int leftValue = 0;
		int rightValue = 0;

		if(unbalancedNode != NULL && parent == NULL) parent = curr;
		if(curr->getLeft() != NULL)leftValue += checkBalance(curr->getLeft());
		if(unbalancedNode != NULL && parent == NULL) parent = curr;
		if(curr->getRight() != NULL)rightValue += checkBalance(curr->getRight());

		if(unbalancedNode != NULL && parent == NULL) parent = curr;
		if(max(leftValue, rightValue) - min(leftValue, rightValue) >  1 && unbalancedNode == NULL)unbalancedNode = curr;



		return max(leftValue, rightValue) + 1;
	}

	//Description: Finds the highest unbalanced node, then balances the AVLtree
	//Preconditions: The AVLTree isn't balanced
	//Postconditions: The AVLTree is balanced
	void rebalanceTree()
	{
		getChildren(unbalancedNode);

		/*if(parent != NULL)
		{
			cout << "The parent of the unbalanced Node is: ";
			cout << *parent;
		}

		cout << "The unbalanced Node is:               ";
		cout << *unbalancedNode;

		cout << "First child is:                       ";
		cout << *childOne;
		cout << "Second child is:                      ";
		cout << *childTwo;
		cout << endl;*/

		//left is false, right is True
		bool leftRightOne;
		bool leftRightTwo;

		if((unbalancedNode->getLeft()) != NULL)
		{
			if(*(unbalancedNode->getLeft()) == *childOne) leftRightOne = false;
			else leftRightOne = true;
		}
		else leftRightOne = true;

		if(childOne->getLeft() != NULL)
		{
			if(*(childOne->getLeft()) == *childTwo) leftRightTwo = false;
			else leftRightTwo = true;
		}
		else leftRightTwo = true;

		if(!leftRightOne && !leftRightTwo)leftLeft(childOne, childTwo);
		else if(leftRightOne && leftRightTwo) rightRight(childOne, childTwo);
		else if(!leftRightOne && leftRightTwo) leftRight(childOne, childTwo);
		else if(leftRightOne && !leftRightTwo) rightLeft(childOne, childTwo);



		parent = NULL;
		unbalancedNode = NULL;
		childOne = NULL;
		childTwo = NULL;
		childOneValue = 0;
	}

	int getChildren(NodeData *curr)
	{
		int leftValue = 0;
		int rightValue = 0;

		if(curr->getLeft() != NULL)leftValue += getChildren(curr->getLeft());
		if(curr->getRight() != NULL)rightValue += getChildren(curr->getRight());


		if(childOne == NULL) childTwo = curr;

		if(max(leftValue, rightValue) >  childOneValue)
		{
			if(childOne != NULL)childTwo = childOne;

			if(leftValue > rightValue)childOne = curr->getLeft();
			else childOne = curr->getRight();

			childOneValue = max(leftValue, rightValue);
		}

		return max(leftValue, rightValue) + 1;
	}

	void leftLeft(NodeData *leftChildOne, NodeData *leftChildTwo)
	{
		//cout << "left left" << endl;
		if(parent == NULL)
		{
			unbalancedNode->setLeft(leftChildOne->getRight());
			leftChildOne->setRight(unbalancedNode);
			head = leftChildOne;
		}
		else
		{
			//is the unbalanced the left or right child of the parent
			//left is false, right is true
			bool leftOrRight;
			if(parent->getLeft() == unbalancedNode) leftOrRight = false;
			else leftOrRight = true;

			unbalancedNode->setLeft(leftChildOne->getRight());
			leftChildOne->setRight(unbalancedNode);

			if(!leftOrRight) parent->setLeft(leftChildOne);
			else parent->setRight(leftChildOne);
		}
	}

	void rightRight(NodeData *rightChildOne, NodeData *rightChildTwo)
	{
		//cout << "right right" << endl;
		if(parent == NULL)
		{
			unbalancedNode->setRight(rightChildOne->getLeft());
			rightChildOne->setLeft(unbalancedNode);
			head = rightChildOne;
		}
		else
		{
			//is the unbalanced the left or right child of the parent
			//left is false, right is true
			bool leftOrRight;
			if(parent->getLeft() == unbalancedNode) leftOrRight = false;
			else leftOrRight = true;

			unbalancedNode->setRight(rightChildOne->getLeft());
			rightChildOne->setLeft(unbalancedNode);
			if(!leftOrRight) parent->setLeft(rightChildOne);
			else parent->setRight(rightChildOne);
		}
	}

	void rightLeft(NodeData *rightChildOne, NodeData *leftChildTwo)
	{
		//cout << "right left" << endl;
		if(parent == NULL)
		{
			rightChildOne->setLeft(leftChildTwo->getRight());
			unbalancedNode->setRight((leftChildTwo));
			leftChildTwo->setRight(rightChildOne);
		}
		else
		{
			//is the unbalanced the left or right child of the parent
			//left is false, right is true
			bool leftOrRight;
			if(parent->getLeft() == unbalancedNode) leftOrRight = false;
			else leftOrRight = true;

			rightChildOne->setLeft(leftChildTwo->getRight());
			unbalancedNode->setRight((leftChildTwo));
			leftChildTwo->setRight(rightChildOne);

			if(!leftOrRight) parent->setLeft(childOne);
			else parent->setRight(childOne);
		}

		rightRight(rightChildOne, leftChildTwo);
	}

	void leftRight(NodeData *leftChildOne, NodeData *rightChildTwo)
	{
		//cout << "left right" << endl;
		if(parent == NULL)
		{
			leftChildOne->setRight(rightChildTwo->getLeft());
			unbalancedNode->setLeft((rightChildTwo));
			rightChildTwo->setLeft(leftChildOne);
		}
		else
		{
			//is the unbalanced the left or right child of the parent
			//left is false, right is true
			bool leftOrRight;
			if(parent->getLeft() == unbalancedNode) leftOrRight = false;
			else leftOrRight = true;

			leftChildOne->setRight(rightChildTwo->getLeft());
			unbalancedNode->setLeft((rightChildTwo));
			rightChildTwo->setLeft(leftChildOne);

			if(!leftOrRight) parent->setLeft(childOne);
			else parent->setRight(childOne);
		}
		leftLeft(leftChildOne, rightChildTwo);
	}

	//Description: Rempoves all of the nodes from the AVLTree
	//Preconditions: There is at least one node, in the AVLTree.
	//Postconditions: There are no more nodes in the AVLTree, and the head is pointing to NULL
	void clearTree()
    {
        cout << "Clearing out the inventory...." << endl;
	    delete(head);
	    head = NULL;
	    cout << "Done! :D" << endl;
    }


	//Description: This will reduce the stock of a Node by a given amount
	//Preconditions: The NodeData exists, and has enough stock
	//Postconditions: The NodeData loses some stock
	 bool reduceStock(NodeData*, int amount);

	//Description: This prints out all of the Nodes from a given Genre
	//Preconditions: The char is of a valid Genre type
	//Postconditions: The Genre's is printed out inorder
	void printGenre(char genre)
	{
		if(head == NULL)
		{
			cout << "There is nothing in the inventory." << endl;
			return;
		}
		printGenre(genre, head);
		cout << endl;
	}

	void printGenre(char genre, NodeData* curr)
	{
		if(curr->getLeft() != NULL) printGenre(genre, curr->getLeft());
		if(genre == curr->getMovie()->getMovieType())
		{
			cout << *curr;
		}
		if(curr->getRight() != NULL) printGenre(genre, curr->getRight());
	}

	//Description: This prints out all of the genres inventory inorder, because it is all sorted inorder
	//Preconditions: There is at least one NodeData in the AVLTree
	//Postconditions: The whole inventory is print in order of genre, and is sorted according to each genres internal order.
	void printInventory()
	{
		cout << "Attempting to print out the inventory" << endl;
		if(head == NULL)
		{
			cout << "You have no data in your inventory!" << endl;
			return;
		}
		cout << "-----------------------------------" << endl;
		cout << "Printing out the full inventory...." << endl;
		cout << "root = the head, 0 = left child, 1 = right child" << endl;
		printInventory(head, "root ");
		cout << "-----------------------------------" << endl;
	}

	void printInventory(NodeData* curr, string path)
	{
		if(curr->getLeft() != NULL)printInventory(curr->getLeft(), path + "0");
		cout << "-------" << endl;
		cout << "The path: " + path << endl;
		cout << *curr;


		if(curr->getRight() != NULL)printInventory(curr->getRight(), path + "1");
	}

	NodeData* getMovie(string theData)
	{
		string newData = theData.substr(3, theData.length() - 3);
		char type = theData.at(0);
		NodeData *newNode = new NodeData(newData, type);
		return getMovie(head, newNode);
	}

	NodeData* getMovie(NodeData* curr, NodeData* toCompare)
	{

		if(*curr == *toCompare)return curr;

		if(toCompare->getMovie()->getMovieType() == curr->getMovie()->getMovieType())
		{
			if(*toCompare < *curr && curr->getRight() != NULL) return getMovie( curr->getRight(), toCompare);
			else if(curr->getLeft() != NULL) return getMovie( curr->getLeft(), toCompare);
		}
		else
		{
			if(toCompare->getMovie()->getMovieType() < curr->getMovie()->getMovieType() && curr->getRight() != NULL)return getMovie(curr->getRight(), toCompare);
			else if (curr->getLeft() != NULL) return getMovie(curr->getLeft(), toCompare);
		}
		return NULL;

	}

};



#endif