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
	class AdventuringParty : public PlayerCharacter
	{
	private:
		vector<GAMEGANGINE::PlayerCharacter*> PlayerCharacters;
	public:
		void add(PlayerCharacter* in_PlayerCharaccter)
		{
			PlayerCharacters.push_back(in_PlayerCharaccter);
		}
		string greeting() override
		{
			for (const auto& PC : PlayerCharacters)
			{
				PC->greeting();
			}
		}
		~AdventuringParty()
		{
			for (auto PC : PlayerCharacters)
			{
				delete PC;
			}
		}
	};
}