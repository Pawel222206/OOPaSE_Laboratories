#include <iostream>  // input/output
#include <fstream>   // external files support
#include <string>    // string
#include <vector>    // vector
#include <map>       // map
using namespace std; // saves the "std::" clutter

#include "PlayerCharacter.h"
#include "PlayerCharacter_Wizard.h"
#include "FieldModifier.h"

void Wizard::defend()
{
    cout << "Wizard defends himself with magic!" << endl;
}

int Wizard::defaultHatHeight = 2;