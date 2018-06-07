#ifndef HTable_H
#define HTable_H

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

template<typename value_type>
struct item
{
    value_type number;
    item* next;
};

template<typename value_type>
class HTable
{
    public:
    HTable();
    ~HTable();
    void add(const value_type value);
    int hashfun(const value_type& value);
    int returnSize(const value_type& index);
    void printTable();
    void findNumber(const value_type& value);
    void remove(const value_type& value);

    private:
    static const int tableSize = 150;
    //array of pointers
    item<value_type>* hashTable[tableSize];
};

template<typename value_type>
ostream& operator << (ostream& out, HTable<value_type>& list);

#include "HTable.hpp"
#endif