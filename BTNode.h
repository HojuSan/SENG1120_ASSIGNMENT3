#ifndef BSNODE_H
#define BSNODE_H

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

template <typename value_type>

class BTNode
{
    public:
//    BTNode();
    BTNode(const value_type& intdata = value_type(), BTNode<value_type>* intLchild = NULL, BTNode<value_type>* intRchild = NULL, BTNode<value_type>* intparent = NULL);
    ~BTNode();
    void set_data(const value_type newData);
    void set_parent(BTNode<value_type>* newParent);
    void set_left_child(BTNode<value_type>* newLChild);
    void set_right_child(BTNode<value_type>* newRChild);
    bool check_leaf_child() const;
    bool check_left_child() const;
    bool check_right_child() const;
    bool check_one_child() const;
    value_type& get_data();
    const value_type& get_data() const;
    BTNode<value_type>* get_left_child_data();
    const BTNode<value_type>* get_left_child_data() const;
    BTNode<value_type>* get_right_child_data();
    const  BTNode<value_type>* get_right_child_data() const;
    BTNode<value_type>* get_parent_data();
    const  BTNode<value_type>* get_parent_data() const;



    private:
    value_type data;
    BTNode<value_type>* parent;
    BTNode<value_type>* LChild;
    BTNode<value_type>* RChild;

};

#include "BTNode.hpp"
#endif