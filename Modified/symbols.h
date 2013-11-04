#ifndef SYMBOLS_H
#define SYMBOLS_H

#include <iostream>
using namespace std;

//SYMBOL class declaration
class SYMBOL {
	public: 
		//Constructor: Mallocs new space for the symbol name and then copies the name from the argument pointer to the newly allocated space; use malloc function.
		SYMBOL (char* symbolName);
		//Destructor: Frees the memory allocated for the name when the object was created; use free function.
		~SYMBOL();
		//Prints the name of the symbol
		void print() const;
		//Compares input name to symbol name and returns 1 if the same, 0 otherwise. 
		int isThisMyName(char* inputName) const;
		//Mallocs enough space to hold the string representing the name and assigns that address to the argument.  It then copies the name to the newly allocated space. 
		void copyMyName(char** nameAddress);


	private:
		// points to a set of bytes that represent the name of the symbol
		char* symbolName;  

};

#endif