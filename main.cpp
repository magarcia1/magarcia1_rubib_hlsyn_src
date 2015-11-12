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
#include "List_R.h"

/**************************************************************************************************/

using namespace std;

/**************************************************************************************************/

int main(int argc, char *argv[])
{
	Graph sequenceGraph;
	int latency;

	latency = atoi(argv[2]);

	//TODO: Check for correct input. DONE !
	//if (argc != 4) {
	//	cout << "\nUsage: dpgen netlistFile verilogFile \n";
	//	return -1;
	//}
	
	//TODO: Read a file	
	if (!ReadFromFile(sequenceGraph, argv[1])) {
		cout << "Could not finish reading the file due to the errors listed above." << endl;
		return -2;
	}

	//TODO: Connect Graph 
	//(technically this is a SEQUENCE graph where NULL is rep as size 0 vector of
	//either successors or predecessors)
	ConnectGraph(sequenceGraph);

	//TODO: List_R s
	if (!List_R(sequenceGraph, latency)) {
		cout << "ALAP scheduling could not find a suitable schedule" << endl;

	}

	return 0;
}
