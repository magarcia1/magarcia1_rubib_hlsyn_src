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
#include "Parser.h"
#include "dpgen.h"
#include "Edge.h"
#include "Graph.h"

/**************************************************************************************************/

using namespace std;

/**************************************************************************************************/

int main(int argc, char *argv[])
{
	Graph* sequenceGraph = NULL;
	//TODO: Check for correct input. DONE !
	if (argc != 3) {
		cout << "\nUsage: dpgen netlistFile verilogFile \n";
		return -1;
	}
	//TODO: Create a file
	sequenceGraph = Parser::parseFile(argv[3]);


	return 0;
}
