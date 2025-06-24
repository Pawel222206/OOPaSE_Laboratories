#pragma once // IMPORTANT

#include <iostream>  // input/output
#include <fstream>   // external files support
#include <string>    // string
#include <vector>    // vector
#include <map>       // map
using namespace std; // saves the "std::" clutter

#include "Subject.h"
#include "Observer.h"
#include "NonPlayerCharacter.h"

namespace GAMEGANGINE
{

    enum Career
    {
        Peasant,
        Knight,
        Priest
    };

    class PlayerCharacter : public Subject
    {
    private:
        int health, defense;
        Career creer;

        vector<Observer*> observers;

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

        int gethealth() { return health;};
        void updatehealth(int sufferedDamage);
        int getdefense() { return defense; };
        void getcreer();

        virtual void defend() = 0;

        virtual ~PlayerCharacter();

        void completeQuest(PlayerCharacter* p, int in_health, int in_languageMagic, int in_difficulty);
        int completeQuest2(int in_health, int in_languageMagic, int in_difficulty);
    
        void addObserver(Observer* observer) override;
        void removeObserver(Observer* observer) override;
        void notifyObservers(int sufferedDamage) override;

        virtual float getlanguageMagic() { return 0; };
        virtual float getFightingPoints() { return 0; };
    };
}

