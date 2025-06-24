#pragma once // Needed so that the class is initiated only once no matter how many times the program is thrown here during the process

#include <iostream>  // input/output
#include <fstream>   // external files support
#include <string>    // string
#include <vector>    // vector
#include <map>       // map
#include <mutex>     // mutex
using namespace std; // saves the "std::" clutter

#include "PlayerCharacter.h"

namespace GAMEGANGINE
{
    class Warrior : public PlayerCharacter
    {
    private:
        float fightingPionts;

    public:
        Warrior(int in_health, int in_defense, Career in_class, float in_fightingPionts) : PlayerCharacter(in_health, in_defense, in_class), fightingPionts(in_fightingPionts) {}
        float getFightingPoints() override { return fightingPionts; };

        void defend() override;

        //mutex mtx;
        void logStatus() override
        {
            //mtx.lock();
            cout << "Warriors remaining streanght: " << getFightingPoints() << ", mighty and strong!" << endl;
            //mtx.unlock();
        }

        void longLogStatus() override //lab20
        {
            this_thread::sleep_for(chrono::seconds(1));
            cout << "Warriors remaining streanght: " << getFightingPoints() << ", mighty and strong!" << endl;
        }

        string greeting() override
        {
            //this_thread::sleep_for(chrono::seconds(1));
            return "Remember Today, Little Brother. Today, Life is Good.";
        }

        int longLogStatus2Step1() override
        {
            this_thread::sleep_for(chrono::seconds(1));
            return gethealth();
        }
        void longLogStatus2Step2(int value) override
        {
            if (value >= 20) {
                cout << "Healthy Champion" << endl;
            }
            else if (value >= 10) {
                cout << "Normal Warrior" << endl;
            }
            else {
                cout << "Injured Squaier" << endl;
            }
        }
    };
}

