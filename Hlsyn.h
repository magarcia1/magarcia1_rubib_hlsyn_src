/**************************************************************************************************/

/*
* File: Hlsyin.h
* Author: Miguel A. Garcia & Rubi Ballesteros
* NetID: magarcia1
* Assignment #: 3
* Date: November/1172014
*
* Description: Hlsyin contains the required class declaration to successfully parse the content provided
* as an argument at the beginning of the execution of our program. 
*/

/**************************************************************************************************/


#ifndef HLSYN_H
#define HLSYN_H

#include <vector>
#include <string>
#include "graph.h"

//class Hlsyn {
//public:
//	//Parse Components and Edges.
//	//If unable to read file, the vector will be of size 0 
bool ReadFromFile(Graph& myGraph, std::string filename);
bool ConnectGraph(Graph& myGraph);


//private:
//	// These are private because there is no need for them in a static 
//	// class.
//	Hlsyn();
//	~Hlsyn();
//};
#endif