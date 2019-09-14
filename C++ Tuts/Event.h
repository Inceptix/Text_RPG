#pragma once

#include <stdlib.h>
#include "Character.h"

class Event
{
private:
	int numberOfEvents;


public:
	Event();
	virtual ~Event();
	void generateEvent(Character &charater);

	//Events
	void enemyEncounter(Character &character);
	void miscEncounter(Character &character);

};

