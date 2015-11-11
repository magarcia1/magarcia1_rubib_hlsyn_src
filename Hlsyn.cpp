/**************************************************************************************************/

/*
* File: Hlsyn.cpp
* Author: Miguel A. Garcia & Rubi Ballesteros
* NetID: magarcia1
* Assignment #: 3
* Date: December/10/2014
*
* Description: Hlsyn contains the required definitions of the Hlsyin class to successfully parse the content
* provided as an argument at the beginning of the execution of our program. In particular, we are interested in
* extracting the information about the Components and Dependencies existing within the file provided.
*
*/

/**************************************************************************************************/

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <sstream>

/***********************************************************************/

#include "Hlsyn.h"
#include "Component.h"
#include "Inoutput.h"
//#include "graph.h"

using namespace std;

/***********************************************************************/

//Parse Components and Dependencies.
//If unable to read file, the vector will be of size 0 
bool ReadFromFile(Graph& myGraph, std::string filename){

	Inoutput* iov;
	istringstream inSS;
	fstream input;                     //Input file stream
	string lineString = "";
	string words[18];
	int myId = 0;
	int size = 0;
	int startId = 0, endId = 0;
	bool flag = true;

	input.open(filename.c_str());

	if (input.is_open()) {
		while (!input.eof()){

			for (int i = 0; i < 18; i++) {
				words[i].clear();
			}

			getline(input, lineString);
			istringstream inStringS(lineString);

			//parse line
			inStringS >> words[0] >> words[1] >> words[2] >> words[3] >> words[4] >> words[5] >> words[6]
				>> words[7] >> words[8] >> words[9] >> words[10] >> words[11] >> words[12] >> words[13]
				>> words [14] >> words[15] >> words[16] >> words [17];
				
			//Ignore Empty Lines DONE----------------------------------------------------------------------
			if (words[0] == "") {
				continue;
			}
			//Ignore // (comments) DONE---------------------------------------------------------------------
			else if (words[0] == "//") {
				continue;
			}

			//Handle if statement---------------------------------------------------------------------------------
			else if(words[0]=="if"){
				//******strip variable of parenthesis
				if (words[1].at(0) == '(') {
					words[1] = words[1].erase(0);
				}
				if (words[1].at(words[1].length()) == ')') {
					words[1] = words[1].erase(words[1].size() - 1);
				}

				//Check condition of parenthesis
				if (words[1]!="0"){
					continue;
				}
				else {
					bool InIf = true;
					while (InIf) {
						getline(input, lineString);
						if (lineString == "}") {
							InIf = false;
						}
					}
				}
			}
			
			//Detect Input, Output, or Variable Statement DONE-----------------------------------------------------
			else if ((words[0] == "input") || (words[0] == "output") || (words[0] == "variable")) {
				bool signedNum = true;

				//Set width length for signed------------------------
				if (words[1] == "Int2") {
					words[1] = "[1:0]";
					size = 2;
				}
				else if (words[1] == "Int1") {
					words[1] = "";
					size = 1;
				}
				else if (words[1] == "Int8") {
					words[1] = "[7:0]";
					size = 8;
				}
				else if (words[1] == "Int16") {
					words[1] = "[15:0]";
					size = 16;
				}
				else if (words[1] == "Int32") {
					words[1] = "[31:0]";
					size = 32;
				}
				else if (words[1] == "Int64") {
					words[1] = "[63:0]";
					size = 64;
				}

				//Set width length for unsigned------------------------
				if (words[1] == "UInt2") {
					words[1] = "[1:0]";
					size = 2;
					signedNum = false;
				}
				else if (words[1] == "UInt1") {
					words[1] = "";
					size = 1;
					signedNum = false;
				}
				else if (words[1] == "UInt8") {
					words[1] = "[7:0]";
					size = 8;
					signedNum = false;
				}
				else if (words[1] == "UInt16") {
					words[1] = "[15:0]";
					size = 16;
					signedNum = false;
				}
				else if (words[1] == "UInt32") {
					words[1] = "[31:0]";
					size = 32;
					signedNum = false;
				}
				else if (words[1] == "UInt64") {
					words[1] = "[63:0]";
					size = 64;
					signedNum = false;
				}
				//for loop to finish reading an definite (16) amount of inputs/outputs listed in a lines.
				bool stop = false;

				for (int j = 0; !stop && (j <= 17); j++){

					if (words[j] == words[0] || words[j] == words[1]) { //ignore the first two words we've seen
						continue;
					}
					else if (words[j] == "") {
						stop = true;
					}
					else {
						//remove the comma if there is one in "input a, b,".
						if (words[j].at(words[j].length() - 1) == ',') {
							words[j] = words[j].erase(words[j].size() - 1);
						}

						//Create class object and insert to DP*****
						iov = new Inoutput(words[j], words[1], words[0], size);
						iov->setSign(signedNum);
						myGraph.insertPut(iov);
					}
				}
			}	
			//TODO: Detect components & create corresponding Scheduling Graph---------------------------------------
			// ADD, SUB, MUL, REG, SHR, SHL, COMP
			else if (words[1] == "=") {

				int Vnumber = myGraph.getCompSize() + 1;

				// ADDER/SUBTRACTOR *************************************************************
				if (words[3] == "+" || words[3] == "-") {
					Component* adder;
					Inoutput* a;
					Inoutput* b;
					Inoutput* c;

					stringstream CName;

					CName << "V" << Vnumber; //guarantees unique name
					adder = new Component(Vnumber, "adder/subtractor", CName.str());

					a = myGraph.getInput(words[2]);
					b = myGraph.getInput(words[4]);
					c = myGraph.getOutput(words[0]);

					if (a == NULL || b == NULL || c == NULL) { //if the input/outputs/wire not found
						cout << "input/output/variable of an adder/subtractor componet does not exist" <<endl;
						return false;
					}

					adder->insertInput(a);
					adder->insertInput(b);
					adder->setOutput(c);
					adder->setLatency(1); //One cycle latency specified
					adder->setOperation(lineString);
					myGraph.insertComponent(adder);

				}
				// MULTIPLIER ********************************************************************
				if (words[3] == "*") {
					Component* mult;
					Inoutput* a;
					Inoutput* b;
					Inoutput* c;

					stringstream CName;

					CName << "V" << Vnumber; //guarantees unique name
					mult = new Component(Vnumber, "multiplier", CName.str());

					a = myGraph.getInput(words[2]);
					b = myGraph.getInput(words[4]);
					c = myGraph.getOutput(words[0]);

					if (a == NULL || b == NULL || c == NULL) { //if the input/outputs/wire not found
						cout << "input/output/variable of a multiplier componet does not exist" << endl;
						return false;
					}

					mult->insertInput(a);
					mult->insertInput(b);
					mult->setOutput(c);
					mult->setLatency(2); //One cycle latency specified
					mult->setOperation(lineString);
					myGraph.insertComponent(mult);

				}
				// DIVIDER/MODULO ****************************************************************
				if (words[3] == "/" || words[3] == "%") {
					Component* div;
					Inoutput* a;
					Inoutput* b;
					Inoutput* c;

					stringstream CName;

					CName << "V" << Vnumber; //guarantees unique name
					div = new Component(Vnumber, "divider/modulo", CName.str());

					a = myGraph.getInput(words[2]);
					//b = myGraph.searchforEdge(words[4]);
					c = myGraph.getOutput(words[0]);

					if (a == NULL || c == NULL) { //if the input/outputs/wire not found
						cout << "input/output/variable of a multiplier componet does not exist" << endl;
						return false;
					}

					div->insertInput(a);
					//mult->insertInput(b);
					div->setOutput(c);
					div->setLatency(3); //One cycle latency specified
					div->setOperation(lineString);
					myGraph.insertComponent(div);

				}
				// LOGICAL ***********************************************************************
				if (words[3] == ">" || words[3] == "<" || words[3] == "<<" || words[3] == ">>"
					|| words[3] == "==" || words[3] == "?") {
					Component* logic;
					Inoutput* a;
					Inoutput* b;
					Inoutput* c;
					Inoutput* d;

					stringstream CName;

					CName << "V" << Vnumber; //guarantees unique name
					logic = new Component(Vnumber, "logic", CName.str());
					if (words[3] == "?") {
						a = myGraph.getInput(words[2]);
						b = myGraph.getInput(words[4]);
						c = myGraph.getInput(words[6]);
						d = myGraph.getOutput(words[0]);

						if (a == NULL || b == NULL || c == NULL || d == NULL) { //if the input/outputs/wire not found
							cout << "input/output/variable of a multiplier componet does not exist" << endl;
							return false;
						}

						logic->insertInput(a);
						logic->insertInput(b);
						logic->insertInput(c);
						logic->setOutput(d);
						logic->setLatency(1); //One cycle latency specified
						logic->setOperation(lineString);
						myGraph.insertComponent(logic);
					}
					else {
						a = myGraph.getInput(words[2]);
						b = myGraph.getInput(words[4]);
						c = myGraph.getOutput(words[0]);

						if (a == NULL || b == NULL || c == NULL) { //if the input/outputs/wire not found
							cout << "input/output/variable of a multiplier componet does not exist" << endl;
							return false;
						}

						logic->insertInput(a);
						logic->insertInput(b);
						logic->setOutput(c);
						logic->setLatency(1); //One cycle latency specified
						logic->setOperation(lineString);
						myGraph.insertComponent(logic);
					}

					

				}
			}

		}
	}
	else {
		cout << "Sorry, I was not able to open the file for you." << endl;
		flag = false;
	}

	return flag;
}

