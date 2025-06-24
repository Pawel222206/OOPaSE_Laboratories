#pragma once // Why?

#include <iostream>  // input/output
#include <fstream>   // external files support
#include <string>    // string
#include <vector>    // vector
#include <map>       // map
using namespace std; // saves the "std::" clutter

#include "NonPlayerCharacter.h"

namespace GAMEGANGINE
{
    class Caster : public NonPlayerCharacter // for now public to make it simple, change later
    {
    private:
        float disspelling;

    public:
        Caster() : NonPlayerCharacter(2, 2, Creature::Beast), disspelling(2) {}
        Caster(int in_damage, int in_attack, Creature in_creature, float in_disspelling) : NonPlayerCharacter(in_damage, in_attack, in_creature), disspelling(in_disspelling) {}
        float getDispelling() override { return disspelling; };
        string getMagicColour(int in_creature);

        void attackNow() override;

        ~Caster() override;
    };
}

