#include <iostream>  // input/output
#include <fstream>   // external files support
#include <string>    // string
#include <vector>    // vector
#include <map>       // map
using namespace std; // saves the "std::" clutter

#include "NonPlayerCharacter.h" // needed for each header file
#include "PlayerCharacter.h"

void PlayerCharacter::updatehealth(int sufferedDamage)
{
    health = health - sufferedDamage;
}

void PlayerCharacter::getcreer()
{
    cout << creer;
}

PlayerCharacter::~PlayerCharacter()
{
    cout << "Deleting PlayerCharacter" << endl;
}