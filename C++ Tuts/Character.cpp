#include "Character.h"



Character::Character()
{
	this->playerXPos = 0.0;
	this->playerYPos = 0.0;
	this->playerDistanceTraveled = 0;
	this->playerGold = 0;

	this->playerName = "";
	
	this->playerLevel = 0;
	this->playerLevelPoints = 0;
	this->playerExp = 0;
	this->playerExpNext = 0;

	this->playerStrength = 0;
	this->playerVitality = 0;
	this->playerDexterity = 0;
	this->playerIntelligence = 0;

	this->playerHP = 0;
	this->playerHPMax = 0;
	this->playerStamina = 0;
	this->playerStaminaMax = 0;
	this->playerDefense = 0;
	this->playerDamageMin = 0;
	this->playerDamageMax = 0;
}


Character::~Character()
{
}

//Fucntions
void Character::initialize(std::string name)
{
	this->playerXPos = 0.0;
	this->playerYPos = 0.0;
	this->playerGold = 100;

	this->playerName = name;
	
	this->playerLevel = 1;
	this->playerLevelPoints = 0;
	this->playerExp = 0;
	this->playerExpNext = playerExpNext = static_cast<int>
													(50 / 3)*(pow(playerLevel, 3) -
													6 * pow(playerLevel, 2) +
													(17 * playerLevel) - 12) + 100 ;

	this->playerStrength = 5;
	this->playerVitality = 5;
	this->playerDexterity = 5;
	this->playerIntelligence = 5;

	this->playerHPMax = (this->playerVitality *2) + (this->playerStrength/2);
	this->playerHP = this->playerHPMax;
	this->playerStaminaMax = (this->playerVitality) + (this->playerStrength/2) + (this->playerDexterity/2);
	this->playerStamina = this->playerStaminaMax;
	
	this->playerDefense = (this->playerStrength/2) + (this->playerVitality/2) + (this->playerDexterity/2);
	this->playerDamageMin = this->playerStrength;
	this->playerDamageMax = this->playerStrength*2;
}

void Character::printStats() const
{
	std::cout << "-- Character Sheet --\n";
	std::cout << "-- Name: " << this->playerName << "\n";
	std::cout << "-- Level: " << this->playerLevel << "\n";
	std::cout << "-- Exp: " << this->playerExp << "\n";
	std::cout << "-- Exp to next level: " << this->playerExpNext << "\n\n";

	std::cout << "-- HP: " << this->playerHP << "/" << this->playerHPMax << "\n";
	std::cout << "-- Stamina: " << this->playerStamina << "/" << this->playerStaminaMax << "\n";
	std::cout << "-- Defense: " << this->playerDefense << "\n\n";

	std::cout << "-- Strength: " << this->playerStrength << "\n";
	std::cout << "-- Vitality: " << this->playerVitality << "\n";
	std::cout << "-- Dexterity: " << this->playerDexterity << "\n";
	std::cout << "-- Intelligence: " << this->playerIntelligence << "\n\n";
	
}

void Character::levelUp()
{
	while (this->playerExp >= this->playerExpNext)
	{
		this->playerExp -= this->playerExpNext;
		this->playerLevel++;
		this->playerExpNext = static_cast<int>
										(50 / 3)*(pow(playerLevel, 3) -
										6 * pow(playerLevel, 2) +
										(17 * playerLevel) - 12) + 100;
		
	}
	
}

std::string Character::getAsString() const
{

	return "XPos:" + std::to_string(playerXPos) + " | "
		+ "YPos:" + std::to_string(playerYPos) + " | "
		+ "Name:" + playerName + " | "
		+ "HP:" + std::to_string(playerHP) + " | "
		+ "Stamina:" + std::to_string(playerStamina) + " | "
		+ "LvlPoints:" + std::to_string(playerLevelPoints) + " | "
		+ "Lvl:" + std::to_string(playerLevel) + " | "
		+ "Exp:" + std::to_string(playerExp) + " | "
		+ "ExpNext:" + std::to_string(playerExpNext) + " | "
		+ "Str:" + std::to_string(playerStrength) + " | "
		+ "Vit:" + std::to_string(playerVitality) + " | "
		+ "Dex:" + std::to_string(playerDexterity) + " | "
		+ "Int:" + std::to_string(playerIntelligence);

}
