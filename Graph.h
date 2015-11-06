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
	
	void addComponent(Component* aComponent) { components.push_back(aComponent); }
	void addEdge(Edge* aEdge) { temp.push_back(aEdge); }

	Component* getComponent(int id) { return this->components.at(id); }
	Edge* getEdge(int num){ return this->temp.at(num); }

	//Check if already exists
	//bool edgeExists(Edge* anEdge);
	//bool componentExists(Component* aComponent);
private:
	//all our Components
	vector<Component*> components;
	//Vector containing the information of the Input and Output edges before being connected
	vector<Edge*> temp;

};

#endif