bool ConnectGraph(Graph& myGraph) {
	Component* NOPhead;
	NOPhead = new Component(0, "head", "NOP");

	Component* NOPtail;
	NOPtail = new Component(0, "tail", "NOP");
	

	//Set predecessor and successor
	for (int i = 0; i < myGraph.getCompSize(); i++) {
		Component* currComp1;
		currComp1 = myGraph.getComponent(i);
		for (int j = 1; j < myGraph.getCompSize(); j++) {
			Component* currComp2;
			currComp2 = myGraph.getComponent(j);
			for (int k=0; k < currComp2->getInputSize(); k++) {
				Inoutput* currInput;
				currInput = currComp2->getInput(k);
				if (currComp1->getOutput() == currInput) {
					currComp1->addSuccessor(currComp2);
					currComp2->addPredecessor(currComp1);
				}
			}
		}
	}
	//Connect input type Inoutput objects to NULL
	for (int i = 0; i < myGraph.getCompSize(); i++) {
		Component* currComp;
		currComp = myGraph.getComponent(i);

		if (currComp->getPredecessorSize() == 0) {
			NOPhead->addSuccessor(currComp);
			currComp->addPredecessor(NOPhead);
		}

		if (currComp->getSuccessorSize() == 0) {
			NOPtail->addPredecessor(currComp);
			currComp->addSuccessor(NOPtail);
		}


	}
	
	myGraph.insertComponent(NOPhead);
	myGraph.insertComponent(NOPtail);
	return true;
}

bool ALAPSchedule(Graph& myGraph, int alatency) {
	vector<Component*> queue;
	Component* tail;
	Component* head;
	Component* currComp;
	tail = myGraph.getComponent(myGraph.getCompSize() - 1);
	head = myGraph.getComponent(myGraph.getCompSize() - 2);
	tail->setScheduled(alatency + 1);
	



}
bool CheckSuccScheduled(Component* acomponent) {
	Component* currComp;

	for (int i; i < acomponent->getSuccessorSize(); i++) {
		currComp = acomponent->getSuccessor(i);
		if (currComp->getScheduled == -1) {
			return false;
		}
	}

	return true;
}