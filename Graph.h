/**************************************************************************************************/

/*
* File: graph.h
* Author: Miguel A. Garcia & Rubi Ballesteros
* NetID: magarcia1
* Assignment #: 3
* Date: November/10/2015
*
* Description: Graph.h contains the definition of a class named Graph that consists mainly of
* two sections: Components (nodes) and Inputs/outputs/variables (edges).

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
	bool addEdge(Edge* anEdge) { edges.push_back(anEdge); };
	
	//returns NULL if the Id doesn't exist
	Component* getComponent(int id) { return this->components.at(id); };
	Edge* getEdge(int id) { return this->edges.at(id); };
	
	//Check if already exists
	bool edgeExists(Edge* anEdge);
	bool componentExists(Component* aComponent);
private:
	//all our waypoints
	vector<Component*> components;
	//all our streets
	vector<Edge*> edges;
};

#endif