#include "Inventory.h"

Inventory::Inventory()
{
	this->invCap = 5;
	this->invNumberOfItems = 0;
	this->itemArr = new Item*[invCap];
	this->invInitialize();
	
}


Inventory::~Inventory()
{
	for (size_t i = 0; i < this->invNumberOfItems; i++)
	{
		delete this->itemArr[i];
	}
	delete[] this->itemArr;
}

Inventory::Inventory(const Inventory & obj)
{
	this->invCap = obj.invCap;
	this->invNumberOfItems = obj.invNumberOfItems;
	this->itemArr = new Item*[this->invCap];

	for (size_t i = 0; i < this->invNumberOfItems; i++)
	{
		this->itemArr[i] = obj.itemArr[i]->clone();
	}

	invInitialize(this->invNumberOfItems);
}

Item & Inventory::operator[](const int index)
{
	if (index < 0 || index >= this->invNumberOfItems)
		throw("BAD INDEX!");

	return *this->itemArr[index];
}

void Inventory::invAddItem(const Item &item)
{
	if (this->invNumberOfItems >= this->invCap)
	{
		invExpand();
	}
	this->itemArr[this->invNumberOfItems++] = item.clone();
}

void Inventory::invRemoveItem(int index)
{

}

void Inventory::invExpand()
{
	this->invCap *= 2;

	Item **tempArr = new Item*[this->invCap];

	for (size_t i = 0; i < this->invNumberOfItems; i++)
	{
		tempArr[i] = this->itemArr[i];
	}
	delete[] this->itemArr;

	this->itemArr = tempArr;

	this->invInitialize(this->invNumberOfItems);
}

void Inventory::invInitialize(const int from)
{
	for (size_t i = from; i < invCap; i++)
	{
		this->itemArr[i] = nullptr;
	}
}
