#include <iostream>  // input/output
#include <fstream>   // external files support
#include <string>    // string
#include <vector>    // vector
#include <map>       // map
using namespace std; // saves the "std::" clutter

#include "PlayerCharacter.h"
#include "PlayerCharacter_Wizard.h"

void Wizard::channelMagic(PlayerCharacter playerCharacter, int in_sacrafisedHealth)
{
    cout << "Starting health: " << playerCharacter.gethealth() << endl;
    playerCharacter.updatehealth(in_sacrafisedHealth);
    languageMagic = in_sacrafisedHealth;
    cout << "Health after channeling: " << playerCharacter.gethealth() << endl;
    cout << "Language after channeling: " << languageMagic << endl;
}
