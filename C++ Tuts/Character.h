#pragma once
#include "Inventory.h"
#include "Enemy.h"


class Character
{
public:
	Character();
	virtual ~Character();

	//Functions
	void initialize(const std::string name);
	void printStats() const;
	void levelUp();
	std::string getAsString() const;

	//Accessors
	inline const std::string& getPlayerName() const { return this->playerName; }

	inline const double& getPlayerXPos() const { return this->playerXPos; }
	inline const double& getPlayerYPos() const { return this->playerYPos; }
	inline const int& getPlayerDistanceTraveled() const { return this->playerDistanceTraveled; }

	inline const int& getPlayerHP() const { return this->playerHP; }
	inline const int& getPlayerHPMax() const { return this->playerHPMax; }
	inline const int& getPlayerStamina() const { return this->playerStamina; }
	inline const int& getPlayerStaminaMax() const { return this->playerStaminaMax; }
	inline const int& getPlayerDefense() const { return this->playerDefense; }
	inline const int& getPlayerLevel() const { return this->playerLevel; }
	inline const int& getPlayerLevelPoints() const { return this->playerLevelPoints; }
	inline const int& getPlayerExp() const { return this->playerExp; }
	inline const int& getPlayerExpNext() const { return this->playerExpNext; }
	inline const int& getPlayerDamageMin() const { return this->playerDamageMin; }
	inline const int& getPlayerDamageMax() const { return this->playerDamageMax; }
	

	//Modifiers
	inline void setPlayerDistanceTraveled(const int& distance) { this->playerDistanceTraveled = distance; }
	inline void travel() { this->playerDistanceTraveled++; }

private:

	std::string playerName;

	Inventory inventory;
	Weapon weapon;
	Armor armor_head;
	Armor armor_chest;
	Armor armor_arms;
	Armor armor_legs;
	Armor armor_feet;
	int playerGold;

	double playerXPos;
	double playerYPos;

	int playerDistanceTraveled;

	int playerHP;
	int playerHPMax;
	int playerStamina;
	int playerStaminaMax;
	int playerDefense;
	int playerLevel;
	int playerLevelPoints;
	int playerExp;
	int playerExpNext;
	int playerDamageMin;
	int playerDamageMax;

	int playerStrength;
	int playerVitality;
	int playerDexterity;
	int playerIntelligence;


};

