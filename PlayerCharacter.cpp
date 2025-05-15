#include <iostream>  // input/output
#include <fstream>   // external files support
#include <string>    // string
#include <vector>    // vector
#include <map>       // map
using namespace std; // saves the "std::" clutter

#include "NonPlayerCharacter.h" // needed for each header file
#include "PlayerCharacter.h"
#include "FieldModifier.h"

namespace GAMEGANGINE
{
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

    void PlayerCharacter::completeQuest(PlayerCharacter* p, int in_health, int in_languageMagic, int in_difficulty)
    {
        try
        {
            cout << "Checking if quest can be completed (1 measn yes): " << p->completeQuest2(in_health, in_languageMagic, in_difficulty) << endl;
        }
        catch (const logic_error& e)
        {
            cout << e.what() << endl;
        }
    }

    int PlayerCharacter::completeQuest2(int in_health, int in_languageMagic, int in_difficulty)
    {
        if (in_health <= in_difficulty && in_languageMagic <= in_difficulty)
        {
            throw logic_error("You Died");
        }
        return 1;
    }
}

