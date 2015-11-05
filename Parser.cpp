/**************************************************************************************************/

/*
* File: parser.cpp
* Author: Miguel A. Garcia & Rubi Ballesteros
* NetID: magarcia1
* Assignment #: 5
* Date: December/10/2014
*
* Description: Parser contains the required definitions of the parser class to successfully parse the content
* provided as an argument at the beginning of the execution of our program. In particular, we are interested in
* extracting the information about the Components and Dependencies existing within the file provided.
*
*/

/**************************************************************************************************/

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <sstream>

/***********************************************************************/

#include "parser.h"
#include "Component.h"
#include "Dependencie.h"
#include "graph.h"
using namespace std;

/***********************************************************************/

//Parse Components and Dependencies.
//If unable to read file, the vector will be of size 0 
Graph* Parser::parseFile(std::string filename){
	Graph* graph = new Graph();
	istringstream inSS;
	fstream input;                     //Input file stream
	string lineString = "";
	string words[18];
	int myId = 0;
	int startId = 0, endId = 0;

	input.open(filename.c_str());

	if (input.is_open()) {
		while (!input.eof()){
			getline(input, lineString);
			istringstream inStringS(lineString);

			//parse line
			inStringS >> words[0] >> words[1] >> words[2] >> words[3] >> words[4] >> words[5] >> words[6]
				>> words[7] >> words[8] >> words[9] >> words[10] >> words[11] >> words[12] >> words[13]
				>> words [14] >> words[15] >> words[16] >> words [17];
				
			//Ignore Empty Lines DONE----------------------------------------------------------------------
			if (words[0] == "") {
				continue;
			}
			//Ignore // (comments) DONE---------------------------------------------------------------------
			else if (words[0] == "//") {
				continue;
			}
			
			//Detect Input, Output, or Variable Statement DONE-----------------------------------------------------
			else if ((words[0] == "input") || (words[0] == "output") || (words[0] == "variable")) {
				Inoutput* iow;
				bool signedNum = true;

				//Set width length for signed------------------------
				if (words[1] == "Int2") {
					words[1] = "[1:0]";
					size = 2;
				}
				else if (words[1] == "Int1") {
					words[1] = "";
					size = 1;
				}
				else if (words[1] == "Int8") {
					words[1] = "[7:0]";
					size = 8;
				}
				else if (words[1] == "Int16") {
					words[1] = "[15:0]";
					size = 16;
				}
				else if (words[1] == "Int32") {
					words[1] = "[31:0]";
					size = 32;
				}
				else if (words[1] == "Int64") {
					words[1] = "[63:0]";
					size = 64;
				}
			}	
		}
	}
	else {
		cout << "Sorry, I was not able to open the file for you." << endl;
	}

	return graph;
}