/**************************************************************************************************/

/*
* File: Components.h
* Author: Miguel A. Garcia & Rubi Ballesteros
* NetID: magarcia1
* Assignment #: 5
* Date: November/17/2015
*
* Description: Component.h contains the class declaration of the Component section that lists all nodes
* in the graph. Each component has a unique integer id. 
*
*/

/**************************************************************************************************/

#ifndef COMPONENT_H
#define COMPONENT_H

//------------------------------------------------------------------------------------------------
#include <string>
#include <vector>
#include "Inoutput.h"

using namespace std;
//------------------------------------------------------------------------------------------------

class Component {
private:
	int id;		//our unique identifier
	int latency;
	//int size;       //size of the component as an integer
	vector<Inoutput*> inputs;
	vector<Component*> predecessors;
	vector<Component*> successors;
	Inoutput* output;
	string type;
	string name;
	//string compSize; //size of the component as a string
	string operation;

	int scheduled;

public:
	//The rest of the big 4 are auto-generated by the compiler

	//Only this way-point needs to be created
	//Initialization 
	Component();
	Component(int id, string atype, string aname);
	~Component();

	void setId(int newId) { this->id = newId; }
	void setLatency(int newLatency) { this->latency = newLatency;  }
	//void setSize(int theSize) { this->size = theSize; }
	void insertInput(Inoutput* anInput) { this->inputs.push_back(anInput); };
	void replaceInput(int i, Inoutput* newPut) { this->inputs.at(i) = newPut; }
	void setOutput(Inoutput* anOutput) { this->output = anOutput; };
	void setType(string type) { this->type = type; };
	void setName(string name) { this->name = name; }
	//void setCompSize(string newCompSize) { this->compSize = newCompSize; }
	void setOperation(string anOperation) { this->operation = anOperation; }
	void setScheduled(int i) { this->scheduled = i; };
	
	int getId() { return this->id; }
	int getLatency(){ return this->latency; }
	//int getSize() { return this->size; }
	int getInputSize() { return this->inputs.size(); }
	Inoutput* getInput(int i) { return this->inputs.at(i); }
	Inoutput* getOutput() { return this->output; }
	string getType() { return this->type; }
	string getName() { return this->name; }
	//string getCompSize() { return this->compSize; } 
	string getOperation() { return this->operation; }
	int getScheduled() { return this->scheduled; }

	//Connecting the graph (not finished)
	void addSuccessor(Component* aSuccessor) { this->successors.push_back(aSuccessor); }
	void addPredecessor(Component* aPred) { this->predecessors.push_back(aPred); }
	
	int getSuccessorSize() { return this->successors.size(); }
	int getPredecessorSize() { return this->predecessors.size(); }

	Component* getSuccessor(int i) { return this->successors.at(i); }


};
//------------------------------------------------------------------------------------------------

#endif

//------------------------------------------------------------------------------------------------
