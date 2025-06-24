#pragma once // Needed so that the class is initiated only once no matter how many times the program is thrown here during the process

#include <iostream>  // input/output
#include <fstream>   // external files support
#include <string>    // string
#include <vector>    // vector
#include <map>       // map
using namespace std; // saves the "std::" clutter

#include "PlayerCharacter.h"

namespace GAMEGANGINE
{
    class Warrior : public PlayerCharacter
    {
    private:
        float fightingPionts;

    public:
        Warrior(int in_health, int in_defense, Career in_class, float in_fightingPionts) : PlayerCharacter(in_health, in_defense, in_class), fightingPionts(in_fightingPionts) {}
        float getFightingPoints() override { return fightingPionts; };

        void defend() override;
    };
}

