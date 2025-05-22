#pragma once

#include <iostream>  // input/output
#include <fstream>   // external files support
#include <string>    // string
#include <vector>    // vector
#include <map>       // map
using namespace std; // saves the "std::" clutter

#include "PlayerCharacter.h" // allowing refrence to outher classes
#include "PlayerCharacter_Wizard.h"

namespace GAMEGANGINE // namespace
{
    class PlayerCharacterFactory // the class
    {
    public:
        virtual PlayerCharacter* createPlayerCharacter(int in_health, int in_defense, Career in_class, float in_classPoints) = 0; // creator (why use create?)
        virtual ~PlayerCharacterFactory() {} // destructor
    };
}