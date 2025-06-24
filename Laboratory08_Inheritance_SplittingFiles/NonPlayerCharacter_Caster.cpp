#include <iostream>  // input/output
#include <fstream>   // external files support
#include <string>    // string
#include <vector>    // vector
#include <map>       // map
using namespace std; // saves the "std::" clutter

#include "NonPlayerCharacter.h"
#include "NonPlayerCharacter_Caster.h"

string Caster::getMagicColour(int in_creature)
{
    cout << "The Caster defends with ";
    if (in_creature == 0)
    {
        return "Brown Magic";
    }
    else if (in_creature == 1)
    {
        return "Red Magic";
    }
    else if (in_creature == 2)
    {
        return "Green Magic";
    }
    else if (in_creature == 3)
    {
        return "Purple Magic";
    }
    cout << " magic" << endl;
}   