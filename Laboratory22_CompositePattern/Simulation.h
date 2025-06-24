#pragma once // IMPORTANT

#include <iostream>  // input/output
#include <fstream>   // external files support
#include <string>    // string
#include <vector>    // vector
#include <map>       // map
#include <thread>    // thread
#include <mutex>     // mutex
using namespace std; // saves the "stdk.    ::" clutter

#include "PlayerCharacter.h"  // needed for each header file
#include "PlayerCharacter_Wizard.h"
#include "PlayerCharacter_Warrior.h"
#include "Observer.h"
#include "NonPlayercharacterFactory.h"
#include "NonPlayerCharacter_CasterFactory.h"
#include "PlayercharacterFactory.h"
#include "PlayerCharacterAutoFactory.h"

namespace GAMEGANGINE
{
    class Simulation
    {
    public:        
        Simulation() {}
        void simulateWizard()
        {
            GAMEGANGINE::PlayerCharacterFactory* wizardFactory = new GAMEGANGINE::PlayerCharacterAutoFactory<GAMEGANGINE::Wizard>();
            GAMEGANGINE::PlayerCharacter* wizard = wizardFactory->createPlayerCharacter(10, 12, GAMEGANGINE::Career::Priest, 7.2);

            cout << "Simulating wizard:" << endl;
            cout << wizard->gethealth() << " " << wizard->getdefense() << " "; wizard->getcreer();
            cout << endl;
            delete wizard;
        }

        
        void simulateWarrior()
        {
            GAMEGANGINE::PlayerCharacterFactory* warriorFactory = new GAMEGANGINE::PlayerCharacterAutoFactory<GAMEGANGINE::Warrior>();
            GAMEGANGINE::PlayerCharacter* warrior = warriorFactory->createPlayerCharacter(15, 30, GAMEGANGINE::Career::Knight, 12.5);

            cout << "Simulating warrior:" << endl;
            cout << warrior->gethealth() << " " << warrior->getdefense() << " "; warrior->getcreer();
            cout << endl;
            delete warrior;
        }

        void runObjectWithStatus(PlayerCharacter* obj)
        {
            obj->logStatus();
            delete obj;
        }

        void processObjects(const vector<GAMEGANGINE::PlayerCharacter*>& objects)
        {
            for (GAMEGANGINE::PlayerCharacter* obj : objects)
            {
                obj->logStatus();
            }
        }

        mutex resourceMutex; //should it be here?
        void useSharedResource(const string& name)
        {
            cout << name << "Waiting for acces to resource" << endl;
            {
                lock_guard<mutex> lock(resourceMutex);
                cout << name << " is using resource" << endl;
                this_thread::sleep_for(chrono::seconds(1));
                cout << name << " is done." << endl;
            }
        }

        void runLongLogStatus(PlayerCharacter* obj) //lab20
        {
            obj->longLogStatus();
            delete obj;
        }

        string runGreeting(PlayerCharacter* obj)
        {
            return obj->greeting();
        }

        int runLongLogStatus2Step1(PlayerCharacter* obj)
        {
            return obj->longLogStatus2Step1();
        }
        void runLongLogStatus2Step2(PlayerCharacter* obj, int value)
        {
            obj->longLogStatus2Step2(value);
        }
    };
}

