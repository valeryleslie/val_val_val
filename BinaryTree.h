/* *~*~*
Binary Tree Abstract Class Header File
This class contains the common functions in binary trees.
This class also holds the 'printing' traversal functions
i.e. inorder and indented tree
Written by: Valery Leslie Tanada
IDE: Xcode
*~**/
#ifndef _BINARY_TREE
#define _BINARY_TREE

#include "BinaryNode.h"

template<class ItemType>
class BinaryTree
{
protected:
    BinaryNode<ItemType>* rootPtr;        // Ptr to root node
    int count;                            // Number of nodes in tree

public:
    // "admin" functions
    BinaryTree() {rootPtr = 0; count = 0;}
    BinaryTree(const BinaryTree<ItemType> & tree){ }
    virtual ~BinaryTree() { destroyTree(rootPtr); }
   
    // common functions for all binary trees
    bool isEmpty() const    {return count == 0;}
    int getCount() const {return count;}
    void clear()            {destroyTree(rootPtr); rootPtr = 0; count = 0;}
    void inOrder(void visit(ItemType &)) const  {_inorder(visit, rootPtr);}
    void printTree(void visit(ItemType &, int)) const{_printTree(visit, rootPtr, 1);}

    // abstract functions to be implemented by derived class
    virtual bool insert(string ct, ItemType* &ptr) = 0;
    virtual bool remove (ItemType &item) = 0;

private:
    // delete all nodes from the tree
    void destroyTree(BinaryNode<ItemType>* nodePtr);

    // internal traverse
    void _inorder(void visit(ItemType &), BinaryNode<ItemType>* nodePtr) const;
    void _printTree(void visit(ItemType &, int), BinaryNode<ItemType>* nodePtr, int level) const;
};

//Destroy the entire tree
template<class ItemType>
void BinaryTree<ItemType>::destroyTree(BinaryNode<ItemType>* nodePtr)
{
    if(nodePtr) // != NULL
    {
        destroyTree(nodePtr->getLeftPtr());
        destroyTree(nodePtr->getRightPtr());
        delete nodePtr;
    }
}

//Inorder Traversal – listing by primary and secondary key is similar for this program
template<class ItemType>
void BinaryTree<ItemType>::_inorder(void visit(ItemType &), BinaryNode<ItemType>* nodePtr) const
{
    if (nodePtr) // != NULL
    {
        ItemType item = *(nodePtr->getPtr()); // dereferencing the pointer variable of the node to get the County object
        _inorder(visit, nodePtr->getLeftPtr());
        visit(item);
        _inorder(visit, nodePtr->getRightPtr());
    }
}

//Prints tree as an indented list
template<class ItemType>
void BinaryTree<ItemType>::_printTree(void visit(ItemType &, int), BinaryNode<ItemType>* nodePtr, int level) const
{
    if (nodePtr) // != NULL
    {
        ItemType item = *(nodePtr->getPtr()); // dereferencing the pointer variable of the node to get the County object
        visit(item, level);
        level += 1;
        _printTree(visit, nodePtr->getRightPtr(), level);
        _printTree(visit, nodePtr->getLeftPtr(), level);
    }
}

#endif


