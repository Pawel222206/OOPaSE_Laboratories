#include <iostream>  // input/output
#include <fstream>   // external files support
#include <string>    // string
#include <vector>    // vector
#include <map>       // map
using namespace std; // saves the "stdk.    ::" clutter

#include "PlayerCharacter.h"  // needed for each header file
#include "PlayerCharacter_Wizard.h"
#include "PlayerCharacter_Warrior.h"
#include "NonPlayerCharacter.h"
#include "NonPlayerCharacter_Caster.h"
#include "DefendYourselfTrigger.h"
#include "FieldModifier.h"
#include "Quest.h"
#include "DayNightCycle.h"
#include "Observer.h"

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

int safeGetHealth(int in_health)
{
    if (in_health <= 0)
    {
        throw invalid_argument("He's already dead...");
        cout << endl; // no error, but it is afer throw so it will never be run
    }
    return in_health;
}

int main()
{
    cout << "Wizard: " << endl;
    GAMEGANGINE::Wizard* wizard = new GAMEGANGINE::Wizard(10, 20, GAMEGANGINE::Career::Knight, 20);

    try
    {
        cout << "Annual heath checkup: " << safeGetHealth(wizard->gethealth()) << endl;
    }
    catch (const invalid_argument& e)
    {
        cout << e.what() << endl;
    }

    wizard->testYourMIGHT(wizard, wizard->getlanguageMagic());
    cout << endl;

    GAMEGANGINE::Quest* boarSkins = new GAMEGANGINE::Quest(50);
    cout << "Quest difficulty: " << boarSkins->getdifficulty() << endl;
    
    //cout << endl << "Try and do a quest:" << endl;
    //wizard->completeQuest(wizard, wizard->gethealth(), wizard->getlanguageMagic(), boarSkins->getdifficulty());
    cout << endl;

    wizard->addObserver(boarSkins); // quest observes the warrior
    wizard->updatehealth(0);
    wizard->updatehealth(2);
    wizard->updatehealth(10);



    //cout << wizard->gethealth() << " " << wizard->getdefense() << " "; wizard->getcreer();
    //cout << endl << wizard->getlanguageMagic() << endl;

    //cout << "Caster" << endl;
    //GAMEGANGINE::Caster* caster = new GAMEGANGINE::Caster(2, 10, Creature::RestlessDead, 8.2);
    //cout << caster->getdamage() << " " << caster->getattack() << " "; caster->getcreature();
    //cout << endl << caster->getDispelling() << endl;

    //cout << endl << "Get Higher Stat: " << endl;
    //cout << "Health vs Damage: " << getHigherStat(wizard->gethealth(), caster->getdamage()) << endl;
    //cout << "Defence vs Attack: " << getHigherStat(wizard->getdefense(), caster->getattack()) << endl;
    //cout << "Magic points: " << getHigherStat(wizard->getlanguageMagic(), caster->getDispelling()) << endl;



    /*
    cout << endl << "Increasing a field: " << endl;
    GAMEGANGINE::FieldModifier<int>* modifier = new GAMEGANGINE::FieldModifier<int>();
    modifier->set(5);
    cout << modifier->get() << endl;

    //cout << endl;
    //FieldModifier<Wizard>* playerFieldModifier = new FieldModifier<Wizard>();
    ////playerFieldModifier->increaseHealth(wizard);
    //playerFieldModifier->increaseHealth();

    cout << endl << "Overloading Operators:" << endl;
    NamespaceTest::Quest* boarSkins = new NamespaceTest::Quest(5);
    NamespaceTest::Quest* mushrooms = new NamespaceTest::Quest(5);

    cout << "The sum of difficulty of two quests: " << * boarSkins + *mushrooms << endl;

    cout << "The comparison of difficulty of tow quests: ";
    if (*boarSkins == *mushrooms)
    {
        cout << "Equal difficulty" << endl;
    }

    cout << endl;
    Day::Background* scene1 = new Day::Background();
    scene1->provideBacground();

    Night::Background* scene2 = new Night::Background();
    scene2->provideBacground();
    */

    return 0;
}

//namespace GAMEGANGINE
//{
//
//}