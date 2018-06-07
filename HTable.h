/*
Name:           Juyong Kim
Subject:        SENG1120
Task:           Assignment 3
Hopes:          Passing this course
Dreams:         Crushed
Social Life:    Non Existent 
*/
//Macro Guards
#ifndef HTable_H
#define HTable_H

//Libraries
#include <iostream>
#include <cstdlib>
#include <string>

//namespaces
using namespace std;

//templates
template<typename value_type>
//struct item, stores the integer and then uses pointers
//cause smart data manipulation right
struct item
{
    //This number is a lovely piece of chocolate pudding that made me loose
    //sleep for 3 days cause i couldn't figure out why
    //the WDH#%YUSD@$^%Y wouldn't work, ONE BLOODY REFERENCE
    //I should probably delete this but im to tired to. i need to vent, sorry
    //value_type& number ~~ reminder of why i picked the wrong degree
    //Never forget Daniel, Never forget
    value_type number;
    //pointer
    item* next;
};

template<typename value_type>
//class definition
class HTable
{
    //public functions
    public:

    HTable();
    //Description:		constructor
    //Pre:				
    //Post:		        creates a hashtable
    		
    ~HTable();
    //Description:		deconstructor
    //Pre:				hashtable exists
    //Post:		        deletes a hashtable
    		
    void add(const value_type value);
    //Description:		adds a value to the hashtable
    //Pre:				hashtable exists
    //Post:		        value is added to hashtable
    		
    int hashfun(const value_type& value);
    //Description:		function that makes a key value and returns it
    //Pre:				hashtable exists
    //Post:		        creates a key and returns
    		
    int returnSize(const value_type& index);
    //Description:		returns the elements in the hashtable
    //Pre:				hashtable exists
    //Post:		        returns the size
    		
    void printTable();
    //Description:		prints the values of the hashtable
    //Pre:				hashtable exists with values
    //Post:		        prints the values of the hashtable
    		
    void findNumber(const value_type& value);
    //Description:		finds the value in the hashtable
    //Pre:				number exists in hashtable
    //Post:		        prints number:primarily used for testing
    		
    void remove(const value_type& value);
    //Description:		deletes value from hashtable
    //Pre:				value and hashtable exists
    //Post:		        value is deleted from hashtable
    		

    //private functions/data values
    private:

    static const int tableSize = 150;               //size of the array
 
    item<value_type>* hashTable[tableSize];
    //Description:		creates an array of pointers
    //Pre:				
    //Post:		        creates an array of pointers
    		
};

    template<typename value_type>
    ostream& operator << (ostream& out, HTable<value_type>& list);
    //Description:	    overloaded function that calls the print function that prints hashtable values
    //Pre:				hashtable exists with values in it
    //Post:		        code can print values

//including hpp file		
#include "HTable.hpp"
#endif