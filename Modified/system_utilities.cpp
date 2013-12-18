#include <iostream>
#include "system_utilities.h"
using namespace std;

void printError(int errorCode) {
	switch(errorCode) {
	case SYM_LIST_FULL:
		cout << "\n ***ERROR 21: Symbol List Full***  \n The symbol list is currently full." << endl;
		break;
	case DUPLICATE_SYMBOL:
		cout << "\n ***ERROR 22: Duplicate Symbol*** \n This symbol already exists in the symbol list." << endl;
		break;
	case SYMBOL_NOT_FOUND: 
		cout << "\n ***ERROR 23: Symbol Not Found*** \n The symbol does not exist in the symbol list." <<endl;
		break;
	default: 
		cout << "\n ***ERROR***" << endl;
		break;
	}
}