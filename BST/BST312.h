
/*  BST312.h
  CS 312 Fall 2018

  a simple implementation of a binary search tree


*/

#ifndef BST_312_H
#define BST_312_H

#include <cstdlib>  // Provides size_t
#include <iostream>
#include <vector>

using namespace std;
template<class ItemType>
class BST_312 {
public:

    BST_312();

    //Copy constructor
    BST_312(const BST_312 & src);

    ~BST_312();

/****************************
makeEmpty

Function: Removes all the items from the BST.
Preconditions: BST has been initialized
Postconditions: All the items have been removed
*****************************/
    void makeEmpty();

/****************************
isEmpty

Function: Checks to see if there are any items in the BST.
Preconditions: BST has been initialized
Postconditions: Returns true if there are no items in the BST, else false.
*****************************/
    bool isEmpty() const;

/****************************
isFull

Function: Determines if you have any more room to add items to the BST
Preconditions: BST has been initialized
Postconditions: Returns true if there is no more room to add items, else false
*****************************/
    bool isFull() const;

/****************************
insertItem

Function: Adds newItem to the BST.
Preconditions: BST has been initialized and is not full.
Postconditions: newItem is in the proper position for a BST.
*****************************/
    void insertItem(const ItemType &);

/****************************
deleteItem

Function: Removes target from BST.
Preconditions: BST has been initialized.
Postconditions: If found, element has been removed from BST.
*****************************/
    void deleteItem(const ItemType& newItem);

/****************************
countNodes

Function: Counts the number of nodes in the BST
Preconditions: BST has been initialized.
Postconditions: returns the number of nodes in the BST
*****************************/
    int countNodes();

/****************************
preOrderTraversal

Function: Returns the preOder (Node, Left, Right) as a vector of ItemTypes
Preconditions: BST has been initialized.
Postconditions: none
*****************************/
    vector<ItemType> preOrderTraversal();

/****************************
inOrderTraversal

Function: Returns the inOder (Left, Node, Right) as a vector of ItemTypes
Preconditions: BST has been initialized.
Postconditions: none
*****************************/
    vector<ItemType> inOrderTraversal();

/****************************
postOrderTraversal

Function: returns the postOder (Left, Right, Node) as a vector of ItemTypes
Preconditions: BST has been initialized.
Postconditions: none
*****************************/
    vector<ItemType> postOrderTraversal();

/********************
 isItemInTree

Function: Determines if a given Item is in tree.
Preconditions: BST has been initialized.
Postconditions: none
*****************************/

    bool isItemInTree(const ItemType& item);


private:
    struct TreeNode {
        ItemType data;
        TreeNode *left;
        TreeNode *right;
    };

    TreeNode * root;


    void insertItem(TreeNode*& t, const ItemType& newItem);
    void inOrderTraversal(TreeNode* t,vector<ItemType>& result) const;
    int countNodes(TreeNode* t) const;
    void deleteNode(TreeNode*& node);
    void makeEmpty(TreeNode*& t);
    void deleteItem(TreeNode*& t, const ItemType& newItem);
    void getPredecessor(TreeNode* t, ItemType& data);
    void preOrderTraversal(TreeNode* t,vector<ItemType>& result) const;
    void postOrderTraversal(TreeNode* t,vector<ItemType>& result) const;
    void copyTree(TreeNode*& copy, const TreeNode *originalTree);

};

/*******************************
//Function implementations
********************************/

template<class ItemType>
BST_312<ItemType>::BST_312 ()
{
    root = NULL;
}

template<class ItemType>
BST_312<ItemType>::BST_312(const BST_312 & src)
{
    copyTree(root, src.root);
}

template<class ItemType>
BST_312<ItemType>::~BST_312()
{
    makeEmpty();

}


template<class ItemType>
void BST_312<ItemType>::copyTree(TreeNode*& copy, const TreeNode* originalTree)
{
    if (originalTree == NULL)
        copy = NULL;
    else
    {
        copy = new TreeNode;
        copy->data = originalTree->data;

        copyTree(copy->left, originalTree->left);
        copyTree(copy->right, originalTree->right);
    }
}


template<class ItemType>
void BST_312 <ItemType>::deleteNode(TreeNode*& t)
{
    ItemType info;
    TreeNode *tempPtr;

    tempPtr = t;

    if (t->left == NULL)
    {
        t = t->right;
        delete tempPtr;
    }
    else if (t->right == NULL)
    {
        t = t->left;
        delete tempPtr;
    }
    else
    {
        getPredecessor(t->left, info);
        t->data = info;
        deleteItem(t->left, info);
    }
}



//find largest in left subtree
template<class ItemType>
void BST_312 <ItemType>::getPredecessor(TreeNode* t, ItemType& data)
{

    while (t->right != NULL)
        t = t->right;

    data = t->data;

}


