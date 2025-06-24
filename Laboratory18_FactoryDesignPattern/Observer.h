#pragma once // IMPORTANT

#include <iostream>  // input/output
#include <fstream>   // external files support
#include <string>    // string
#include <vector>    // vector
#include <map>       // map
using namespace std; // saves the "std::" clutter

namespace GAMEGANGINE
{
    class Observer
    {
    public:
        virtual void update(int sufferedDamage) = 0;
    };
}

