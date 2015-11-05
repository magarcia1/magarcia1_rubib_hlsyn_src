/**************************************************************************************************/

/*
* File: Edge.cpp
* Author: Miguel A. Garcia
* NetID: magarcia1
* Assignment #: 3
* Date: November/17/2015
*
* Description: Edge.h contains the class declaration of a class named Edge.
*
*/

/**************************************************************************************************/

#include "Edge.h"

/**************************************************************************************************/


Edge::Edge(string aname, string aType, Component* adjComponent) {
	adjComponents.push_back(adjComponent);
	this->name = aname;
	this->type = aType;
	bool signedNum = true;
}

/**************************************************************************************************/
