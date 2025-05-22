#pragma once // Needed so that the class is initiated only once no matter how many times the program is thrown here during the process

#include <iostream>  // input/output
#include <fstream>   // external files support
#include <string>    // string
#include <vector>    // vector
#include <map>       // map
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
    };
}