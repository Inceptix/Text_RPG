#pragma once
#include "Item.h"

class Weapon :
	public Item

{
public:
	Weapon(int wpnDamageMin = 0, int wpnDamageMax = 0, std::string itemName = "NONE",
		int itemLevel = 0, int itemBuyValue = 0, int itemSellValue = 0,
		int itemRarity = 0);
	virtual ~Weapon();

	//Pure virtual
	virtual Weapon* clone() const;

	//Functions
	std::string toString();

private:
	int wpnDamageMin;
	int wpnDamageMax;
};

