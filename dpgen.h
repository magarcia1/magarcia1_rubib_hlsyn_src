//------------------------------------------------------------------------------------------------
//
// Author: Rubi Ballesteros and Miguel Garcia
// Date Created: September 2015
//
// Description: .
//
//------------------------------------------------------------------------------------------------

#ifndef DPGEN_H
#define DPGEN_H

//------------------------------------------------------------------------------------------------
#include <string>
#include "Datapath.h"

using namespace std;
//------------------------------------------------------------------------------------------------

bool ReadfromFile(Datapath &DP, char* FileName);
bool AdjustInputs(Datapath &DP);
bool WritetoFile(Datapath &DP, char* FileName);

//------------------------------------------------------------------------------------------------

#endif

//------------------------------------------------------------------------------------------------