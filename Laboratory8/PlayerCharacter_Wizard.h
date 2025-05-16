#pragma once // Why?

#include <iostream>  // input/output
#include <fstream>   // external files support
#include <string>    // string
#include <vector>    // vector
#include <map>       // map
using namespace std; // saves the "std::" clutter

#include "PlayerCharacter.h"

class Wizard : public PlayerCharacter // for now public to make it simple, change later
{
private:
    int languageMagic;

public:
    Wizard(int in_health, int in_defense, Career in_class, int in_languageMagic) : PlayerCharacter(in_health, in_defense, in_class), languageMagic(in_languageMagic) {}
    int getlanguageMagic() { return languageMagic; };
    void channelMagic(PlayerCharacter playerCharacter, int in_sacrafisedHealth);
};