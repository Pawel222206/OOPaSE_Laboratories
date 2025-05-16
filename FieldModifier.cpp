#include <iostream>  // input/output
#include <fstream>   // external files support
#include <string>    // string
#include <vector>    // vector
#include <map>       // map
using namespace std; // saves the "std::" clutter

#include "FieldModifier.h"
#include "PlayerCharacter.h"  // needed for each header file
#include "PlayerCharacter_Wizard.h"

namespace GAMEGANGINE
{
    template <class T>
    void FieldModifier<T>::increaseHealth()
    {
        //cout << p->gethealth();
        cout << "AAAAA";
    }
}

