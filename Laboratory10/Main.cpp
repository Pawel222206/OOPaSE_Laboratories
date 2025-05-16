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

int main()
{
    cout << "Wizard: " << endl;
    Wizard* wizard = new Wizard(10, 20, Career::Knight, 4);
    cout << wizard->gethealth() << " " << wizard->getdefense() << " "; wizard->getcreer();
    cout << endl << wizard->getlanguageMagic() << endl;

    //cout << endl;
    //wizard->defend();
    //cout << endl;

    cout << "Warrior: " << endl;
    Warrior* warrior = new Warrior(16, 40, Career::Peasant, 8);
    cout << warrior->gethealth() << " " << warrior->getdefense() << " "; warrior->getcreer();
    cout << endl << warrior->getFightingPoints() << endl;

    //cout << endl;
    //warrior->defend();
    cout << endl;
 
    DefendYourselfTrigger* trigger = new DefendYourselfTrigger();
    trigger->makePlayerDefend(wizard);
    trigger->makePlayerDefend(warrior);


    return 0;
}
