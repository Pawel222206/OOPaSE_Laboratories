#pragma once // IMPORTANT

#include <iostream>  // input/output
#include <fstream>   // external files support
#include <string>    // string
#include <vector>    // vector
#include <map>       // map
using namespace std; // saves the "std::" clutter

#include "PlayerCharacter.h"  // needed for each header file
#include "PlayerCharacter_Wizard.h"
#include "NonPlayerCharacter.h"
#include "NonPlayerCharacter_Caster.h"

namespace GAMEGANGINE
{
    template <class T>
    class FieldModifier
    {
    private:
        T value;
    public:
        FieldModifier() {}
        void set(T in_value) { value = in_value; };
        T get() { return value; };
        //void increaseHealth(T* p);
        void increaseHealth();
    };
}

