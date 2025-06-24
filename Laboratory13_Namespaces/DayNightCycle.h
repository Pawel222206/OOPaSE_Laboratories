#pragma once // IMPORTANT

#include <iostream>  // input/output
#include <fstream>   // external files support
#include <string>    // string
#include <vector>    // vector
#include <map>       // map
using namespace std; // saves the "std::" clutter

namespace Day
{
    class DayNightCycle {};

    class Background : public DayNightCycle {
    public:
        void provideBacground()
        {
            cout << "The sun is high, it is a beautifull night." << endl;
        };
    };
}

namespace Night
{
    class DayNightCycle {};

    class Background : public DayNightCycle {
    public:
        void provideBacground()
        {
            cout << "The moon is high, it is a dreadfull night." << endl;
        };
    };
}