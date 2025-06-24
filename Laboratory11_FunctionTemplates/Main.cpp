#include <iostream>  // input/output
#include <fstream>   // external files support
#include <string>    // string
#include <vector>    // vector
#include <map>       // map
using namespace std; // saves the "std::" clutter

#include "PlayerCharacter.h"  // needed for each header file
#include "PlayerCharacter_Wizard.h"
#include "PlayerCharacter_Warrior.h"
#include "NonPlayerCharacter.h"
#include "NonPlayerCharacter_Caster.h"
#include "DefendYourselfTrigger.h"
#include "FieldModifier.h"

template <typename T>
T getHigherStat(T a, T b)
{
    if (a > b) 
    {
        return a;
    }
    else
    {
        return b;
    }
    
}

int main()
{
    cout << "Wizard: " << endl;
    Wizard* wizard = new Wizard(10, 20, Career::Knight, 4.2);
    cout << wizard->gethealth() << " " << wizard->getdefense() << " "; wizard->getcreer();
    cout << endl << wizard->getlanguageMagic() << endl;

    cout << "Caster" << endl;
    Caster* caster = new Caster(2, 10, Creature::RestlessDead, 8.2);
    cout << caster->getdamage() << " " << caster->getattack() << " "; caster->getcreature();
    cout << endl << caster->getDispelling() << endl;

    cout << endl << "Get Higher Stat: " << endl;
    cout << "Health vs Damage: " << getHigherStat(wizard->gethealth(), caster->getdamage()) << endl;
    cout << "Defence vs Attack: " << getHigherStat(wizard->getdefense(), caster->getattack()) << endl;
    cout << "Magic points: " << getHigherStat(wizard->getlanguageMagic(), caster->getDispelling()) << endl;

    cout << endl << "Increasing a field: " << endl;
    FieldModifier<int>* modifier = new FieldModifier<int>();
    modifier->set(5);
    cout << modifier->get() << endl;

    //cout << endl;
    //FieldModifier<Wizard>* playerFieldModifier = new FieldModifier<Wizard>();
    ////playerFieldModifier->increaseHealth(wizard);
    //playerFieldModifier->increaseHealth();

    return 0;
}
