/*
	Main test driver for Program 3.
	Author:  	Larry Henschen
			henschen@eecs.northwestern.edu
	Creation date:	April 23, 2012
	Last Modified:	April 23, 2012

*/

#include "system_utilities.h"
#include "symbols.h"
#include "symbol_list.h"
#include <iostream>
using namespace std;




int main() {
	int err;  char *tmpname;
	
	SYMBOL s1("x15"), s2("larry"), *s3;
	symbolList lst(DONTALLOWDUPLICATES), lst1(ALLOWDUPLICATES);

	s3 = new SYMBOL("a");

	// Test the SYMBOL class print function.
	cout << "Symbol s1 is ";
	s1.print();
	cout << ".\n";
	cout << "Symbol s2 is ";
	s2.print();
	cout << ".\n";
	cout << "Symbol s3 is ";
	s3->print();
	cout << ".\n";

	// Test SYMBOL class isThisMyName function.
	cout << s1.isThisMyName("x15");
	cout << s1.isThisMyName("xyz");
	cout << s2.isThisMyName("larry");
	cout << s2.isThisMyName("a");
	cout << s3->isThisMyName("a");
	cout << s3->isThisMyName("b");

	// Done with symbol "a".  Return memory to system.
	//delete s3;
	free((void *)s3);

	
	cout << "\n\n\nBeginning tests for symbolList.\n\n";

	// Test allow supplicates option.
	s3 = new SYMBOL("tst1");
	err = lst1.addSymbol(s3);
	err = lst1.addSymbol(s3);
	err = lst1.addSymbol(s3);
	err = lst1.addSymbol(s3);
	err = lst1.addSymbol(s3);
	err = lst1.addSymbol(s3);
	err = lst1.addSymbol(s3);
	err = lst1.addSymbol(s3);
	s3 = new SYMBOL("tst2");
	err = lst1.addSymbol(s3);
	err = lst1.addSymbol(s3);
	lst1.print();

	cout << "lst test"; //LM 
	// Begin tests for symbol list class.
	lst.print(); //should print empty - LM
	s3 = new SYMBOL("tst1");
	err = lst.addSymbol(s3);
	lst.print(); //should print 1, prints empty, so not incrementing symbolCount -LM
	cout << "debug" << err; //LM
	if(err!=0) printError(err);
	s3 = new SYMBOL("tst2");
	err = lst.addSymbol(s3);
	if(err!=0) printError(err);
	s3 = new SYMBOL("tst3");
	err = lst.addSymbol(s3);
	if(err!=0) printError(err);
	s3 = new SYMBOL("tst4");
	err = lst.addSymbol(s3);
	if(err!=0) printError(err);
	s3 = new SYMBOL("tst5");
	err = lst.addSymbol(s3);
	if(err!=0) printError(err);

	lst.print();

	s3 = new SYMBOL("tst1");
	err = lst.addSymbol(s3);
	if(err!=0) printError(err);
	s3 = new SYMBOL("tst3");
	err = lst.addSymbol(s3);
	if(err!=0) printError(err);
	s3 = new SYMBOL("tst5");
	err = lst.addSymbol(s3);
	if(err!=0) printError(err);

	s3 = new SYMBOL("tst6");
	err = lst.addSymbol(s3);
	if(err!=0) printError(err);
	s3 = new SYMBOL("tst7");
	err = lst.addSymbol(s3);
	if(err!=0) printError(err);
	s3 = new SYMBOL("tst8");
	err = lst.addSymbol(s3);
	if(err!=0) printError(err);
	s3 = new SYMBOL("tst9");
	err = lst.addSymbol(s3);
	if(err!=0) printError(err);
	s3 = new SYMBOL("tst10");
	err = lst.addSymbol(s3);
	if(err!=0) printError(err);

	lst.print();

	s3 = new SYMBOL("tst11");
	err = lst.addSymbol(s3);
	if(err!=0) printError(err);


	cout << "\n\nBeginning tests for getSymbol.\n\n";

	// Test the getSymbol function.
	err = lst.getSymbol("tst1", &s3);
	if(err!=0) printError(err);
	else {	cout << "Symbol found: ";
			s3 -> print();
			cout << "\n";
			//delete s3;
			free((void *)s3);
	}
	err = lst.getSymbol("tst4", &s3);
	if(err!=0) printError(err);
	else {	cout << "Symbol found: ";
			s3 -> print();
			cout << "\n";
			//delete s3;
			free((void *)s3);
	}
	err = lst.getSymbol("tst10", &s3);
	if(err!=0) printError(err);
	else {	cout << "Symbol found: ";
			s3 -> print();
			cout << "\n";
			//delete s3;
			free((void *)s3);
	}
	err = lst.getSymbol("xyz", &s3);
	if(err!=0) printError(err);
	else {	cout << "Symbol found: ";
			s3 -> print();
			cout << "\n";
			//delete s3;
			free((void *)s3);
	}
	

	cout << "\n\nBeginning tests for remove function.\n\n";

	// Test the symbolList class remove function.
	err = lst.removeSymbol("tst1");
	if(err!=0) printError(err);
	err = lst.removeSymbol("tst3");
	if(err!=0) printError(err);
	err = lst.removeSymbol("tst5");
	if(err!=0) printError(err);
	err = lst.removeSymbol("tst7");
	if(err!=0) printError(err);
	err = lst.removeSymbol("tst9");
	if(err!=0) printError(err);
	lst.print();
	err = lst.removeSymbol("tst5");
	if(err!=0) printError(err);
	err = lst.removeSymbol("tst2");
	if(err!=0) printError(err);
	err = lst.removeSymbol("tst4");
	if(err!=0) printError(err);
	err = lst.removeSymbol("tst6");
	if(err!=0) printError(err);
	err = lst.removeSymbol("tst8");
	if(err!=0) printError(err);
	err = lst.removeSymbol("tst10");
	if(err!=0) printError(err);
	lst.print();
	err = lst.removeSymbol("abc");
	if(err!=0) printError(err);

	// Test copyMyName
	s1.copyMyName(&tmpname);
	cout << "\n\nTesting copyMyName.  s1 name is:" << tmpname;

	cin >> err;

	return 0;
}