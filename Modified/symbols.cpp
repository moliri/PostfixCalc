#include <iostream>
#include "symbols.h"
using namespace std;


SYMBOL::SYMBOL (char* symbolName) {
	//Constructor: Mallocs new space for the symbol name and then copies the name from the argument pointer to the newly allocated space. Use malloc function.

	int size = sizeof(symbolName); //find size of input symbolName
	char*symbolNameSpace; //create a pointer to a new area to store the name
	symbolNameSpace = (char*)malloc(size); //allocate space
	*symbolNameSpace = *symbolName; //copies name from input to storage
}


SYMBOL::~SYMBOL() {
	//Destructor: Frees the memory allocated for the name when the object was created. Use free function.

}


void SYMBOL::print() const {
	//Prints the name of the symbol

}

int SYMBOL::isThisMyName(char* inputName) const {
	//Compares input name to symbol name and returns 1 if the same, 0 otherwise. 
}

void SYMBOL::copyMyName(char** nameAddress) {
	//Mallocs enough space to hold the string representing the name and assigns that address to the argument.  It then copies the name to the newly allocated space.

}