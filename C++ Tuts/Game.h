#pragma once

#include "Functions.h"

#include "Event.h"
#include <ctime>
#include <vector>
#include <fstream>

class Game
{
public:
	Game();
	virtual ~Game();

	//Operators

	//Functions
	void initGame(); //This also creates new characters
	void gameMenu();
	void mainMenu();
	void saveCharacters();
	void loadCharacters();
	void Travel();

	//Accessors
	inline bool getStartGame() const { return this->start; }
	inline bool getPlaying() const { return this->playing; }

	//Modifiers

private:
	int choice;
	int safeChoice;
	bool start;
	bool playing;


	//Character Related
	int activeCharacter;
	std::vector<Character> characters;
	std::string fileName;
};

