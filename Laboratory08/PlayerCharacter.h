#pragma once // IMPORTANT

#include <iostream>  // input/output
#include <fstream>   // external files support
#include <string>    // string
#include <vector>    // vector
#include <map>       // map
using namespace std; // saves the "std::" clutter

#include "NonPlayerCharacter.h"

enum Career
{
    Peasant,
    Knight,
    Priest
};

class PlayerCharacter
{
private:
    int health, defense;
    Career creer;

    /* - we do inheritaqnce instead
    friend class Potions;
    */

public:
    PlayerCharacter()
    {
        health = 12;
        defense = 30;
        creer = Career::Peasant;
    }
    PlayerCharacter(int in_health, int in_defense, Career in_Class)
    {
        health = in_health;
        defense = in_defense;
        creer = in_Class;
    }

    int gethealth() { return health; };
    int getdefense() { return defense; };
    void updatehealth(int sufferedDamage);
    void getcreer();

    friend void combat(PlayerCharacter playerCharacter, NonPlayerCharacter nonPlayerCharacter);
};