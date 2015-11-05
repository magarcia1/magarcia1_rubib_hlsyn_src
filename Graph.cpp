/**************************************************************************************************/

/*
* File: graph.cpp
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

#include "Graph.h"

using namespace std;

/**************************************************************************************************/

Graph::Graph() {

}

bool Graph::edgeExists(Edge* anEdge) {
	for (int i = 0; i < edges.size(); i++) {
		Edge* edge = edges.at(i);
		if (edge->getName == anEdge->getName) {
			return true;
		}
		return false;
	}
}

bool Graph::componentExists(Component* aComponent) {
	for (int i = 0; i < components.size(); i++) {
		Component* component = components.at(i);
		if (component->getName == aComponent->getName) {
			return true;
		}
		return false;
	}
}

/**************************************************************************************************/