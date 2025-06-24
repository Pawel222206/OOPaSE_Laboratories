#pragma once // IMPORTANT

#include <iostream>  // input/output
#include <fstream>   // external files support
#include <string>    // string
#include <vector>    // vector
#include <map>       // map
using namespace std; // saves the "std::" clutter

namespace GAMEGANGINE
{
    class Quest : public Observer
    {
    public:
        int difficulty = 0;
        int charactersState = 0;

        int getdifficulty() { return difficulty; };

        Quest(int in_difficulty) : difficulty(in_difficulty) {}
        bool operator==(const Quest& q)
        {
            if (this->difficulty == q.difficulty)
            {

                return true;
            }
            return false;
        }

        int operator+(const Quest& qq)
        {
            return (this->difficulty + qq.difficulty);

        }

        void update(int sufferedDamage) override
        {
            if (sufferedDamage <= 0)
            {
                charactersState = 0;
                cout << "Your characte is fine :)" << endl;
            }
            else if (sufferedDamage <= 5)
            {
                charactersState = 1;
                cout << "Your characte has suffer a minor injury, be weary" << endl;
            }
            else
            {
                charactersState = 2;
                cout << "Your characte has suffer a major injury, are you sure you want to continue?" << endl;
            }
            
        }
        int getcharactersState() { return charactersState; };
    };
}

