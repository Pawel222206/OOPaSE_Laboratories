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

void combat(PlayerCharacter playerCharacter, NonPlayerCharacter nonPlayerCharacter)
{
    //cout << "Mortla Combat: " << playerCharacter.health << " " << nonPlayerCharacter.getdamage() << endl;

    cout << "Mortla Combat: " << endl;
    if (nonPlayerCharacter.getattack() > playerCharacter.getdefense())
    {
        cout << "Hit! ";
        playerCharacter.updatehealth(nonPlayerCharacter.getdamage());
        nonPlayerCharacter.getcreature(); cout << " hit the "; playerCharacter.getcreer(); cout << " with " << nonPlayerCharacter.getAttackType(); cout << endl;
        playerCharacter.getcreer(); cout << " has " << playerCharacter.gethealth() << " health remaining" << endl;
    }
    else {
        cout << "Miss..." << endl;
    }
}

void PlayerCharacter::defend()
{
    cout << "Player Character defends himself" << endl;
}

PlayerCharacter::~PlayerCharacter()
{
    cout << "Deleting PlayerCharacter" << endl;
}

/* - we do inheritaqnce instead
class Potions
{
public:
    void healingPotion(PlayerCharacter& playerCharacter, int healedWounds)
    {
        cout << "Healing potion used: " << healedWounds << " wounds healed!" << endl;
        playerCharacter.health += healedWounds;
        // playerCharacter.updatehealth(-healedWounds);
    }
};
*/