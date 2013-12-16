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
			cout << "/t";
			cout << symbolArray[i] << endl;
		}
	}
}

int symbolList::addSymbol(SYMBOL *inputSymbol) const {
	//If the list is full, return SYM_LIST_FULL. Else, if the list doesn't allow duplicates, check if a symbol object with the same name as the input occurs [use isThisMyName]. If so, return DUPLICATE_SYMBOL. Else, add the symbol to list end and return 0.

	if(symbolCount == LISTLEN) { //if list is full
		return SYM_LIST_FULL;
	}

	else if(allowDups == DONTALLOWDUPLICATES) { //if no duplicates
		for(int i = 0; i < LISTLEN; i++) {
			if (symbolArray[i]->isThisMyName(inputSymbol) { //check if current symbol is same as input symbol
				return DUPLICATE_SYMBOL;
			}
		}
	}
	else {
		symbolArray[symbolCount] = inputSymbol; //assign input to next available array spot
		symbolCount++; //increase count
		return 0;
	}
}
		
int symbolList::getSymbol(SYMBOL *keyGetSymbol, SYMBOL **receiveSymbol) const {
	//If no symbol with the key name occurs in the list, return SYMBOL_NOT_FOUND. Else, malloc space for a symbol into the second argument pointer and copy the first occurence of the symbol to the newly allocated space [use copyMyName].

	for(int i = 0; i < LISTLEN; i++) {
		if(symbolArray[i] == keyGetSymbol) {

			/* char* name = SYMBOL.copyMyName(keyGetSymbol);
			int size = strlen(name); //find length of the key
			receiveSymbol = (char*)malloc(size+1); //allocate space +1 for null
			strcpy(receiveSymbol, name); //copies symbol into storage from input 
			*/
		}
		else {
			return SYMBOL_NOT_FOUND;
		}
	}
}

int symbolList::removeSymbol(char *keyRemoveSymbol) const {
	//If no symbol with the key name occurs in the list, return SYMBOL_NOT_FOUND. Else, remove the first occurence, destroy the SYMBOL object, and move all other symbols down the array and return 0.
}