/**************************************************************************************************/

/*
* File: graph.h
* Author: Miguel A. Garcia & Rubi Ballesteros
* NetID: magarcia1
* Assignment #: 3
* Date: November/10/2015
*
* Description: Graph.h contains the definition of a class named Graph 

*
*/

/**************************************************************************************************/

#ifndef	GRAPH_H
#define GRAPH_H

#include <vector>
#include <string>
#include "Component.h"
#include "Edge.h"

using namespace std;

class Graph{
public:
	Graph();
	
	bool addComponent(Component* aComponent) { components.push_back(aComponent);};
	
	//returns NULL if the Id doesn't exist
	Component* getComponent(int id) { return this->components.at(id); };
	
	//Check if already exists
	//bool edgeExists(Edge* anEdge);
	//bool componentExists(Component* aComponent);
private:
	//all our Components
	vector<Component*> components;

};

#endif