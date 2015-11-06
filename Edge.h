/**************************************************************************************************/

/*
* File: Edge.h
* Author: Miguel A. Garcia
* NetID: magarcia1
* Assignment #: 3
* Date: November/17/2015
*
* Description: Edge.h contains the class declaration of a class named Edge. 
*
*/

/**************************************************************************************************/

#ifndef EDGE_H
#define EDGE_H

#include <vector>
#include <string>

using namespace std;
//Instead of including a Waypoints.h here, we just used tell the compiler "it's a class, don't worry
//about it." This is an example of the usefulness of Forward Declaration.
class Component;

class Edge{
public:
	
	//rest of the big 4 are auto-generated by the compiler
	//only this  edge needs to be created
	Edge();
	//Edge(string aname, string aType, Component* adjComponent);
	Edge(string name, string sizeSpec, string type, bool signedNumber, int size);

	void addAdjComp(Component* aComponent) { this->adjComponents = aComponent; }
	void setName(string aName){ this->name = aName; }
	void setSizeSpec(string aSize) { this->sizeSpec = aSize; }
	void setType(string aType){ this->type = aType; }
	void setSize(int aSize){ this->size = size; }
	void ChangeSign(bool aSign) { this->signedNum = aSign; }	
	
	Component* getAdjComponent() const { return this->adjComponents; }
	string getName() const { return this->name; }
	string getSizeSpec() const { return this->sizeSpec; }
	string getEndId() const { return this->type; }
	int getSize() const { return this->size; }
	bool getSignedNum() const { return this->signedNum; }


private:
	//to whom do I connect?
	Component* adjComponents;
	string name;
	string sizeSpec;
	string type;
	int size;
	bool signedNum;

};

#endif

/***********************************************************************/