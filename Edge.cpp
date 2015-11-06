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
#include <vector>
#include <string>
#include "Edge.h"

/**************************************************************************************************/


//Edge::Edge(string aname, string aType, Component* adjComponent) {
//	this->adjComponents = adjComponent;
//	this->name = aname;
//	this->type = aType;
//	bool signedNum = true;
//}
Edge::Edge()
{

}

Edge::Edge(string name, string sizeSpec, string type, bool signedNumber, int size)
	:name(name), sizeSpec(sizeSpec), type(type), signedNum(signedNumber), size(size)
{

}


/**************************************************************************************************/
