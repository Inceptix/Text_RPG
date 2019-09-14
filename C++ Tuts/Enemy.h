#pragma once
#include <stdlib.h>
#include <string>


class Enemy
{
private:
	int enemyLevel;
	int enemyHP;
	int enemyHPMax;
	int enemyDamageMin;
	int enemyDamageMax;
	float enemyDropChance;
	int enemyDefense;


public:
	Enemy(int level = 0);
	virtual ~Enemy();

	inline bool isAlive() { return this->enemyHP > 0; }
	std::string getAsString()const;
	inline void takeDamage(int damage) { this->enemyHP -= damage; };
	inline int getDamage()const { return rand() % this->enemyDamageMax - this->enemyDamageMin; }
	inline int getExp() const { return this->enemyLevel * 50; }
};

