#include <iostream>  // input/output
#include <fstream>   // external files support
#include <string>    // string
#include <vector>    // vector
#include <map>       // map
using namespace std; // saves the "std::" clutter

#include "PlayerCharacter.h"
#include "PlayerCharacter_Wizard.h"
#include "FieldModifier.h"

namespace GAMEGANGINE
{
	void Wizard::defend()
	{
		cout << "Wizard defends himself with magic!" << endl;
	}

    void Wizard::testYourMIGHT(Wizard* p, int in_languageMagic)
    {
        try
        {
            cout << "Wizard power test: " << p->testYourMIGHT2(in_languageMagic) << endl;
        }
        catch (const invalid_argument& e)
        {
            cout << e.what() << endl;
        }
    }

    int Wizard::testYourMIGHT2(int in_languageMagic2)
    {
        if (in_languageMagic2 <= 10)
        {
            throw invalid_argument("You're to weak boi, shoo");
        }
        return in_languageMagic2;
    }
}

