/**************************************************************************************************/

/*
* File: Dependencie.h
* Author: Miguel A. Garcia
* NetID: magarcia1
* Assignment #: 3
* Date: November/10/2014
*
* Description: Main controlling a program that translates circuit pseudo code into
* a syntactically correct Verilog implementation.
*/

/**************************************************************************************************/

#include <iostream>
#include <sstream>
#include "Hlsyn.h"
#include "Graph.h"

/**************************************************************************************************/

using namespace std;

/**************************************************************************************************/

int main(int argc, char *argv[])
{
	Graph sequenceGraph;
	//TODO: Check for correct input. DONE !
	if (argc != 2) {
		cout << "\nUsage: dpgen netlistFile verilogFile \n";
		return -1;
	}
	
	//TODO: Create a file	
	if (!ReadFromFile(sequenceGraph, argv[1])) {
		cout << "Could not finish reading the file due to the errors listed above." << endl;
		return -2;
	}

	return 0;
}