template<class ItemType>
void BST_312 <ItemType>::deleteItem(TreeNode*& t, const ItemType& newItem)
{
    if (t == NULL)
        return;
    else if (newItem < t->data)
        deleteItem(t->left, newItem);
    else if (newItem > t->data)
        deleteItem(t->right, newItem);
    else
        deleteNode(t);
}


template<class ItemType>
void BST_312 <ItemType>::deleteItem(const ItemType& newItem)
{
    deleteItem(root, newItem);

}
//deletes recursively by calling left then right, and then deleting node using given function
template<class ItemType>
void BST_312 <ItemType>::makeEmpty(TreeNode*& t)
{
    if(t==NULL)
        return;
    if(t->left!=NULL)
        makeEmpty(t->left);
    if(t->right!=NULL)
        makeEmpty(t->right);
    deleteNode(t);
}

template<class ItemType>
void BST_312 <ItemType>::makeEmpty()
{
    makeEmpty(root);
    root = NULL;

}

template<class ItemType>
bool BST_312 <ItemType>::isEmpty() const
{
    return root == NULL;
}



template<class ItemType>
bool BST_312 <ItemType>::isFull() const
{
    try
    {
        TreeNode *temp = new TreeNode;
        delete temp;
        return false;
    }
    catch (std::bad_alloc)
    {
        return true;
    }

}

//inserts recursively by creating new node, recursive call to left and then to right (t modifies root)
template<class ItemType>
void BST_312 <ItemType>::insertItem(TreeNode*& t, const ItemType& newItem)
{
  if(!isFull()){
      if(t==NULL){
          TreeNode *n= new TreeNode;
          n->data=newItem;
          n->left=NULL;
          n->right=NULL;
          t=n;
      }
        else {
          if (t->data > newItem)
              insertItem(t->left, newItem);//t->left is null for the first call of every new branch
          if (t->data < newItem)
              insertItem(t->right, newItem);
      }
    }

}
//helper function to pass in root (which is modified by t)
template<class ItemType>
void BST_312 <ItemType>::insertItem(const ItemType& newItem)
{
    //YOUR CODE GOES HERE
    insertItem(this->root, newItem);
}


//counts nodes recursively. adds one for root and then adds left and right recrusively
template<class ItemType>
int BST_312 <ItemType>::countNodes(TreeNode* t) const
{
    //YOUR CODE GOES HERE
    int sum=0;
    if(t==NULL)
        return 0;
    else {
        if (t != NULL)
            sum=1;
        return sum + countNodes(t->left) + countNodes(t->right);
    }

}

//helper function that passes in root
template<class ItemType>
int BST_312 <ItemType>::countNodes()
{
    return countNodes(this->root);
}
//traverses recursively in preorder (data, left right) and stores result in result vector
template<class ItemType>
void BST_312 <ItemType>::preOrderTraversal(TreeNode* t,vector<ItemType>& result) const
{

    if(t!=NULL) {
        result.push_back(t->data);
        preOrderTraversal(t->left, result);
        preOrderTraversal(t->right, result);
    }else
        return;
}

//helper function that creates and returns result vector, also passes in root
template<class ItemType>
vector<ItemType> BST_312 <ItemType>::preOrderTraversal()
{
    vector<ItemType> result;
    preOrderTraversal(this->root, result);
    return result;
}
//traverses recursively in inorder (left, data, right) and stores result in result vector
template<class ItemType>
void BST_312 <ItemType>::inOrderTraversal(TreeNode* t,vector<ItemType>& result) const
{
    if(t!=NULL) {

        inOrderTraversal(t->left, result);
        result.push_back(t->data);
        inOrderTraversal(t->right, result);
    } else
        return;

}
//helper function that creates and returns result vector, also passes in root
template<class ItemType>
vector<ItemType> BST_312 <ItemType>::inOrderTraversal()
{
    vector<ItemType> result;
    inOrderTraversal(this->root, result);
    return result;
}
//traverses recursively in postorder (left, right, data) and stores result in result vector
template<class ItemType>
void BST_312 <ItemType>::postOrderTraversal(TreeNode* t,vector<ItemType>& result) const
{


    if(t!=NULL) {
        postOrderTraversal(t->left, result);
        postOrderTraversal(t->right, result);
        result.push_back(t->data);
    } else
        return;
}
//helper function that creates and returns result vector, also passes in root
template<class ItemType>
vector<ItemType> BST_312 <ItemType>::postOrderTraversal()
{
    vector<ItemType> result;
    postOrderTraversal(this->root, result);
    return result;
}
//iterates through result vector using inorder traversal and returns true of passed in item matches current it access value
template<class ItemType>
bool BST_312 <ItemType>::isItemInTree(const ItemType& item)
{

    //YOUR CODE GOES HERE
    vector<ItemType> vec;
    vec=inOrderTraversal();
    typename vector<ItemType>::iterator it;

    for(it=vec.begin(); it!=vec.end(); it++){
        if(vec[it]==item)
            return true;
    }
    return false;


};
#endif

