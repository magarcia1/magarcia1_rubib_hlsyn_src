/**************************************************************************************************/

/*
* File: Components.cpp
* Author: Miguel A. Garcia & Rubib Ballesteros
* NetID: magarcia1
* Assignment #: 5
* Date: December/10/2014
*
* Description: Component.cpp contains the class definition of the Component section that lists all nodes
* in the graph. Each component has a unique integer id.
*
*/

/**************************************************************************************************/

#include <iostream>
#include <fstream>
#include <sstream>
#include "Component.h"


//------------------------------------------------------------------------------------------------

using namespace std;

//------------------------------------------------------------------------------------------------

Component::Component() {
	this->type = "none";
	this->name = "default";
	this->output = NULL;
	this->sizeoOutput = 0;

}
Component::Component(string atype, string aname) {
	this->type = atype;
	this->name = aname;
	if (this->type[this->type.length()] != '\0') {
		type[type.length()] = '\0';
	}
	if (name[name.length()] != '\0') {
		name[name.length()] = '\0';
	}

	this->output = NULL;
	this->sizeoOutput = 0;
}

Component::~Component() {

	unsigned int i = 0;
	type = "";
	name = "";
	sizeoOutput = 0;
	for (i = 0; i < this->inputs.size(); ++i){
		delete inputs[i];
	}
	inputs.clear();
	delete output;
	output = NULL;

}
void Component::setType(string type) {
	this->type = type;
}

void Component::setName(string name) {
	this->name = name;
}

void Component::insertInput(Inoutput* anInput) {
	this->inputs.push_back(anInput);
}

void Component::setOutput(Inoutput* anOutput) {
	this->output = anOutput;
}

void Component::setSize(int theSize) {
	this->sizeoOutput = theSize;
}
//------------------------------------------------------------------------------------------------