#include "HTable.h"

template<typename value_type>
HTable<value_type>::HTable()
{

}

template<typename value_type>
HTable<value_type>::~HTable()
{

}

template<typename value_type>
int HTable<value_type>::hashfun(int value)
{
    return value%150;
}