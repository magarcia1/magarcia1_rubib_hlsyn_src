
#include "Edge.h"



Edge::Edge(string aname, string aType, Component* adjComponent) {
	adjComponents.push_back(adjComponent);
	this->name = aname;
	this->type = aType;
	bool signedNum = true;
}