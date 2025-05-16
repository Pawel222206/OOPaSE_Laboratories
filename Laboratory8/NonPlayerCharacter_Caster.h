#pragma once // Why?

#include <iostream>  // input/output
#include <fstream>   // external files support
#include <string>    // string
#include <vector>    // vector
#include <map>       // map
using namespace std; // saves the "std::" clutter

#include "NonPlayerCharacter.h"

class Caster : public NonPlayerCharacter // for now public to make it simple, change later
{
private:
    int Dispelling;

public:
    Caster(int in_damage, int in_attack, Creature in_creature) : NonPlayerCharacter(in_damage, in_attack, in_creature) {}
    int getDispelling() { return Dispelling; };
    string getMagicColour(int in_creature);
};