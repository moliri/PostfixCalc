#include <iostream>
#include "symbols.h"
using namespace std;


SYMBOL::SYMBOL (char* symbolName) {
	//Constructor: Mallocs new space for the symbol name and then copies the name from the argument pointer to the newly allocated space. 

}


SYMBOL::~SYMBOL() {
	//Destructor: Frees the memory allocated for the name when the object was created

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