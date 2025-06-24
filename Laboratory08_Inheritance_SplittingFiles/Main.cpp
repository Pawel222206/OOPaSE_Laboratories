#include <iostream>  // input/output
#include <fstream>   // external files support
#include <string>    // string
#include <vector>    // vector
#include <map>       // map
using namespace std; // saves the "std::" clutter

#include "PlayerCharacter.h"  // needed for each header file
#include "PlayerCharacter_Wizard.h"
#include "NonPlayerCharacter.h"
#include "NonPlayerCharacter_Caster.h"
#include "Arena.h"

int main()
{
    PlayerCharacter* steve = new PlayerCharacter();
    PlayerCharacter* priest = new PlayerCharacter(10, 20, Career::Priest);

    NonPlayerCharacter* mob = new NonPlayerCharacter();
    NonPlayerCharacter* boblinTheGoblin = new NonPlayerCharacter(2, 10, Creature::Greenskin);

    //combat(*steve, *mob); // friend function

    /* Friend class - we do inheritaqnce instead
    Potion healingDrought; // friend class
    healingDrought.healingPotion(*wizard, 9);
    */

    cout << "Wizard" << endl;
    Wizard* wizard = new Wizard(10, 20, Career::Knight, 4);
    cout << wizard->gethealth() << " " << wizard->getdefense() << " "; wizard->getcreer();
    cout << endl << wizard->getlanguageMagic() << endl;

    cout << "Caster" << endl;
    Caster* caster = new Caster(2, 10, Creature::RestlessDead);
    cout << caster->getdamage() << " " << caster->getattack() << " "; caster->getcreature();
    cout << endl;

    cout << endl;
    wizard->channelMagic(*wizard, 4);
    cout << endl;
    cout << caster->getMagicColour(3) << endl;

    Arena* magicalCircle = new Arena(*priest, *boblinTheGoblin);
    cout << endl;
    magicalCircle->compareStats();

    return 0;
}
