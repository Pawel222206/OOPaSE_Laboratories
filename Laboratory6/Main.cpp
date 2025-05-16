#include <iostream>  // input/output
#include <fstream>   // external files support
#include <string>    // string
#include <vector>    // vector
#include <map>       // map

using namespace std; // saves the "std::" clutter

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
};

/* old way of doing this
void PlayerCharacter::gethealth()
{
    cout << health;
}
*/

void PlayerCharacter::updatehealth(int sufferedDamage)
{
    health = health - sufferedDamage;
}

void PlayerCharacter::getcreer()
{
    cout << creer;
}

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

int main()
{
    PlayerCharacter* steve = new PlayerCharacter();
    PlayerCharacter* wizard = new PlayerCharacter(10, 20, Career::Wizard);
    //cout << "Steve: " << steve->gethealth(); cout << " "; steve->getcreer(); cout << endl;
    //cout << "Elven Mage: " << wizard->gethealth(); cout << " "; wizard->getcreer();  cout << endl;
    NonePlayerCharacter* mob = new NonePlayerCharacter();
    NonePlayerCharacter* boblinTheGoblin = new NonePlayerCharacter(2, 10, Creature::Greenskin);
    //cout << "Radom mob: " << mob->getdamage(); cout << " "; mob->getcreature(); cout << endl;
    //cout << "Boblin The Goblin: " << boblinTheGoblin->getdamage(); cout << " "; boblinTheGoblin->getcreature();  cout << endl;

    cout << "Mortla Combat: " << endl;
    if (mob->getattack() > steve->getdefense())
    {
        cout << "Hit! ";
        steve->updatehealth(mob->getdamage());
        mob->getcreature(); cout << " hit the "; steve->getcreer(); cout << " with " << mob->getAttackType(); cout << endl;
        steve->getcreer(); cout << " has " << steve->gethealth() << " health remaining";
    }
    else {
        cout << "Miss...";
    }

    //dopiesz po 2 warotœci: klasa z klasy i coœtam jeszcze tylko ¿eby dobiæ do 5 properties
    //dodaj destructor jak ktoœ umiera
    //zrób przyk³ad z tym jak ktoœ umiera ¿eby go zdekonstruktowaæ



    return 0;
}