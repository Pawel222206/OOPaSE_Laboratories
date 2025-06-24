#include <iostream>  // input/output
#include <fstream>   // external files support
#include <string>    // string
#include <vector>    // vector
#include <map>       // map
using namespace std; // saves the "std::" clutter

#include "DefendYourselfTrigger.h"
#include "PlayerCharacter.h"


namespace GAMEGANGINE
{
	void DefendYourselfTrigger::makePlayerDefend(PlayerCharacter* p)
	{
		p->defend();
	}
}
