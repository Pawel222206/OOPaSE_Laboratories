#include <iostream>  // input/output
#include <fstream>   // external files support
#include <string>    // string
#include <vector>    // vector
#include <map>       // map

using namespace std; // saves the "std::" clutter

/////////////////////////////////////////////////////////////////////////////////////

enum Creature
{
    Beast,
    MosnstrusBeast,
    Greenskin,
    RestlessDead
};

////////////////////////////////////////////

class NonePlayerCharacter
{
private:
    int damage, attack;
    Creature creature;

public:
    NonePlayerCharacter()
    {
        damage = 4;
        attack = 40;
        creature = Creature::Beast;
    }
    NonePlayerCharacter(int in_damage, int in_attack, Creature in_creature)
    {
        damage = in_damage;
        attack = in_attack;
        creature = in_creature;
    }

    int getdamage() { return damage; };
    int getattack() { return attack; };
    void getcreature();
    string getAttackType();

}
;
void NonePlayerCharacter::getcreature()
{
    cout << creature;
}

string NonePlayerCharacter::getAttackType()
{
    if (creature == 0)
    {
        return "Claw Slash";
    }
    else if (creature == 1)
    {
        return "Fang Rend";
    }
    else if (creature == 2)
    {
        return "Brutal Smash'n";
    }
    else if (creature == 4)
    {
        return "Undead Bite";
    }
}

/////////////////////////////////////////////////////////////////////////////////////

enum Career
{
    Wizard,
    Peasant,
    Knight,
    Priest
};

/////////////////////////////////////////////

class PlayerCharacter
{
private:
    int health, defense;
    Career creer;
    friend class Potions;

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

    friend void combat(PlayerCharacter playerCharacter, NonePlayerCharacter nonPlayerCharacter);
};

void PlayerCharacter::updatehealth(int sufferedDamage)
{
    health = health - sufferedDamage;
}

void PlayerCharacter::getcreer()
{
    cout << creer;
}

void combat(PlayerCharacter playerCharacter, NonePlayerCharacter nonPlayerCharacter)
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

/////////////////////////////////////////////////////////////////////////////////////

int main()
{
    PlayerCharacter* steve = new PlayerCharacter();
    PlayerCharacter* wizard = new PlayerCharacter(10, 20, Career::Wizard);

    NonePlayerCharacter* mob = new NonePlayerCharacter();
    NonePlayerCharacter* boblinTheGoblin = new NonePlayerCharacter(2, 10, Creature::Greenskin);

    combat(*steve, *mob);

    cout << "Wizard has: " << wizard->gethealth() << " wounds." << endl;
    Potions healingDrought;
    healingDrought.healingPotion(*wizard, 9);
    cout << "Wizard has: " << wizard->gethealth() << " wounds." << endl;

    //dopisz po 2 u¿ycia friend function i friend class

    return 0;
}