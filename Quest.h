#pragma once // IMPORTANT

#include <iostream>  // input/output
#include <fstream>   // external files support
#include <string>    // string
#include <vector>    // vector
#include <map>       // map
using namespace std; // saves the "std::" clutter

namespace NamespaceTest
{
    class Quest
    {
    public:
        int difficulty = 0;
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
    };
}

