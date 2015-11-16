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
	vector<Component*> scheduled; //components that are already scheduled
	vector<Component*> toSchedule;//components not yet scheduled
	Component* currComp;
	Component* head;
	int* addSub = new int(1);
	int* divMod = new int(1);
	int* mul = new int(1);
	int* logic = new int(1);
	int* addSubTemp = new int(-1);
	int* divModTemp = new int(-1);
	int* mulTemp = new int(-1);
	int* logicTemp = new int(-1);
	int* timeStep = new int(1);

	if (!ALAPSchedule(aGraph, aLatency)) {
		cout << "ALAP scheduling could not find a suitable schedule" << endl;
		return false;
	}
	timeStep = new int(1);

	head = aGraph.getComponent(0);
	head->setScheduled(0);
	//candidate operations are the successor elements inside the vector schedule 
	//In here, we are pushing the head to the schedule vector (This means we already scheduled the head)
	scheduled.push_back(aGraph.getComponent(0));
	//loop into all the elements of schedule to determine if we should schedule them at the current time 
	for (unsigned int k = 0; k < scheduled.size(); k++){
		//check components inside the schedule vector, "one at a time" 
		currComp = scheduled.at(k);
		//we are pushing the succesors into vecotors of the specific component, we will analyze them later
		for (int i = 0; i < currComp->getSuccessorSize(); i++){
			if (currComp->getSuccessor(i)->getType() == "adder/subtractor"){
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

		//schedule zero zlack operations 
		ZeroSlackScheduling(addSubs, toSchedule, addSub, addSubTemp, timeStep);
		ZeroSlackScheduling(divMods, toSchedule, divMod, divModTemp, timeStep);
		ZeroSlackScheduling(muls, toSchedule, mul, mulTemp, timeStep);
		ZeroSlackScheduling(logics, toSchedule, logic, logicTemp, timeStep);
		//schedule Candidate Operations requiring no additional resources
		ScheduleAvailableOp(addSubs, toSchedule, addSub, addSubTemp, timeStep);
		ScheduleAvailableOp(divMods, toSchedule, divMod, divModTemp, timeStep);
		ScheduleAvailableOp(muls, toSchedule, mul, mulTemp, timeStep);
		ScheduleAvailableOp(logics, toSchedule, logic, logicTemp, timeStep);
		
		for (int i = 0; i < toSchedule.size(); i++){
			toSchedule.at(i)->decrementor();
			if (toSchedule.at(i)->getTimeToSchedule() == 0){
				scheduled.push_back(toSchedule.at(i));
				toSchedule.erase(toSchedule.begin() + i);
				i=i-1;
			}
		}

		*timeStep = *timeStep + 1;
	}


	return true;
}

void ZeroSlackScheduling(vector<Component*>& aComp, vector<Component*>& toSchedule, int* resourceAvailable, int* resourceAvailableTemp, int* timeStep){
	*resourceAvailableTemp = *resourceAvailable;

	for (unsigned int i = 0; i < aComp.size(); i++){
		if (aComp.at(i)->getSlack() == 0){
			if (*resourceAvailableTemp == 0){
				*resourceAvailable = *resourceAvailable + 1;
				//schedule it
				aComp.at(i)->setScheduled(*timeStep);
				toSchedule.push_back(aComp.at(i));
				aComp.erase(aComp.begin() + i);
			}
			else{
				*resourceAvailableTemp = *resourceAvailableTemp - 1;
				//schedule it
				aComp.at(i)->setScheduled(*timeStep);
				toSchedule.push_back(aComp.at(i));
				aComp.erase(aComp.begin() + i);
			}
		}
	}
	
}

void ScheduleAvailableOp(vector<Component*>& aComp, vector<Component*>& toSchedule, int* resourceAvailable, int* resourceAvailableTemp, int* timeStep){
	if (*resourceAvailableTemp == 0){
		return;
	}
	else{
		for (unsigned int i = 0; i < aComp.size(); i++){
			if (*resourceAvailableTemp != 0){
				*resourceAvailableTemp = *resourceAvailableTemp - 1;
				//schedule it
				aComp.at(i)->setScheduled(*timeStep);
				toSchedule.push_back(aComp.at(i));
				aComp.erase(aComp.begin() + i);
			}
			else{
				return;
			}
		}
	}
	return;
}
/**************************************************************************************************/