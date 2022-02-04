/* *~*~*
Binary Search Tree ADT
This class holds the Binary Search Tree's Nodes
Each node holds: the secondary key (in this case, the county name)
and the pointer to the County object with such key
Contains insert, remove, and search functions which are
called upon in main
Written by: Valery Leslie Tanada
IDE: Xcode
*~**/
 
#ifndef _BINARY_SEARCH_TREE
#define _BINARY_SEARCH_TREE

#include "BinaryTree.h"

#include <string>
using std::string;

template<class ItemType>
class BinarySearchTree : public BinaryTree<ItemType>
{
public:
    // insert a node at the correct location
    bool insert(string ct, ItemType* &ptr);
    // remove a node if found
    bool remove (ItemType &item);
    // find a target node using primary key
    bool search(const ItemType &target, ItemType &returnedItem);
    
private:
    // internal insert node: insert newNode in nodePtr subtree
    BinaryNode<ItemType>* _insert(BinaryNode<ItemType>* nodePtr, BinaryNode<ItemType>* newNode);
    // delete target node from tree, called by internal remove node
    bool _remove(BinaryNode<ItemType>* root, BinaryNode<ItemType>* nodePtr, BinaryNode<ItemType>* parent);
    // search for target node
    BinaryNode<ItemType>* _search(BinaryNode<ItemType>* nodePtr, BinaryNode<ItemType>* &parent, const ItemType &target);
   
};


///////////////////////// public function definitions ///////////////////////////
//Wrapper for _insert - Inserting items within a tree
template<class ItemType>
bool BinarySearchTree<ItemType>::insert(string ct, ItemType* &ptr)
{
    BinaryNode<ItemType>* newNodePtr = new BinaryNode<ItemType>(ct, ptr);
    this->rootPtr = _insert(this->rootPtr, newNodePtr);
    return true;
}

//Wrapper for _remove
// - it calls the private _remove function that returns a Node pointer or NULL
//   via the output parameter, and returns true, otherwise it returns false.
// -it searches for the target node and immediately returns false when node is not
// found
template<class ItemType>
bool BinarySearchTree<ItemType>::remove (ItemType &item) 
{
    BinaryNode<ItemType>* parent = NULL;
    BinaryNode<ItemType>* rem;
    rem = _search(this->rootPtr, parent, item);
   return _remove(this->rootPtr, rem, parent);
}

//Wrapper for _search (primary key search function)
// - it calls the private _search function that returns a Node pointer or NULL
// - if found, it copies data from that node and copies it to the return parameter
//   and returns true;
template<class ItemType>
bool BinarySearchTree<ItemType>::search(const ItemType& anEntry, ItemType &returnedItem)
{
    BinaryNode<ItemType>* temp = nullptr;
    temp = _search(this->rootPtr, this->rootPtr, anEntry);
    if (temp)
    {
        returnedItem = *(temp->getPtr()) ;
        return true;
    }
    return false;
}

//////////////////////////// private functions ////////////////////////////////////////////

//Implementation of the insert operation
template<class ItemType>
BinaryNode<ItemType>* BinarySearchTree<ItemType>::_insert(BinaryNode<ItemType>* nodePtr,
                                                          BinaryNode<ItemType>* newNodePtr)
{
    BinaryNode<ItemType>* pWalk = nodePtr;
    
    if (!nodePtr) // == NULL
    {
        nodePtr = newNodePtr;
        return nodePtr;
    }
    else if (pWalk && *(pWalk->getPtr()) > *(newNodePtr->getPtr()))
        pWalk->setLeftPtr( _insert(pWalk->getLeftPtr(), newNodePtr) );
    else if (pWalk && *(pWalk->getPtr()) < *(newNodePtr->getPtr()))
        pWalk->setRightPtr( _insert(pWalk->getRightPtr(), newNodePtr) );
    
    return nodePtr;
}

//Implementation for the remove operation
// - return false if tree is empty, returns true otherwise
// - accepts the to-be removed node as well as its parents
template<class ItemType>
bool BinarySearchTree<ItemType>::_remove(BinaryNode<ItemType>* root, BinaryNode<ItemType>* nodePtr, BinaryNode<ItemType>* parent)
{
    
    if (nodePtr == NULL)
        return false;
    
    // Internal nod with 2 children
    if (nodePtr->getLeftPtr() && nodePtr->getRightPtr())
    {
        BinaryNode<ItemType>* child = nodePtr->getRightPtr();
        BinaryNode<ItemType>* childPar = nodePtr;
        while (child->getLeftPtr())
        {
            childPar = child;
            child = child->getLeftPtr();
        }
        nodePtr->setPtr(child->getPtr());
        _remove(root, child, childPar);
    }
    // Root node with 1 or 0 children
    else if (nodePtr == root)
    {
        if (nodePtr->getLeftPtr())
            root = nodePtr->getLeftPtr();
        else
            root = nodePtr->getRightPtr();
    }
    // Internal node with left child only
    else if (nodePtr->getLeftPtr())
    {
        if (parent->getLeftPtr() == nodePtr)
            parent->setLeftPtr(nodePtr->getLeftPtr());
        else
            parent->setRightPtr(nodePtr->getLeftPtr());
    }
    // Internal node with right child only or a leaf node
    else
    {
        if (parent->getLeftPtr() == nodePtr)
            parent->setLeftPtr(nodePtr->getRightPtr());
        else
            parent->setRightPtr(nodePtr->getRightPtr());
    }
    
    return true;
}

//Implementation for the search operation
// - return NULL if target not found, otherwise
// - returns a pointer to the node that matched the target
// - accepts a 'parent' pointer specifically for the remove
// - function's use as it needs a parent node
template<class ItemType>
BinaryNode<ItemType>* BinarySearchTree<ItemType>::_search(BinaryNode<ItemType>* nodePtr, BinaryNode<ItemType>* &parent, const ItemType &target)
{
     BinaryNode<ItemType>* found = nullptr;
    
    if (nodePtr && *(nodePtr->getPtr()) == target)
    {
        found = nodePtr;
    }
    else if (nodePtr && *(nodePtr->getPtr()) > target)
    {
        parent = nodePtr;
        return _search(nodePtr->getLeftPtr(), parent, target);
    }
    else if (nodePtr && *(nodePtr->getPtr()) < target)
    {
        parent = nodePtr;
        return _search(nodePtr->getRightPtr(), parent, target);
    }
    
    return found;
}

#endif
