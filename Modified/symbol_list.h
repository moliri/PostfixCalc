#ifndef SYMBOL_LIST_H
#define SYMBOL_LIST_H

#include <iostream>
using namespace std;

//symbolList class declaration
class symbolList {
	public: 
		//Constructor: Mallocs new space for the symbol name and then copies the name from the argument pointer to the newly allocated space. 
		SYMBOL (char* symbolName);
		//Destructor: Frees the memory allocated for the name when the object was created
		~SYMBOL();
		//Prints the name of the symbol
		void print() const;
		//Compares input name to symbol name and returns 1 if the same, 0 otherwise. 
		int isThisMyName(char* inputName) const;
		//Mallocs enough space to hold the string representing the name and assigns that address to the argument.  It then copies the name to the newly allocated space. 
		void copyMyName(char** nameAddress);


	private:
		// array of pointers with length LISTLEN, holds a list of SYMBOLS objects

		//number of symbols currently in the list
		int symbolCount;
		//indicates whether or not the list is allowed to have duplicate symbols
		int allowDups;
		

};

#endif