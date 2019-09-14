#include "Armor.h"



Armor::Armor(int armorType, int armorDefense, std::string itemName, int itemLevel, int itemBuyValue, int itemSellValue, int itemRarity)
	: Item(itemName, itemLevel, itemBuyValue, itemSellValue, itemRarity)
{
	this->armorType = armorType;
	this->armorDefense = armorDefense;
}



Armor::~Armor()
{
}

Armor * Armor::clone() const
{
	return new Armor(*this);
}

std::string Armor::toString()
{
	std::string str = std::to_string(this->armorType) + " " + std::to_string(this->armorDefense);
	return str;
}
