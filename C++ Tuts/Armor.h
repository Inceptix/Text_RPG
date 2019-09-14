#pragma once
#include "Item.h"

class Armor :
	public Item
{
public:
	Armor(int armorType = 0, int armorDefense = 0, std::string itemName = "NONE",
		int itemLevel = 0, int itemBuyValue = 0, int itemSellValue = 0,
		int itemRarity = 0);
	virtual ~Armor();

	

	//Pure virtual
	virtual Armor* clone() const;

	//Functions
	std::string toString();

private:

	int armorType;
	int armorDefense;
};

