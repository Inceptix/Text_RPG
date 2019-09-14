#include "Item.h"



Item::Item(std::string name, int itemLevel, int itemBuyValue, int itemSellValue, int rarity)
{
	this->itemName = name;
	this->itemLevel = itemLevel;
	this->itemBuyValue = itemBuyValue;
	this->itemSellValue = itemSellValue;
	this->itemRarity = rarity;
}


Item::~Item()
{
}
