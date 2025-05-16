#include <iostream>  // input/output
#include <fstream>   // external files support
#include <string>    // string
#include <vector>    // vector
#include <map>       // map
using namespace std; // saves the "std::" clutter

#include "NonPlayerCharacter.h" // needed for each header file
#include "PlayerCharacter.h"

void NonPlayerCharacter::getcreature()
{
    cout << creature;
}

string NonPlayerCharacter::getAttackType()
{
    if (creature == 0)
    {
        return "Claw Slash";
    }
    else if (creature == 1)
    {
        return "Fang Rend";
    }
    else if (creature == 2)
    {
        return "Brutal Smash'n";
    }
    else if (creature == 4)
    {
        return "Undead Bite";
    }
}