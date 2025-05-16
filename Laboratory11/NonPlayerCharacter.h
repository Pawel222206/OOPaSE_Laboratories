#pragma once

#include <iostream>  // input/output
#include <fstream>   // external files support
#include <string>    // string
#include <vector>    // vector
#include <map>       // map
using namespace std; // saves the "std::" clutter

enum Creature
{
    Beast,
    MosnstrusBeast,
    Greenskin,
    RestlessDead
};

class NonPlayerCharacter
{
private:
    int damage, attack;
    Creature creature;

public:
    NonPlayerCharacter()
    {
        damage = 4;
        attack = 40;
        creature = Creature::Beast;
    }
    NonPlayerCharacter(int in_damage, int in_attack, Creature in_creature)
    {
        damage = in_damage;
        attack = in_attack;
        creature = in_creature;
    }

    int getdamage() { return damage; };
    int getattack() { return attack; };
    void getcreature();
    string getAttackType();

    virtual void attackNow();

    virtual ~NonPlayerCharacter();
};