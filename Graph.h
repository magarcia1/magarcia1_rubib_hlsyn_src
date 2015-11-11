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
#include "Inoutput.h"

using namespace std;

class Graph{
public:
	Graph();
	
	void insertPut(Inoutput* iow);
	void insertComponent(Component* dpcomp);
	Inoutput* getInput(string name);
	Inoutput* getInputat(int i);
	Inoutput* getOutputat(int i);
	Inoutput* getVarat(int i);
	Inoutput* getOutput(string name);
	Component* getComponent(int i);
	int getCompSize();
	int getInpSize();
	int getOutSize();
	int getVarSize();

	void insertComponentAt(Component* comp, int i) { this->components.insert(this->components.begin()+i, comp); }

private:
	//all our Components
	vector<Component*> components;
	//Vector containing the information of the Input and Output edges before being connected
	vector<Inoutput*> inputs;
	vector<Inoutput*> outputs;
	vector<Inoutput*> variables;

};

#endif