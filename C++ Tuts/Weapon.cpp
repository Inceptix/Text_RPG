#include "Weapon.h"



Weapon::Weapon(int wpnDamageMin, int wpnDamageMax, std::string itemName, int itemLevel, int itemBuyValue, int itemSellValue, int itemRarity)
	: Item(itemName, itemLevel, itemBuyValue, itemSellValue, itemRarity)
{
	this->wpnDamageMax = wpnDamageMax;
	this->wpnDamageMin = wpnDamageMin;
}



Weapon::~Weapon()
{
}

Weapon * Weapon::clone() const
{
	return new Weapon(*this);
}

std::string Weapon::toString()
{
	std::string str = std::to_string(this->wpnDamageMin) + " " + std::to_string(this->wpnDamageMax);
	return str;
}
