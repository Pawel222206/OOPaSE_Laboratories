#include <iostream>  // input/output
#include <fstream>   // external files support
#include <string>    // string
#include <vector>    // vector
#include <map>       // map
using namespace std; // saves the "std::" clutter

#include "NonPlayerCharacter.h" // needed for each header file
#include "NonPlayerCharacter_Caster.h"
#include "PlayerCharacter.h"
#include "PlayerCharacter_Wizard.h"
#include "Arena.h"

void Arena::compareStats()
{
    cout << "Arena Combat: " << endl;
    if (champion.getdefense() > oponent.getattack())
    {
        cout << "Champion defends themselves!" << endl;
    }
    else if (champion.getdefense() == oponent.getattack())
    {
        cout << "Draw..." << endl;
    }
    else
    {
        cout << "Oponent defets the champion!" << endl;
    }
    cout << endl;
}