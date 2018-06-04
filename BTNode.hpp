#include "BTNode.h"

/*
template<typename value_type>
BTNode<value_type>::BTNode()
{
    data ??
    LChild = NULL;
    RChild = NULL;
    parent = NULL;
}
*/

template<typename value_type>
BTNode<value_type>::BTNode(const value_type& intdata, BTNode<value_type>* intLchild, BTNode<value_type>* intRchild, BTNode<value_type>* intParent)
{
    data = intdata;
    LChild = intLchild;
    RChild = intRchild;
    parent = intParent;
}

template<typename value_type>
BTNode<value_type>::~BTNode()
{
    LChild = NULL;
    RChild = NULL;
    parent = NULL;
}

template<typename value_type>
void BTNode<value_type>::set_data(const value_type newData)
{
    data = newData;
}

template<typename value_type>
void BTNode<value_type>::set_parent(BTNode<value_type>* newParent)
{
    parent = newParent;
}

template<typename value_type>
void BTNode<value_type>::set_left_child(BTNode<value_type>* newLChild)
{
    LChild = newLChild;
}

template<typename value_type>
void BTNode<value_type>::set_right_child(BTNode<value_type>* newRChild)
{
    RChild = newRChild;
}

template<typename value_type>
bool BTNode<value_type>::check_leaf_child() const
{
    return ((LChild == NULL) && (RChild == NULL));
}

template<typename value_type>
bool BTNode<value_type>::check_left_child() const
{
    return (data < parent->get_data());
}

template<typename value_type>
bool BTNode<value_type>::check_right_child() const
{
    return (data > parent->get_data());
}

template<typename value_type>
bool BTNode<value_type>::check_one_child() const
{
    return	(((LChild == NULL) && (RChild != NULL)) || ((LChild != NULL) && (RChild == NULL)));		
}

template<typename value_type>
value_type& BTNode<value_type>::get_data()
{
    return data;
}

template<typename value_type>
const value_type& BTNode<value_type>::get_data() const
{
    return data;
}

template<typename value_type>
BTNode<value_type>* BTNode<value_type>::get_left_child_data()
{
    return LChild;
}

template<typename value_type>
const BTNode<value_type>* BTNode<value_type>::get_left_child_data() const
{
    return LChild;
}

template<typename value_type>
BTNode<value_type>* BTNode<value_type>::get_right_child_data()
{
    return RChild;
}

template<typename value_type>
const  BTNode<value_type>* BTNode<value_type>::get_right_child_data() const
{
    return RChild;
}

template<typename value_type>
BTNode<value_type>* BTNode<value_type>::get_parent_data()
{
    return parent;
}

template<typename value_type>
const  BTNode<value_type>* BTNode<value_type>::get_parent_data() const
{
    return parent;
}