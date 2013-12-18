#include <iostream>
#include "symbol_list.h"
using namespace std;

symbolList::symbolList(int allowDupsInput){
	//Constructor: Has one parameter - int that says whether the list can contain duplicates or not (ALLOWDUPLICATES or DONTALLOWDUPLICATES). Copies the argument to the appropriate data member and set the number of elements in the list to 0. 
	
	allowDups = allowDupsInput; //copies input into data member
	symbolCount = 0; //sets list element count to 0
}
		
symbolList::~symbolList() {
	//Destructor: Destroys any SYMBOL objects in the list
	
	for(int i = 0; i < LISTLEN; i++) { //walk through array
		delete symbolArray[i];	//and remove each symbol
	}
}
		
void symbolList::print() const {
	//If empty list, print message. Else, print "Printing SYMBOL list:" followed by the list of symbols on the next line, indented by 5 spaces

	if(symbolCount == 0) {
		cout << "Symbol list is empty."; 
	}
	else {
		cout << "Printing SYMBOL list:" << endl;
		for(int i = 0; i < LISTLEN; i++){
			cout << "\t";
			char* name;
			symbolArray[i]->copyMyName(&name);
			cout << name << endl;
		}
	}
}

int symbolList::addSymbol(SYMBOL *inputSymbol) {
	//If the list is full, return SYM_LIST_FULL. Else, if the list doesn't allow duplicates, check if a symbol object with the same name as the input occurs [use isThisMyName]. If so, return DUPLICATE_SYMBOL. Else, add the symbol to list end and return 0.
	char* inputHolder; //for converting SYMBOL* to char*
	inputSymbol->copyMyName(&inputHolder); //copy input
	if(symbolCount == LISTLEN) { //if list is full
		return SYM_LIST_FULL;
	}

	if(allowDups == DONTALLOWDUPLICATES) { //if no duplicates
		for(int i = 0; i < LISTLEN; i++) {
			if (symbolArray[i]->isThisMyName(inputHolder)) { //check if current symbol is same as input symbol
				return DUPLICATE_SYMBOL;
			}
		}
	}
	symbolArray[symbolCount] = inputSymbol; //assign input to next available array spot
	symbolCount++; //increase count
	return 0;
}
		
int symbolList::getSymbol(char* keyGetSymbol, SYMBOL** receiveSymbol) {
	//If no symbol with the key name occurs in the list, return SYMBOL_NOT_FOUND. Else, malloc space for a symbol into the second argument pointer and copy the first occurence of the symbol to the newly allocated space [use copyMyName].
	
	for(int i = 0; i < LISTLEN; i++) {
		if (symbolArray[i]->isThisMyName(keyGetSymbol)) { //check if current symbol is same as key
			int keySize = strlen(keyGetSymbol); //find length of the key
			*receiveSymbol = (SYMBOL*)malloc(keySize+1); //allocate space +1 for null

			int spaceSize = sizeof(**receiveSymbol); //check size to copy
			memcpy(*receiveSymbol, keyGetSymbol, spaceSize); //copies symbol into allocated space
			
		}
		else {
			return SYMBOL_NOT_FOUND;
		}
	}
}

int symbolList::removeSymbol(char *keyRemoveSymbol) {
	//If no symbol with the key name occurs in the list, return SYMBOL_NOT_FOUND. Else, remove the first occurence, destroy the SYMBOL object, and move all other symbols down the array and return 0.

	for(int i = 0; i < LISTLEN; i++) {
		if (symbolArray[i]->isThisMyName(keyRemoveSymbol)) { //check if current symbol is same as key
			delete symbolArray[i]; //remove/delete current one
			symbolArray[i+1] = symbolArray[i+2]; //shifting next symbol in the array down by one
			return 0;
		}
		else {
			return SYMBOL_NOT_FOUND;
		}
	}
}