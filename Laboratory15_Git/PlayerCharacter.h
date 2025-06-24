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
    void updatehealth(int sufferedDamage);
    int getdefense() { return defense; };
    void getcreer();

    virtual void defend() =0;
    virtual ~PlayerCharacter();
};