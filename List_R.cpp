/**************************************************************************************************/

/*
* File: List_R.cpp
* Author: Miguel A. Garcia
* NetID: magarcia1
* Assignment #: 3
* Date: November/10/2014
*
* Description:
*/

/**************************************************************************************************/

#include <iostream>
#include <sstream>
#include "Graph.h"
#include "List_R.h"

#include "Hlsyn.h"

/**************************************************************************************************/

bool List_R(Graph& aGraph, int aLatency){
	vector<Component*> addSubs;
	vector<Component*> divMods;
	vector<Component*> muls;
	vector<Component*> logics;
	vector<Component*> scheduled;

	Component* currComp;
	Component* head;
	int* addSub = new int(1);
	int* divMod = new int(1);
	int* mul = new int(1);
	int* logic = new int(1);
	int* timeStep = new int(1);

	if (!ALAPSchedule(aGraph, aLatency)) {
		cout << "ALAP scheduling could not find a suitable schedule" << endl;
		return false;
	}
	timeStep = new int(1);

	head = aGraph.getComponent(0);
	head->setScheduled(0);

	scheduled.push_back(aGraph.getComponent(0));

	for (unsigned int k = 0; k < scheduled.size(); k++){
		currComp = scheduled.at(k);
		for (unsigned int i = 0; i < currComp->getSuccessorSize(); i++){
			if (currComp->getSuccessor(i)->getType() == "adder/subtracter"){
				currComp->getSuccessor(i)->setSlack(currComp->getSuccessor(i)->getScheduled() - *timeStep);
				addSubs.push_back(currComp->getSuccessor(i));
			}
			else if (currComp->getSuccessor(i)->getType() == "multiplier"){
				currComp->getSuccessor(i)->setSlack(currComp->getSuccessor(i)->getScheduled() - *timeStep);
				muls.push_back(currComp->getSuccessor(i));
			}
			else if (currComp->getSuccessor(i)->getType() == "divider/modulo"){
				currComp->getSuccessor(i)->setSlack(currComp->getSuccessor(i)->getScheduled() - *timeStep);
				divMods.push_back(currComp->getSuccessor(i));
			}
			else if (currComp->getSuccessor(i)->getType() == "logic"){
				currComp->getSuccessor(i)->setSlack(currComp->getSuccessor(i)->getScheduled() - *timeStep);
				logics.push_back(currComp->getSuccessor(i));
			}
			
		}
		//For add and Sub
		ZeroSlackScheduling(addSubs, addSub, timeStep);
		//For divMod
		ZeroSlackScheduling(divMods, divMod, timeStep);
		//For mul
		ZeroSlackScheduling(muls, mul, timeStep);
		//For logic
		ZeroSlackScheduling(logics, logic, timeStep);
	}

	return true;
}

void ZeroSlackScheduling(vector<Component*> aComp, int* resourceAvailable, int* timeStep){
	int temp = *resourceAvailable;

	for (unsigned int i = 0; i < aComp.size(); i++){
		if (aComp.at(i)->getSlack() == 0){
			if (temp == 0){
				*resourceAvailable = *resourceAvailable + 1;
				//schedule it
				aComp.at(i)->setScheduled(*timeStep);
			}
			else{
				temp = temp - 1;
				//schedule it
				aComp.at(i)->setScheduled(*timeStep);
			}
		}
	}

}

/**************************************************************************************************/