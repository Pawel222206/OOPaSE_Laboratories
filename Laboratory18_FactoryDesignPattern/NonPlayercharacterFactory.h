#pragma once

#include <iostream>  // input/output
#include <fstream>   // external files support
#include <string>    // string
#include <vector>    // vector
#include <map>       // map
using namespace std; // saves the "std::" clutter

#include "NonPlayerCharacter.h" // allowing refrence to outher classes
#include "NonPlayerCharacter_Caster.h"

namespace GAMEGANGINE // namespace
{
    class NonPlayerCharacterFactory // the class
    {
    public:
        virtual NonPlayerCharacter* createNonPlayerCharacter(int in_damage, int in_attack, Creature in_creature, float in_disspelling) = 0; // creator (why use create?)
        virtual ~NonPlayerCharacterFactory() {} // destructor
    };
}