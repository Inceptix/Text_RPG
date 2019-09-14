#pragma once
#include "Armor.h"
#include "Weapon.h"
#pragma comment (lib, "winmm")
#include <Windows.h>

class Inventory
{
public:
	Inventory();
	~Inventory();
	Inventory(const Inventory &obj);
	inline int size() const { return this->invNumberOfItems; };
	Item& operator[](const int index);

	void invAddItem(const Item &item);
	void invRemoveItem(int index);
	inline void debugPrint() const
	{
		for (size_t i = 0; i < this->invNumberOfItems; i++)
		{
			std::cout << this->itemArr[i]->debugPrint() << "\n";
		}
	}
	
private:
	void invExpand();
	void invInitialize(const int from = 0);

	Item **itemArr;

	int invCap;
	int invNumberOfItems;

};

