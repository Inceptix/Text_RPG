#include "Enemy.h"



Enemy::Enemy(int level)
{
	this->enemyLevel = level;
	this->enemyHPMax = level * 10;
	this->enemyHP = this->enemyHPMax;
	this->enemyDamageMin = this->enemyLevel * 3;
	this->enemyDamageMax = this->enemyLevel * 5;
	this->enemyDropChance = rand() % 100;
	this->enemyDefense = this->enemyLevel * 2;

}


Enemy::~Enemy()
{
}

std::string Enemy::getAsString() const
{
	return "Level: " + std::to_string(this->enemyLevel) + "\n" +
		"HP: " + std::to_string(this->enemyHP) + " / " + std::to_string(this->enemyHPMax) + "\n" +
		"Damage: " + std::to_string(this->enemyDamageMin) + " - " + std::to_string(this->enemyDamageMax) + "\n" +
		"Defense : " + std::to_string(this->enemyDefense) + "\n" +
		"Drop Chance: " + std::to_string(this->enemyDropChance) + "\n";
}
