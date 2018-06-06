#ifndef HTable_H
#define HTable_H

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

template<typename value_type>

class HTable
{
    public:
    HTable();
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
    }
    item* hashTable [tableSize];
};

template <typename value_type>
ostream& operator << (ostream& out, HTable<value_type>& list);

#include "HTable.hpp"
#endif