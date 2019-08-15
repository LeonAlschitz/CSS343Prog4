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
	vector<char> validGenres = {'F'};

	public:

	//Description: This creates a new AVLTree
	//Preconditions: This object is un-initialized
	//Postconditions: This Object is initialized
	AVLTree();

	//Description: This destroys the AVLTree
	//Preconditions: This Object is initialized
	//Postconditions: This Object is un-initialized
	~AVLTree();

	//Description: This makes the NodeData object a child of a different node
	//Preconditions: This Object is initialized
	//Postconditions: The AVLTree will have one more node in the tree
	void insertNode(NodeData*);

	//Description: This creates a new NodeData object using the newInput, and then calls insertNode(NodeData*), and then balances the tree
	//Preconditions: The String has a valid movie type, as well as a non-negative stock amount.
	//Postconditions: The AVLTree will have one more node in the tree
	void insertNode(string newInput)
	{
		int curr = 0;

		int count = 0;

		while(curr <= newInput.length())
		{
			string temp = "";
			if(curr == 0)
			{
				temp = newInput.substr(curr, 1);
			}

			if(newInput.substr(curr, 1) == ",")
			{
				count++;
			}
			if(count == 2)
			{

				return;
			}

			curr++;
		}
	}

	//Description: Checks the balance of the AVLTree, and calls rebalanceTree if nessecary
	//Preconditions: A newNode has just been inserted
	//Postconditions: The AVLTree is balanced
	bool checkBalance();

	//Description: Finds the highest unbalanced node, then balances the AVLtree
	//Preconditions: The AVLTree isn't balanced
	//Postconditions: The AVLTree is balanced
	void rebalanceTree();

	//Description: Rempoves all of the nodes from the AVLTree
	//Preconditions: There is at least one node, in the AVLTree.
	//Postconditions: There are no more nodes in the AVLTree, and the head is pointing to NULL
	bool clearTree();


	//Description: This will reduce the stock of a Node by a given amount
	//Preconditions: The NodeData exists, and has enough stock
	//Postconditions: The NodeData loses some stock
	 bool reduceStock(NodeData*, int amount);

	//Description: This prints out all of the Nodes from a given Genre
	//Preconditions: The char is of a valid Genre type
	//Postconditions: The Genre's is printed out inorder
	void printGenre(char);

	//Description: This prints out all of the genres inventory inorder, because it is all sorted inorder
	//Preconditions: There is at least one NodeData in the AVLTree
	//Postconditions: The whole inventory is print in order of genre, and is sorted according to each genres internal order.
	void printInventory();
};



#endif