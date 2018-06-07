/*
Name:           Juyong Kim
Subject:        SENG1120
Task:           Assignment 3
Hopes:          Passing this course
Dreams:         Crushed
Social Life:    Non Existent 
*/
#include "BTNode.h"

//constructor
template<typename value_type>
BTNode<value_type>::BTNode(const value_type& intdata, BTNode<value_type>* intLchild, BTNode<value_type>* intRchild, BTNode<value_type>* intParent)
{
    data = intdata;                                     //sets data
    LChild = intLchild;                                 //sets left child
    RChild = intRchild;                                 //sets right child
    parent = intParent;                                 //sets parent node
}

//deconstructor
template<typename value_type>
BTNode<value_type>::~BTNode()
{
    LChild = NULL;                                      //sets left child to null
    RChild = NULL;                                      //sets right child to null 
    parent = NULL;                                      //sets parent to NULL
}

//sets data in node
template<typename value_type>
void BTNode<value_type>::set_data(const value_type newData)
{
    data = newData;                                     //sets data
}

//sets node as parent
template<typename value_type>
void BTNode<value_type>::set_parent(BTNode<value_type>* newParent)
{
    parent = newParent;                                 //sets parent
}

//sets node as left child
template<typename value_type>
void BTNode<value_type>::set_left_child(BTNode<value_type>* newLChild)
{
    LChild = newLChild;                                 //sets left child
}

//sets node as right child
template<typename value_type>
void BTNode<value_type>::set_right_child(BTNode<value_type>* newRChild)
{
    RChild = newRChild;                                 //sets right child
}

//checks if node is leaf child
template<typename value_type>
bool BTNode<value_type>::check_leaf_child() const
{
    return ((LChild == NULL) && (RChild == NULL));      //if there is no left or right child return true
}

//checks if node is left child
template<typename value_type>
bool BTNode<value_type>::check_left_child() const
{
    return (data < parent->get_data());                 //if parent data is more than the current data return true
}

//checks if node is right child
template<typename value_type>
bool BTNode<value_type>::check_right_child() const
{
    return (data > parent->get_data());                 //if parent data is less than the current data return true
}

//checks if bs tree has only one node
template<typename value_type>
bool BTNode<value_type>::check_one_child() const
{
    //if there is only one child node for either side then return true
    return	(((LChild == NULL) && (RChild != NULL)) || ((LChild != NULL) && (RChild == NULL)));		
}

//retrieves data from node
template<typename value_type>
value_type& BTNode<value_type>::get_data()
{
    return data;                                        //return data
}

//retrieves data from node
template<typename value_type>
const value_type& BTNode<value_type>::get_data() const
{
    return data;                                        //return data
}

//retrieves data from left child node
template<typename value_type>
BTNode<value_type>* BTNode<value_type>::get_left_child_data()
{
    return LChild;                                      //return left child data
}

//retrieve data from left child node
template<typename value_type>
const BTNode<value_type>* BTNode<value_type>::get_left_child_data() const
{
    return LChild;                                      //return left child data
}

//retrieves data from right child node
template<typename value_type>
BTNode<value_type>* BTNode<value_type>::get_right_child_data()
{
    return RChild;                                      //return right child data
}

//retrieve data from right child node
template<typename value_type>
const  BTNode<value_type>* BTNode<value_type>::get_right_child_data() const
{
    return RChild;                                      //return right child data
}

//retrieve data from parent node
template<typename value_type>
BTNode<value_type>* BTNode<value_type>::get_parent_data()
{
    return parent;                                      //return parent data
}

//retrieve data from parent node
template<typename value_type>
const  BTNode<value_type>* BTNode<value_type>::get_parent_data() const
{
    return parent;                                      //return parent data
}