#include <iostream>
#include <math.h>
#include <cassert>
#include "supp.hpp"

int Item::childCount() const
{
    int count = -1;
    if (leftChild)
        ++count;
    
    if (rigthChild)
        ++count;
    
    return count;
};

Item*& Item::child(int index)
{
    // assert(0 <= index && index <= childCount());
    switch (index)
    {
    case 0:
        return leftChild;
    default:
        return rigthChild;
    }
}

void bTree::add(Item *&root, int index)
{
    if (!root)
        root = new Item(index);
    else
    {
        if (index <= root->getName()) 
            add(root->child(0), index); 
        else
            add(root->child(1), index);
    }
}

void bTree::addItem(int index)
{
    add(root, index);
}

void bTree::printItems1(Item *&root)
{
    if (root)
    {
        printItems1(root->child(0));
        std::cout << root->getName() << "\t";
        printItems1(root->child(1));
    }
}

void bTree::printItems2(Item *root)
{

}

 void bTree::printBTree()
 {
    printItems1(root);
 }