#include <iostream>
#include <stdlib.h>
#include <string.h>
#include "symbols.h"
using namespace std;


SYMBOL::SYMBOL (char* symbolNameInput) {
	//Constructor: Mallocs new space for the symbol name and then copies the name from the argument pointer to the newly allocated space. Use malloc function.

	int size = strlen(symbolNameInput); //find length of input symbolName
	symbolNameLocation = (char*)malloc(size+1); //allocate space +1 for null
	strcpy(symbolNameLocation, symbolNameInput); //copies name into storage from input
	*(symbolNameLocation + size) = '\0'; //add null at end of dereferenced pointer (aka name)
}


SYMBOL::~SYMBOL() {
	//Destructor: Frees the memory allocated for the name when the object was created. Use free function.

	free((void*)symbolNameLocation);
}


void SYMBOL::print() const {
	//Prints the name of the symbol

	cout << symbolNameLocation;

}

int SYMBOL::isThisMyName(char* inputName) {
	//Compares input name to symbol name and returns 1 if the same, 0 otherwise.

	int different = strcmp(inputName, symbolNameLocation);
	if(different == 0) { //returns 0 if equal
		return 1;
	}
	else {
		return 0;
	}
}

/*
int SYMBOL::isThisMyName(char* inputName) {
	//Compares input name to symbol name and returns 1 if the same, 0 otherwise. 
	
	int different = strcmp(symbolNameLocation, inputName);
	if(different == 0) {  //returns 0 if equal
		return 1;
	}
	else if((different == -1) ||(different == 1)) {
		return 0;
	}
} */

void SYMBOL::copyMyName(char** nameAddress) {
	//Takes a pointer to char as an argument. Mallocs enough space to hold the string representing the name and assigns that address to the argument.  It then copies the name to the newly allocated space.
		
	int size = strlen(symbolNameLocation); //find length of input symbolName
	*nameAddress = (char*)malloc(size+1); //allocate space +1 for null
	strcpy(*nameAddress, symbolNameLocation); //copy name to the new address (dereferenced double pointer)
}