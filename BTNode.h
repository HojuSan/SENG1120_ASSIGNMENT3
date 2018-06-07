/*
Name:           Juyong Kim
Subject:        SENG1120
Task:           Assignment 3
Hopes:          Passing this course
Dreams:         Crushed
Social Life:    Non Existent 
*/
//Macro Guards
#ifndef BSNODE_H
#define BSNODE_H

//Libraries
#include <iostream>
#include <cstdlib>
#include <string>

//namespaces
using namespace std;
//templates
template <typename value_type>
//class definition
class BTNode
{
    //public functions
    public:

    BTNode(const value_type& intdata = value_type(), BTNode<value_type>* intLchild = NULL, BTNode<value_type>* intRchild = NULL, BTNode<value_type>* intparent = NULL);
    //Description:		creates a node
    //Pre:				
    //Post:		        creates a node with default parameters

    ~BTNode();
    //Description:		deconstructor
    //Pre:				node exists
    //Post:		        deletes node
    		
    void set_data(const value_type newData);
    //Description:		sets data into node
    //Pre:				node exists
    //Post:		        node has data saved in it
    		
    void set_parent(BTNode<value_type>* newParent);
    //Description:		sets parent node
    //Pre:				node exists
    //Post:		        node is set to parent
    		
    void set_left_child(BTNode<value_type>* newLChild);
    //Description:		sets node as left child node
    //Pre:				node exists
    //Post:		        node is set as left child node
    		
    void set_right_child(BTNode<value_type>* newRChild);
    //Description:		sets node as right child node
    //Pre:				node exists
    //Post:		        node is set as right child node
    		
    bool check_leaf_child() const;
    //Description:		checks if node is the last in the tree
    //Pre:				node exists
    //Post:		        returns true or false
    		
    bool check_left_child() const;
    //Description:		checks if node is the left child
    //Pre:				node existts
    //Post:		        returns true or false
    		
    bool check_right_child() const;
    //Description:		checks if node is the right child
    //Pre:				node exists
    //Post:		        returns true or false
    		
    bool check_one_child() const;
    //Description:		checks if bstree has only one node
    //Pre:				
    //Post:		        returns true or false
    		
    value_type& get_data();
    //Description:		gets data from whatever node
    //Pre:				node exists
    //Post:		        returns data from node
    		
    const value_type& get_data() const;
    //Description:		gets data from whatever node
    //Pre:				node exists
    //Post:		        returns data from node	
    		
    BTNode<value_type>* get_left_child_data();
    //Description:		gets data from left node
    //Pre:				node exists
    //Post:		        returns data from left node
    		
    const BTNode<value_type>* get_left_child_data() const;
    //Description:		gets data from left node
    //Pre:				node exists
    //Post:		        returns data from left node
    		
    BTNode<value_type>* get_right_child_data();
    //Description:		gets data from right node
    //Pre:				node exists
    //Post:		        returns data from right node
    		
    const  BTNode<value_type>* get_right_child_data() const;
    //Description:		gets data from right node
    //Pre:				node exists
    //Post:		        returns data from right node	
    		
    BTNode<value_type>* get_parent_data();
    //Description:		gets data from parent node
    //Pre:				node exists
    //Post:		        returns data from parent node	
    		
    const  BTNode<value_type>* get_parent_data() const;
    //Description:		gets data from parent node
    //Pre:				node exists
    //Post:		        returns data from parent node	
    		

    //private functions/data values
    private:
    value_type data;                //data saved in node
    BTNode<value_type>* parent;     //pointer of parent
    BTNode<value_type>* LChild;     //pointer of left child
    BTNode<value_type>* RChild;     //pointer of right child

};

//including hpp file
#include "BTNode.hpp"
#endif