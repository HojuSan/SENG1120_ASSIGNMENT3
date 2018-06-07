#include "HTable.h"

template<typename value_type>
HTable<value_type>::HTable()
{
    for(int i = 0; i < tableSize; i++)
    {
        hashTable[i] = new item;
        hashTable[i]->number = 0;
        hashTable[i]->next = NULL;
    }
}

template<typename value_type>
HTable<value_type>::~HTable()
{
    delete [] hashTable;
}

template<typename value_type>
void HTable<value_type>::add(const value_type value)
{
    int index = hashfun(value);

    if(hashTable[index]->number == 0)
    {
        hashTable[index]->number = value;
    }
    else
    {
        item* tempPtr = hashTable[index];
        item* n = new item;
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
value_type& HTable<value_type>::hashfun(const value_type& value)
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
        item* tempPtr = hashTable[index];
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

    item* tempPtr = hashTable[index];
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

    item* delPtr;
    item* p1;
    item* p2;

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