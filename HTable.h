#ifndef HTable_H
#define HTable_H

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

template<typename value_type>
struct item
{
    //This number is a little piece of shit that made me loose
    //sleep for 3 days cause i couldn't figure out why
    //the WDH#%YUSD@$^%Y wouldn't work, ONE BLOODY REFERENCE
    //I should probably delete this but im to tired to. i need to vent, sorry
    //value_type& number ~~ reminder of why i picked the wrong degree
    //Never forget Daniel, Never forget
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