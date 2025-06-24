#include <iostream>  // input/output
#include <fstream>   // external files support
#include <string>    // string
#include <vector>    // vector
#include <map>       // map
#include <thread>    // thread
#include <mutex>     // mutex
#include <future>    // future
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
#include "NonPlayercharacterFactory.h"
#include "NonPlayerCharacter_CasterFactory.h"
#include "PlayercharacterFactory.h"
#include "PlayerCharacterAutoFactory.h"
#include "Simulation.h"
#include "AdventuringParty.h"
#include "AdventuringGuild.h"

//template <typename T>
//T getHigherStat(T a, T b)
//{
//    if (a > b) 
//    {
//        return a;
//    }
//    else
//    {
//        return b;
//    }
//    
//}

//int safeGetHealth(int in_health)
//{
//    if (in_health <= 0)
//    {
//        throw invalid_argument("He's already dead...");
//        cout << endl; // no error, but it is afer throw so it will never be run
//    }
//    return in_health;
//}

//void printMessage()
//{
//    cout << "In Thread, sleeping" << endl;
//    this_thread::sleep_for(chrono::seconds(2));
//    cout << "In Thread, waking" << endl;
//}

int main()
{
    cout << "Lab 22" << endl;
    GAMEGANGINE::PlayerCharacterFactory* warriorFactory = new GAMEGANGINE::PlayerCharacterAutoFactory<GAMEGANGINE::Warrior>();
    GAMEGANGINE::PlayerCharacter* warrior = warriorFactory->createPlayerCharacter(15, 30, GAMEGANGINE::Career::Knight, 12.5);
    //cout << warrior->greeting();
    GAMEGANGINE::PlayerCharacterFactory* wizardFactory = new GAMEGANGINE::PlayerCharacterAutoFactory<GAMEGANGINE::Wizard>();
    GAMEGANGINE::PlayerCharacter* wizard = wizardFactory->createPlayerCharacter(10, 12, GAMEGANGINE::Career::Priest, 7.2);
    //cout << wizard->greeting();
    
    GAMEGANGINE::AdventuringParty* adventuringParty = new GAMEGANGINE::AdventuringParty();
    adventuringParty->add(wizard);
    adventuringParty->add(warrior);
    cout << adventuringParty->greeting() << endl;
    //delete adventuringParty;

    GAMEGANGINE::PlayerCharacter* GreenKnight = warriorFactory->createPlayerCharacter(21, 47, GAMEGANGINE::Career::Peasant, 19.5);
    
    GAMEGANGINE::AdventuringGuild* adventuringGuild = new GAMEGANGINE::AdventuringGuild();
    adventuringGuild->add(adventuringParty);
    adventuringGuild->add(GreenKnight);
    cout << adventuringGuild->greeting() << endl;
    delete adventuringGuild;




    
    /*
    cout << "Lab 19" << endl;
    GAMEGANGINE::Simulation* simulation = new GAMEGANGINE::Simulation();
    thread t1(&GAMEGANGINE::Simulation::simulateWizard, simulation); // startting a thread
    thread t2(&GAMEGANGINE::Simulation::simulateWarrior, simulation);
    t1.join();
    t2.join();
    cout << "Back in main, end of task 1" << endl << endl;


    GAMEGANGINE::PlayerCharacterFactory* warriorFactory = new GAMEGANGINE::PlayerCharacterAutoFactory<GAMEGANGINE::Warrior>();
    GAMEGANGINE::PlayerCharacter* warrior = warriorFactory->createPlayerCharacter(15, 30, GAMEGANGINE::Career::Knight, 12.5);

    GAMEGANGINE::PlayerCharacterFactory* wizardFactory = new GAMEGANGINE::PlayerCharacterAutoFactory<GAMEGANGINE::Wizard>();
    GAMEGANGINE::PlayerCharacter* wizard = wizardFactory->createPlayerCharacter(10, 12, GAMEGANGINE::Career::Priest, 7.2);

    t1 = thread(&GAMEGANGINE::Simulation::runObjectWithStatus, simulation, wizard); // reusing the thread
    t2 = thread(&GAMEGANGINE::Simulation::runObjectWithStatus, simulation, warrior);
    t1.join();
    t2.join();
    cout << "Back in main, end of task 2" << endl << endl;

    GAMEGANGINE::PlayerCharacter* warrior1 = new GAMEGANGINE::Warrior(15, 30, GAMEGANGINE::Career::Peasant, 12.5);
    GAMEGANGINE::PlayerCharacter* warrior2 = new GAMEGANGINE::Warrior(25, 45, GAMEGANGINE::Career::Knight, 29.1);

    GAMEGANGINE::PlayerCharacter* wizard1 = new GAMEGANGINE::Wizard(8, 9, GAMEGANGINE::Career::Priest, 32.7);
    GAMEGANGINE::PlayerCharacter* wizard2 = new GAMEGANGINE::Wizard(10, 12, GAMEGANGINE::Career::Priest, 7.2);
    
    vector<GAMEGANGINE::PlayerCharacter*> group1 = { warrior1 , wizard1 };
    vector<GAMEGANGINE::PlayerCharacter*> group2 = { warrior2 , wizard2 };

    t1 = thread(&GAMEGANGINE::Simulation::processObjects, simulation, group1);
    t2 = thread(&GAMEGANGINE::Simulation::processObjects, simulation, group2);
    t1.join();
    this_thread::sleep_for(chrono::seconds(1));
    t2.join();
    cout << "Back in main, end of task 3" << endl << endl;

    t1 = thread(&GAMEGANGINE::Simulation::useSharedResource, simulation, "Wizard");
    t2 = thread(&GAMEGANGINE::Simulation::useSharedResource, simulation, "Warrior");
    t1.join();
    t2.join();
    cout << "Back in main, end of task 4" << endl << endl;
    */

    /*
    cout << "Lab 20" << endl;
    GAMEGANGINE::Simulation* simulation = new GAMEGANGINE::Simulation();

    GAMEGANGINE::PlayerCharacterFactory* wizardFactory = new GAMEGANGINE::PlayerCharacterAutoFactory<GAMEGANGINE::Wizard>();
    GAMEGANGINE::PlayerCharacter* wizard = wizardFactory->createPlayerCharacter(10, 12, GAMEGANGINE::Career::Priest, 7.2);

    GAMEGANGINE::PlayerCharacterFactory* warriorFactory = new GAMEGANGINE::PlayerCharacterAutoFactory<GAMEGANGINE::Warrior>();
    GAMEGANGINE::PlayerCharacter* warrior = warriorFactory->createPlayerCharacter(15, 30, GAMEGANGINE::Career::Knight, 12.5);

    future<void> f1 = async(launch::async, &GAMEGANGINE::Simulation::runLongLogStatus, simulation, wizard);
    future<void> f2 = async(launch::async, &GAMEGANGINE::Simulation::runLongLogStatus, simulation, warrior);
    cout << "Working..." << endl;
    this_thread::sleep_for(chrono::seconds(4));
    cout << "Back in main, end of task 1" << endl << endl;

    
    vector<GAMEGANGINE::PlayerCharacter*> characters = { new GAMEGANGINE::Wizard(10, 12, GAMEGANGINE::Career::Priest, 7.2), new GAMEGANGINE::Warrior(15, 30, GAMEGANGINE::Career::Knight, 12.5) };
    vector<future<string>> futures;

    for (GAMEGANGINE::PlayerCharacter* character : characters)
    {
        futures.push_back(async(launch::async, &GAMEGANGINE::Simulation::runGreeting, simulation, character));
    }
    for (auto& f : futures)
    {
        cout << f.get() << endl;
    }
    for (GAMEGANGINE::PlayerCharacter* character : characters)
    {
        delete character;
    }
    cout << "Back in main, end of task 2" << endl << endl;


    vector<GAMEGANGINE::PlayerCharacter*> int_characters = { new GAMEGANGINE::Wizard(10, 12, GAMEGANGINE::Career::Priest, 7.2), new GAMEGANGINE::Warrior(15, 30, GAMEGANGINE::Career::Knight, 12.5) };
    vector<future<int>> int_futures;

    for (GAMEGANGINE::PlayerCharacter* character : int_characters)
    {
        int_futures.push_back(async(launch::async, &GAMEGANGINE::Simulation::runLongLogStatus2Step1, simulation, character));
    }
    for (size_t i = 0; i < int_characters.size(); i++)
    {
        int value = int_futures[i].get();
        simulation->runLongLogStatus2Step2(int_characters[i], value);
    }
    cout << "Back in main, end of task 3" << endl << endl;
    */


    // earier stuff
    //GAMEGANGINE::NonPlayerCharacterFactory* casterFactory = new GAMEGANGINE::NonPlayerCharacter_CasterFactory();
    //GAMEGANGINE::NonPlayerCharacter* caster = casterFactory->createNonPlayerCharacter(2, 10, Creature::RestlessDead, 8.2);

    //cout << caster->getdamage() << " " << caster->getattack() << " "; caster->getcreature();
    //cout << endl << caster->getDispelling() << endl;
    //cout << endl;

    //GAMEGANGINE::PlayerCharacterFactory* wizardFactory = new GAMEGANGINE::PlayerCharacterAutoFactory<GAMEGANGINE::Wizard>();
    //GAMEGANGINE::PlayerCharacter* wizard = wizardFactory->createPlayerCharacter(10, 12, GAMEGANGINE::Career::Priest, 7.2);

    //cout << wizard->gethealth() << " " << wizard->getdefense() << " "; wizard->getcreer();
    //cout << endl << wizard->getlanguageMagic() << endl; // will workn after adding a virtual function to be overriten by wizard, as with caster...
    //cout << endl;

    //GAMEGANGINE::PlayerCharacterFactory* warriorFactory = new GAMEGANGINE::PlayerCharacterAutoFactory<GAMEGANGINE::Warrior>();
    //GAMEGANGINE::PlayerCharacter* warrior = warriorFactory->createPlayerCharacter(15, 30, GAMEGANGINE::Career::Knight, 12.5);

    //cout << warrior->gethealth() << " " << warrior->getdefense() << " "; warrior->getcreer();
    //cout << endl << wizard->getlanguageMagic() << endl; // will workn after adding a virtual function to be overriten by wizard, as with caster...
    //cout << endl;

    //cout << "Wizard: " << endl;
    //GAMEGANGINE::Wizard* wizard = new GAMEGANGINE::Wizard(10, 20, GAMEGANGINE::Career::Knight, 20);

    //try
    //{
    //    cout << "Annual heath checkup: " << safeGetHealth(wizard->gethealth()) << endl;
    //}
    //catch (const invalid_argument& e)
    //{
    //    cout << e.what() << endl;
    //}

    //wizard->testYourMIGHT(wizard, wizard->getlanguageMagic());
    //cout << endl;

    //GAMEGANGINE::Quest* boarSkins = new GAMEGANGINE::Quest(50);
    //cout << "Quest difficulty: " << boarSkins->getdifficulty() << endl;
    //
    ////cout << endl << "Try and do a quest:" << endl;
    ////wizard->completeQuest(wizard, wizard->gethealth(), wizard->getlanguageMagic(), boarSkins->getdifficulty());
    //cout << endl;

    //wizard->addObserver(boarSkins); // quest observes the warrior
    //wizard->updatehealth(0);
    //wizard->updatehealth(2);
    //wizard->updatehealth(10);
    //cout << endl;


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