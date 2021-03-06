/*
Name:           Juyong Kim
Subject:        SENG1120
Task:           Assignment 3
Hopes:          Passing this course
Dreams:         Crushed
Social Life:    Non Existent 
*/
#include "BSTree.h"
	
//constructor
template<typename value_type>
BSTree<value_type>::BSTree()
{
    rootPtr = NULL;                                             //sets root pointer to null
    size = 0;                                                   //size of bstree is set to zero
}

//constructor with parameters
template<typename value_type>
BSTree<value_type>::BSTree(value_type data)
{
    rootPtr = new BTNode<value_type>(data);                     //sets root pointer to node with set data
    size = 1;                                                   //bstree size is 1
}

//deconstructor
template<typename value_type>
BSTree<value_type>::~BSTree()
{
    delete rootPtr;                                             
}

template<typename value_type>
void BSTree<value_type>::add(value_type data)
{
    if(rootPtr == NULL)
    {
        rootPtr = new BTNode<value_type>(data);
    }
    else
    {
        insert(rootPtr, data);
    }
}

//currently working on this one
template<typename value_type>
void BSTree<value_type>::insert(BTNode<value_type>* node, value_type data)
{
    int family = compareNodes(data, node->get_data());

    if(family == 0)
    {
        node->set_data(data);
    }
    else if (family > 0)
    {
        if(node->get_right_child_data() == NULL)
        {
            node->set_right_child(new BTNode<value_type>(data));
            node->get_right_child_data()->set_parent(node);
            size++;
            return;
        }
        else
        {
            insert(node->get_right_child_data(), data);
        }
    }
    else
    {
        if(node->get_left_child_data() == NULL)
        {
            node->set_left_child(new BTNode<value_type>(data));
            node->get_left_child_data()->set_parent(node);
            size++;
            return;
        }
        else
        {
            insert(node->get_left_child_data(), data);
        }
    }
}

template<typename value_type>
int BSTree<value_type>::compareNodes(const value_type node1, const value_type node2)
{
    if(node1 < node2)
    {
        return -1;
    }
    else if(node1 == node2)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

template<typename value_type>
void BSTree<value_type>::remove(const value_type& data)
{

    if(size == 0)
    {
        return;
    }
    else
    {
        erase(rootPtr,data);
    }

}

template<typename value_type>
void BSTree<value_type>::erase(BTNode<value_type>* node, const value_type& data)
{
    
    if (node == NULL)														//If the node passed in is NULL
    {
        return;													
    }

    int relation = compareNodes(data, node->get_data());					//Call the comparenode function, sets relation to it

    if (relation > 0)														//If the data passed in is bigger then the node
    {
        erase(node->get_right_child_data(), data);									//Call itself on the right node
    }
    else if (relation < 0)													//If the data passed in is smaller then the node
    {
        erase(node->get_left_child_data(), data);									//Call itself on the left node
    }
    else 																	//Else
    {
        if(node->check_leaf_child())												//If it is a leaf node, i.e no children
        {
            if(compareNodes(rootPtr->get_data(), data) == 0)				//If the data, and node data are the same
            {
                rootPtr = NULL;												//Set root to NULL
            }
            else 															//Else
            {
                if(node->check_right_child()) 									//if it a right child
                {
                    node->get_parent_data()->set_right_child(NULL); 					//Set it's parent's right child to NULL
                }
                else 														//Else
                {
                    node->get_parent_data()->set_left_child(NULL); 					//Set it's parent's left child to NULL
                }
            }
            delete node;													//Delete node
            node = NULL;													//Set node to NULL
            size--;															//Decrease size
        }
        else if(node->check_one_child()) 										//Else if the node have a one child
        {
            if (compareNodes(rootPtr->get_data(), data) == 0)				//The root, and the data are the same
            {
                if(node->get_right_child_data() != NULL) 								//If the right child is not NULL
                {
                    node->get_right_child_data()->set_parent(NULL);					//Set it's parents right child to NULL
                    rootPtr = node->get_right_child_data();							//Set the root to the node's right child
                }
                else 														//Else
                {
                    node->get_left_child_data()->set_parent(NULL); 					//Set it's parents left child to NULL
                    rootPtr = node->get_left_child_data();  							//Set the root to the node's right child
                }
            }
            else if(node->get_right_child_data() != NULL) 							//If the node's right child is not NULL
            {
                node->get_right_child_data()->set_parent(node->get_parent_data());			//Set the Right child's parent to be the parent of the current node
                if (node->check_right_child()) 									//if the node is a right child
                {
                    node->get_parent_data()->set_right_child(node->get_right_child_data()); 	//Set the current node's parent's right node to be the current node's right child
                }
                else
                {
                    node->get_parent_data()->set_left_child(node->get_right_child_data()); 	//Set the current node's parent's left node to be the current node's left child
                }
            }
            else 															//Else
            {
                node->get_left_child_data()->set_parent(node->get_parent_data()); 		//Set the left child's parent to be the parent of the current node
                if (node->check_right_child()) 									//If the node is a right child
                {
                    node->get_parent_data()->set_right_child(node->get_left_child_data()); 	//Set the current node's parent's right node to be the current node's right child
                }
                else 														//Else
                {
                    node->get_parent_data()->set_left_child(node->get_left_child_data()); 	//Set the current node's parent's left node to be the current node's left child
                }
            }
        delete node; 														//Delete node
        size--;			
        }													//Decrease size
        else 																//Else
        {
            BTNode<value_type>* temp_node = findMin(node->get_right_child_data());		//Creates a temp node, by finding the lowerst node on the right child
            value_type* temporary_object = new value_type(temp_node->get_data());		//Creates temp object that stores the data of the temp node
            erase(temp_node, temp_node->get_data());							//Calls itself
            node->set_data(*temporary_object);										//sets the data of the temp object to the node
        }
    }														
}

template<typename value_type>
BTNode<value_type>* BSTree<value_type>::findMin(BTNode<value_type>* node)	//Finds the smallest node
{
    if (node->get_left_child_data() != NULL) 										//If the left child is not NULL
    {
        findMin(node->get_left_child_data());										//Calls itself, passing in the node's left child
    }
    else 																	//Else
    {
        return node; 														//Returns the node
    }
}   
    

template<typename value_type>
void BSTree<value_type>::print()
{
    privatePrint(rootPtr);
}

template<typename value_type>
void BSTree<value_type>::privatePrint(BTNode<value_type>* node)
{
    if(node != NULL)
    {
        privatePrint(node->get_left_child_data());
        cout << node->get_data() << " ";
        privatePrint(node->get_right_child_data());
    }
}

template<typename value_type>        
ostream& operator << (ostream& out, BSTree<value_type>& list)
{
    out << "(";
    list.print();
    out << ")";
    return out;
}
