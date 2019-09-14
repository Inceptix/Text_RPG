#include "Event.h"


Event::Event()
{
	this->numberOfEvents = 2;
}


Event::~Event()
{

}

void Event::generateEvent(Character & character)
{
	int i = rand() % this->numberOfEvents;

	switch (i)
	{
	case 0:
		//Enemy Encounter
		enemyEncounter(character);
		break;
	case 1:
		//Miscellanious Event
		break;
	case 2:
		//Safe Travel
		break;

	default:
		break;
	}
}

//Different events
void Event::enemyEncounter(Character &character)
{
	//while()
}

void Event::miscEncounter(Character &character)
{

}