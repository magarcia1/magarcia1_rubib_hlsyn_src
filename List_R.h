/**************************************************************************************************/

/*
* File: List_R.h
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

/**************************************************************************************************/

bool List_R(Graph& aGraph, int aLatency);
void ZeroSlackScheduling(vector<Component*> aComp, vector<Component*> toSchedule, int* resourceAvailable, int* resourceAvailableTemp, int* timeStep);
void ScheduleAvailableOp(vector<Component*> aComp, vector<Component*> toSchedule, int* resourceAvailable, int* resourceAvailableTemp, int* timeStep);

/**************************************************************************************************/