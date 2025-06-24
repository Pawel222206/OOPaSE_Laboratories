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
    class Wizard : public PlayerCharacter // for now public to make it simple, change later
    {
    private:
        float languageMagic;

    public:
        Wizard() {}
        Wizard(int in_health, int in_defense, Career in_class, float in_languageMagic) : PlayerCharacter(in_health, in_defense, in_class), languageMagic(in_languageMagic) {}
        float getlanguageMagic() override { return languageMagic; };

        void defend() override;

        void testYourMIGHT(Wizard* p, int in_languageMagic);
        int testYourMIGHT2(int in_languageMagic2);

        //mutex mtx; // turns out this was not needed here
        void logStatus() override
        {
            //mtx.lock();
            cout << "Wizard magic: " << getlanguageMagic() << ", he's fine." << endl;
            //mtx.unlock();
        }

        void longLogStatus() override //lab20
        {
            this_thread::sleep_for(chrono::seconds(3));
            cout << "Wizard magic: " << getlanguageMagic() << ", he's fine." << endl;
        }

        string greeting() override
        {
            //this_thread::sleep_for(chrono::seconds(3));
            return "A wizard is never late, nor is he early, he arrives precisely when he means to.";
        }

        int longLogStatus2Step1() override
        {
            this_thread::sleep_for(chrono::seconds(3));
            return gethealth();
        }
        void longLogStatus2Step2(int value) override
        {
            if (value >= 20) {
                cout << "Healthy Mage" << endl;
            }
            else if (value >= 10) {
                cout << "Normal Wizard" << endl;
            }
            else {
                cout << "Injured Apprentice" << endl;
            }
        }
    };
}