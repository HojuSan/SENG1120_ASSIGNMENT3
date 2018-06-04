#ifndef BSTREE_H
#define BSTREE_H

#include <iostream>
#include <cstdlib>
#include <string>
#include "BTNode.h"

using namespace std;

template <typename value_type>

class BSTree
{
    public:
    BSTree();
    BSTree(value_type data);
    ~BSTree();
    void add(value_type new_input);
    //when you pass a literally value like an integer or a string instead of a stated variable like val1
    //you need to put a const in it
    void remove(const value_type& remove_input);
    void print();
    BTNode<value_type>* findMin(BTNode<value_type>* node);

    private:
    BTNode<value_type>* rootPtr;
    size_t size;

    void insert(BTNode<value_type>* node, value_type data);
    int compareNodes(const value_type node1, const value_type node2);
    void erase(BTNode<value_type>* node, const value_type& data);
    void privatePrint(BTNode<value_type>* node);


};

template <typename value_type>
ostream& operator << (ostream& out, BSTree<value_type>& list);

#include "BSTree.hpp"
#endif