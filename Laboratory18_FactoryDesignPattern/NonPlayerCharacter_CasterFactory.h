#pragma once

#include <iostream>  // input/output
#include <fstream>   // external files support
#include <string>    // string
#include <vector>    // vector
#include <map>       // map
using namespace std; // saves the "std::" clutter

#include "NonPlayercharacterFactory.h" // allowing refrence to outher classes
#include "NonPlayerCharacter.h"
#include "NonPlayerCharacter_Caster.h"

namespace GAMEGANGINE // namespace
{
    class NonPlayerCharacter_CasterFactory : public NonPlayerCharacterFactory // the class, being child class of other public class
    {
    public:
        NonPlayerCharacter* createNonPlayerCharacter(int in_damage, int in_attack, Creature in_creature, float in_disspelling) override
        {
            return new Caster(in_damage, in_attack, in_creature, in_disspelling);
            //return new NonPlayerCharacter();
        }
    };
}