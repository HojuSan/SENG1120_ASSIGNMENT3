#ifndef HTable_H
#define HTable_H

#include <iostream>
#include <cstdlib>
#include <string>

template<typename value_type>

using namespace std;

class HTable
{
    public:
    HTable();
    ~HTable();
    int hashfun(int value);

    private:

};

#include "HTable.hpp"
#endif