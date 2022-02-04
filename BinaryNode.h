/* *~*~*
Binary Node Class Header File
This class holds the Binary Search Tree's Nodes
Each node holds: the secondary key (in this case, the county name)
and the pointer to the County object with such key
Written by: Valery Leslie Tanada
IDE: Xcode
*~**/

#ifndef _BINARY_NODE
#define _BINARY_NODE

#include<string>
using std::string;

template<class ItemType>
class BinaryNode
{
private:
    string key;                            // Secondary key of the County object
    ItemType *ptr;                         // Pointer to County object
    BinaryNode<ItemType>* leftPtr;         // Pointer to left child
    BinaryNode<ItemType>* rightPtr;        // Pointer to right child

public:
    // constructors
    BinaryNode(string c, ItemType *p) {key = c; ptr = p; leftPtr = 0; rightPtr = 0;}
    BinaryNode(string c, ItemType *p,
               BinaryNode<ItemType>* left,
               BinaryNode<ItemType>* right) {key = c; ptr = p; leftPtr = left; rightPtr = right;}
    
    // setters
    void setKey(string k) {key = k;}
    void setPtr(ItemType *pt) {ptr = pt;}
    void setLeftPtr(BinaryNode<ItemType>* left) {leftPtr = left;}
    void setRightPtr(BinaryNode<ItemType>* right) {rightPtr = right;}
    
    // getters
    string getKey() const {return key;}
    ItemType* getPtr() const  {return ptr;}
    BinaryNode<ItemType>* getLeftPtr() const  {return leftPtr;}
    BinaryNode<ItemType>* getRightPtr() const {return rightPtr;}
};

#endif
