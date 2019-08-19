#include <iostream>
#include "AVLTree.h"
#include "NodeData.h"

int main()
{

    AVLTree *aTree = new AVLTree();

    aTree->insertNode("C, 20, Lora Ephron, Found the Mail, The Actor 2004");
    aTree->insertNode("C, 20, Lora Ephron, Found the Mail, The Actor 2003");
    aTree->insertNode("D, 15, Bora Ephron, Missing Mail, 2002");

    aTree->insertNode("F, 10, Nora Ephron, You've Got Mail, 1998");
    aTree->insertNode("F, 10, Nora Ephron, You've Got Mail, 1997");
    aTree->insertNode("F, 10, Nora Ephron, You've Got Mail, 1997");

    aTree->insertNode("D, 15, Bora Ephron, Missing Mail, 2001");


    aTree->printGenre('D');
    aTree->printInventory();

    NodeData *testNode = new NodeData("10, Nora Ephron, You've Got Mail, 1998", 'F');
    cout << *testNode;
    NodeData *testNode2 = new NodeData("15, Bora Ephron, Missing Mail, 2002", 'D');
    cout << *testNode2;

    NodeData *testNode3 = new NodeData("20, Lora Ephron, Found the Mail, The Actor 2004", 'C');
    cout << *testNode3;

    NodeData *testNode4 = new NodeData("15, Bora Ephron, Missing Mail, 2002", 'D');
    cout << *testNode4;

    if(*testNode4 == *testNode2)
    {
        cout << "passed";
    }


    return 0;
}