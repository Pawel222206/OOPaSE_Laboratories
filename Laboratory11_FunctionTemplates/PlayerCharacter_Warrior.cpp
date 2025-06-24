#include <iostream>  // input/output
#include <fstream>   // external files support
#include <string>    // string
#include <vector>    // vector
#include <map>       // map
using namespace std; // saves the "std::" clutter

#include "PlayerCharacter.h"
#include "PlayerCharacter_Warrior.h"

void Warrior::defend()
{
    cout << "Warrior defends himself with a shield!" << endl;
}