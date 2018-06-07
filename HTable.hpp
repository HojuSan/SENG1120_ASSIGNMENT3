#include "HTable.h"


HTable::HTable()
{
    for(int i = 0; i < tableSize; i++)
    {
        hashTable[i] = new item;
        hashTable[i]->number = 0;
        hashTable[i]->next = NULL;
    }
}


HTable::~HTable()
{
    delete [] hashTable;
}

void HTable::add(int value)
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


int HTable::hashfun(int value)
{
    return value%tableSize;
}


int HTable::returnSize(int index)
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


void HTable::printTable()
{
    for(int i = 0; i < tableSize; i++)
    {
        if(hashTable[i]->number != 0)
        {
            cout << hashTable[i]->number << " ";
        }
    }
}


ostream& operator << (ostream& out, HTable& list)
{
    out << "(";
    list.printTable();
    out << ")";
    return out;
}


void HTable::findNumber(int value)
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


void HTable::remove(int value)
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