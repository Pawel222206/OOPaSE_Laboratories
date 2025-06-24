#pragma once

#include <iostream>  // input/output
#include <fstream>   // external files support
#include <string>    // string
#include <vector>    // vector
#include <map>       // map
using namespace std; // saves the "std::" clutter

#include "PlayerCharacter.h"
#include "PlayerCharacter_Wizard.h"
#include "PlayerCharacter_Warrior.h"
#include "AdventuringParty.h"

namespace GAMEGANGINE
{
	class AdventuringGuild : public PlayerCharacter
	{
	private:
		vector<GAMEGANGINE::PlayerCharacter*> PlayerCharacters;
	public:
		void add(PlayerCharacter* in_PlayerCharacter)
		{
			//cout << "Added" << endl; // test
			PlayerCharacters.push_back(in_PlayerCharacter);
		}
		string greeting() override
		{
			cout << "Kompania! Bacznosc!" << endl;
			int healthPool = 0;
			for (auto PC : PlayerCharacters)
			{
				//return PC->greeting(); // return needed here becouse its not void, return breaks the loop endign function
				cout << PC->greeting();
				PC->logStatus();
				healthPool += PC->gethealth();
			}
			cout << "Guild's health pool: " << healthPool << "; ";
			return "Muster finished.";
		}
		~AdventuringGuild()
		{
			for (auto PC : PlayerCharacters)
			{
				delete PC;
			}
		}

		void defend() override
		{
			cout << "Nope" << endl;
		}
		void logStatus() override
		{
			cout << "Nope" << endl;
		}
		void longLogStatus() override
		{
			cout << "Nope" << endl;
		}
		int longLogStatus2Step1() override
		{
			return gethealth();
		}
		void longLogStatus2Step2(int value) override
		{
			cout << "Nope" << endl;
		}
	};
}