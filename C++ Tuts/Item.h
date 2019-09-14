#pragma once
#include <string>
#include <iostream>
#include <iomanip>

class Item
{
public:
	Item(std::string name = "NONE", int level = 0,
		int itemBuyValue = 0,
		int itemSellValue = 0,
		int itemRarity = 0);
	virtual ~Item();

	inline std::string debugPrint() const { return this->itemName; }
	virtual Item* clone() const = 0;

	//Accessors
	inline const std::string& itemGetName() const { return this->itemName; }
	inline const int& itemGetLevel() const { return this->itemLevel; }
	inline const int& itemGetBuyValue() const { return this->itemBuyValue; }
	inline const int& itemGetSellValue() const { return this->itemSellValue; }
	inline const int& itemGetRarity() const { return this->itemRarity; }

	//Modifiers

private:
	std::string itemName;
	int itemLevel;
	int itemSellValue;
	int itemBuyValue;
	int itemRarity;

};

