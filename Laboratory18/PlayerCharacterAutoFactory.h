#pragma once

#include <iostream>  // input/output
#include <fstream>   // external files support
#include <string>    // string
#include <vector>    // vector
#include <map>       // map
using namespace std; // saves the "std::" clutter

#include "PlayercharacterFactory.h" // allowing refrence to outher classes
#include "PlayerCharacter.h"
#include "PlayerCharacter_Wizard.h"

namespace GAMEGANGINE // namespace
{
    template <class T>
    class PlayerCharacterAutoFactory : public PlayerCharacterFactory // the class, being child class of other public class
    {
    public:
        PlayerCharacter* createPlayerCharacter(int in_health, int in_defense, Career in_class, float in_classPoints) override
        {
            return new T(in_health, in_defense, in_class, in_classPoints);
        }
    };
}