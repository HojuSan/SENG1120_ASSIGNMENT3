#ifndef HTable_H
#define HTable_H

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;


class HTable
{
    public:
    HTable();
    ~HTable();
    void add(int value);
    int hashfun(int value);
    int returnSize(int index);
    void printTable();
    void findNumber(int value);
    void remove(int value);

    private:
    static const int tableSize = 150;
    struct item
    {
        int number;
        item* next;
    };
    //array of pointers
    item* hashTable[tableSize];
};

ostream& operator << (ostream& out, HTable& list);

#endif