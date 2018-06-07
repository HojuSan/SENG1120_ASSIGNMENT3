/*
Name:           Juyong Kim
Subject:        SENG1120
Task:           Assignment 3
Hopes:          Passing this course
Dreams:         Crushed
Social Life:    Non Existent 
*/
//Macro Guards
#ifndef BSTREE_H
#define BSTREE_H

//Libraries
#include <iostream>
#include <cstdlib>
#include <string>
#include "BTNode.h"

//namespaces
using namespace std;
//templates
template <typename value_type>
//class definition
class BSTree
{
    //public functions
    public:

    BSTree();
    //Description:		
    //Pre:				
    //Post:		
    		
    BSTree(value_type data);
    //Description:		
    //Pre:				
    //Post:		

    //deconstructor will lead to memory leaks!!!!!!!!!
    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    //FIX NOW  YA LAZY KUNT		
    //also check if bs tree ordering is done right.
    ~BSTree();
    //Description:		
    //Pre:				
    //Post:		
    		
    void add(value_type new_input);
    //Description:		
    //Pre:				
    //Post:		
    		
    //when you pass a literally value like an integer or a string instead of a stated variable like val1
    //you need to put a const in it
    void remove(const value_type& remove_input);
    //Description:		
    //Pre:				
    //Post:		
    		
    void print();
    //Description:		
    //Pre:				
    //Post:		
    		
    BTNode<value_type>* findMin(BTNode<value_type>* node);
    //Description:		
    //Pre:				
    //Post:		
    		
    //private functions/data values
    private:

    BTNode<value_type>* rootPtr;
    size_t size;

    void insert(BTNode<value_type>* node, value_type data);
    //Description:		
    //Pre:				
    //Post:		
    		
    int compareNodes(const value_type node1, const value_type node2);
    //Description:		
    //Pre:				
    //Post:		
    		
    void erase(BTNode<value_type>* node, const value_type& data);
    //Description:		
    //Pre:				
    //Post:		
    		
    void privatePrint(BTNode<value_type>* node);
    //Description:		
    //Pre:				
    //Post:		
    		


};

template <typename value_type>
ostream& operator << (ostream& out, BSTree<value_type>& list);
    //Description:		
    //Pre:				
    //Post:		

//including hpp file
#include "BSTree.hpp"
#endif