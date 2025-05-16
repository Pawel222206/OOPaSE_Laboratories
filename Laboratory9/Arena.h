#pragma once // IMPORTANT

#include <iostream>  // input/output
#include <fstream>   // external files support
#include <string>    // string
#include <vector>    // vector
#include <map>       // map
using namespace std; // saves the "std::" clutter

#include "PlayerCharacter.h"
#include "PlayerCharacter_Wizard.h"
#include "NonPlayerCharacter.h"
#include "NonPlayerCharacter_Caster.h"

class Arena
{
private:
    PlayerCharacter champion;
    NonPlayerCharacter oponent;

public:
    Arena(PlayerCharacter in_champion, NonPlayerCharacter in_oponent)
    {
        champion = in_champion;
        oponent = in_oponent;
    }

    void compareStats();
};