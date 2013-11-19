#ifndef SYMBOL_LIST_H
#define SYMBOL_LIST_H

#include "symbols.h"
#include <iostream>
using namespace std;

//symbolList class declaration
class symbolList {
	public: 
		//Constructor: Has one parameter - int that says whether the list can contain duplicates or not (ALLOWDUPLICATES or DONTALLOWDUPLICATES). Copies the argument to the appropriate data member and set the number of elements in the list to 0. 
		symbolList(int allowDupsInput);
		//Destructor: Destroys any SYMBOL objects in the list
		~symbolList();
		//If empty list, print message. Else, print "Printing SYMBOL list:" followed by the list of symbols on the next line, indented by 5 spaces
		void print() const;
		//If the list is full, return SYM_LIST_FULL. Else, if the list doesn't allow duplicates, check if a symbol object with the same name as the input occurs. If so, return DUPLICATE_SYMBOL. Else, add the symbol to list end and return 0.
		int addSymbol(SYMBOL *inputSymbol) const;
		//If no sumbol with the key name occurs in the list, return SYMBOL_NOT_FOUND. Else, malloc space for a symbol into the second argument pointer and copy the first occurence of the symbol to the newly allocated space.
		int getSymbol(SYMBOL *keyGetSymbol, SYMBOL **receiveSymbol) const;
		//If no symbol with the key name occurs in the list, return SYMBOL_NOT_FOUND. Else, remove the first occurence, destroy the SYMBOL object, and move all other symbols down the array and return 0.
		int removeSymbol(char *keyRemoveSymbol) const;


	private:
		// array of pointers with length LISTLEN, holds a list of SYMBOL objects
		SYMBOL *array[LISTLEN];
		//number of symbols currently in the list
		int symbolCount;
		//indicates whether or not the list is allowed to have duplicate symbols (same name)
		int allowDups;
		

};

#endif