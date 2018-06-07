/*
Name:           Juyong Kim
Subject:        SENG1120
Task:           Assignment 3
Hopes:          Passing this course
Dreams:         Crushed
Social Life:    Non Existent 
*/
#include "HTable.h"

//constructor
template<typename value_type>
HTable<value_type>::HTable()
{
    for(int i = 0; i < tableSize; i++)                                      //for loop that goes through the entire array
    {
        hashTable[i] = new item<value_type>;                                //creates an item to save into each index of the array
        hashTable[i]->number = 0;                                           //number is set to default
        hashTable[i]->next = NULL;                                          //pointer is also set to null
    }
}

//deconstructor
template<typename value_type>
HTable<value_type>::~HTable()
{
    for(int i = 0; i < tableSize; i++)                                      //for loop that goes through the entire array
    {
        delete hashTable[i];                                                //deletes the item in that index
        hashTable[i] = NULL;                                                //sets the pointer from this index to null
    }
}

template<typename value_type>
void HTable<value_type>::add(const value_type value)
{
    int index = hashfun(value);                                             //sets a key from hashfun into an index

    if(hashTable[index]->number == 0)                                       //if there is no value at that index of the array
    {
        hashTable[index]->number = value;                                   //set the value into that index of the array
    }
    else                                                                    //else
    {
        item<value_type>* tempPtr = hashTable[index];                       //create a temporary pointer 
        item<value_type>* n = new item<value_type>;
        n->number = value;
        n->next = NULL;
        while(tempPtr->next != NULL)
        {
            tempPtr = tempPtr->next;
        }
        tempPtr->next = n;
    }

}


template<typename value_type>
int HTable<value_type>::hashfun(const value_type& value)
{
    return value%tableSize;
}

template<typename value_type>
int HTable<value_type>::returnSize(const value_type& index)
{
    int count = 0;

    if(hashTable[index]->number == 0)
    {
        return count;
    }
    else
    {
        count++;
        item<value_type>* tempPtr = hashTable[index];
        while(tempPtr->next != NULL)
        {
            count++;
            tempPtr = tempPtr->next;
        }
    }

    return count;
}

template<typename value_type>
void HTable<value_type>::printTable()
{
    for(int i = 0; i < tableSize; i++)
    {
        if(hashTable[i]->number != 0)
        {
            cout << hashTable[i]->number << " ";
        }
    }
}

template<typename value_type>
ostream& operator << (ostream& out, HTable<value_type>& list)
{
    out << "(";
    list.printTable();
    out << ")";
    return out;
}

template<typename value_type>
void HTable<value_type>::findNumber(const value_type& value)
{
    int index = hashfun(value);
    bool foundNumber = false;
    int tempNum;

    item<value_type>* tempPtr = hashTable[index];
    while(tempPtr != NULL)
    {
        if(tempPtr->number == value)
        {
            foundNumber = true;
            tempNum = tempPtr->number;
        }
        tempPtr = tempPtr->next;
    }
    if(foundNumber == true)
    {
        cout << "number is " << tempNum << endl;
    }
    else
    {
        cout << "number wasn't found" << endl;
    }
}

template<typename value_type>
void HTable<value_type>::remove(const value_type& value)
{
    int index = hashfun(value);

    item<value_type>* delPtr;
    item<value_type>* p1;
    item<value_type>* p2;

    //case1 item doesn't exist
    if(hashTable[index]->number == 0)
    {
        return;
    }
    //case2 number is found and only has one number saved in the bucket
    else if(hashTable[index]->number == value && hashTable[index]->next == NULL)
    {
        hashTable[index]->number = 0;
    }
    //case3 number is found but more numbers in the bucket
    else if(hashTable[index]->number == value)
    {
        delPtr = hashTable[index];
        hashTable[index] = hashTable[index]->next;
        delete delPtr;
    }
    //case4 number exists in bucket but the first number isn't a match
    else
    {
        p1 = hashTable[index]->next;
        p2 = hashTable[index];

        while(p1 != NULL && p1->number != value)
        {
            p2 = p1;
            p1 = p1->next;
        }
        //no match
        if(p1 == NULL)
        {
            return;
        }
        //number is found
        else
        {
            delPtr = p1;
            p1 = p1->next;
            p2->next = p1;

            delete delPtr;
        }
    }

}