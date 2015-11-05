/**************************************************************************************************/

/*
* File: parser.h
* Author: Miguel A. Garcia & Rubi Ballesteros
* NetID: magarcia1
* Assignment #: 3
* Date: November/1172014
*
* Description: Parser contains the required class declaration to successfully parse the content provided
* as an argument at the beginning of the execution of our program. 
*/

/**************************************************************************************************/


#ifndef PARSER_H
#define PARSER_H

#include <vector>
#include <string>
//#include "graph.h"

class Parser {
public:
	//Parse waypoints and streets.
	//If unable to read file, the vector will be of size 0 
	static Graph* parseFile(std::string filename);


private:
	// These are private because there is no need for them in a static 
	// class.
	Parser();
	~Parser();
};
#endif