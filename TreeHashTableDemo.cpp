//TreeHashTableDemo - Main Program
/******************************/
//Author: Alex Mendes
//Course: SENG1120
//Program Description: This program demonstrates the basic functionality of binary seach trees and hash tables. 

#include <iostream>
#include <cstdlib>
#include <time.h>
#include "BSTree.h"
#include "HTable.h"
using namespace std;

int main()
{
	clock_t t;
	
	BSTree treeValues;
	HTable tableValues;

	// if you are using class templates.
	// BSTree<int> treeValues;
	// HTable<int> tableValues;

	int vectorMarks[] = {123454, 23418, 787626, 56534, 879840, 5465443, 5650, 678760, 3456462, 34465, 97567, 345169, 1456769, 867570, 565471};
    cout << sizeof(vectorMarks)/sizeof(vectorMarks[0]) << endl;
/*
	t = clock(); // gets current time
	for (int i=0; i<sizeof(vectorMarks)/sizeof(vectorMarks[0]); i++) {treeValues.add(vectorMarks[i]);} // populates the tree.
    cout << "Initial tree: " << treeValues << endl; // prints the contents of the tree.

	// modifies the tree.
	treeValues.remove(123454);
    treeValues.remove(787626);
	treeValues.remove(678760);
	treeValues.remove(22670);
	treeValues.remove(56534);
	treeValues.remove(1456769);
	treeValues.remove(5465443);
	
    cout << "Final tree: " << treeValues << endl; // prints the contents of the tree.
	cout << "Time elapsed: " << (clock() - t) << endl << endl; // prints elapsed time.

	t = clock(); // gets current time
    for (int i=0; i<sizeof(vectorMarks)/sizeof(vectorMarks[0]); i++) {tableValues.add(vectorMarks[i]);} // populates the hash table.
    cout << "Initial hash table: " << tableValues << endl; // prints the contents of the hash table.

	tableValues.remove(123454);
    tableValues.remove(787626);
	tableValues.remove(678760);
	tableValues.remove(22670);
	tableValues.remove(56534);
	tableValues.remove(1456769);
	tableValues.remove(5465443);
*/
    cout << "Final hash table: " << tableValues << endl; // prints the contents of the hash table.
    cout << "Time elapsed: " << (clock() - t) << endl << endl; // prints elapsed time.

	cout << "The program has finished." << endl;
	return 0;
}