#include "Game.h"

Game::Game()
{
	//Use safeChoice to set the state of the menu
	safeChoice = -1;
	choice = safeChoice;
	activeCharacter = 0;
	fileName = "..\\Game\\characters.txt";

	start = true;
	playing = false;

	
}


Game::~Game()
{
}


//Functions
void Game::initGame()
{
	
	//Enemy e(rand() & 10 + 1);
	//std::cout << e.getAsString() << "\n";

	//Starting new game
	choice = safeChoice;
	std::string name;

	//Clears the '\n' char from buffer
	std::cin.clear();
	std::cin.ignore(INT_MAX, '\n');

	//Print to console
	std::cout << "Enter your name: ";

	//Input name
	std::getline(std::cin, name);

	//Pass name to char
	characters.push_back(Character());
	activeCharacter = characters.size() - 1;
	characters[activeCharacter].initialize(name);

	start = false;
	playing = true;
	

}
/////////////////////////////////////////////////////////////
//////////////////////  GAME MENU ///////////////////////////
/////////////////////////////////////////////////////////////
void Game::gameMenu()
{
	std::cout << "\nGAME MENU\n\n";
	std::cout << "1: Travel\n";
	std::cout << "2: Shop\n";
	std::cout << "3: Level up\n";
	std::cout << "4: Rest\n";
	std::cout << "5: Character Stats\n";
	std::cout << "6: Save Character\n";
	std::cout << "0: Quit\n\n";

	std::cout << "Choice: ";

	std::cin >> choice;

	switch (choice)
	{
	case 0:
		//Switching game states
		//Make sure choice is safe
		PlaySound("..\\Audio\\confirm.wav", NULL, SND_FILENAME);
		playing = false;
		start = true;
		choice = safeChoice;
		break;
	case 1: //Travel
		Travel();
		break;
	case 5: //Character Sheet
		PlaySound("..\\Audio\\confirm.wav", NULL, SND_FILENAME);
		if (characters.size() == 0)
		{
			std::cout << "No character selected. Please select a character.\n";
		}
		else
		{
			characters[activeCharacter].printStats();
			choice = safeChoice;
		}
		break;
	case 6: //Save Chars
		PlaySound("..\\Audio\\confirm.wav", NULL, SND_FILENAME);
		saveCharacters();
		std::cout << "Save successful.\n";
		choice = safeChoice;
		break;
	default:
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
		std::cout << "Invalid input. Try again.\n";
		break;
	}
}

/////////////////////////////////////////////////////////////
//////////////////////  MAIN MENU ///////////////////////////
/////////////////////////////////////////////////////////////
void Game::mainMenu()
{
	std::cout << "\nMAIN MENU\n\n";
	std::cout << "1: New Character\n";
	std::cout << "2: Load Character\n";
	std::cout << "3: Options\n";
	std::cout << "4: Character Stats\n";
	std::cout << "5: Save Characters\n";
	std::cout << "0: Quit\n\n";
	
	std::cout << "\nChoice: ";
	
	std::cin >> choice;

	switch (choice)
	{
	
	case 0:
		start = false;
		break;
	case 1:
		PlaySound("..\\Audio\\confirm.wav", NULL, SND_FILENAME);
		initGame();
		choice = safeChoice;
		
		break;
	case 2:
		PlaySound("..\\Audio\\confirm.wav", NULL, SND_FILENAME);
		loadCharacters();
		break;
	case 4:
		PlaySound("..\\Audio\\confirm.wav", NULL, SND_FILENAME);
		if (characters.size() == 0)
		{
			std::cout << "No character selected. Please select a character.\n";
		}
		else
		{
			characters[activeCharacter].printStats();
			choice = safeChoice;
		}
		break;
	case 5:
		PlaySound("..\\Audio\\confirm.wav", NULL, SND_FILENAME);
		saveCharacters();
		std::cout << "Save successful.\n";
		choice = safeChoice;
		break;
	default:
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
		std::cout << "Invalid Input. Try again.\n";
		break;
	}

	if (std::cin.fail())
	{
		std::cout << "Cin failed.\nCin failed.\nCin failed.\nCin failed.\nCin failed.\n";
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
	}
}

void Game::saveCharacters()
{
	std::ofstream outFile(fileName);

	if (outFile.is_open())
	{
		for (size_t i = 0; i < characters.size(); i++)
		{
			outFile << characters[i].getAsString() << "\n";
		}
	}
	outFile.close();
}

void Game::loadCharacters()
{

}

void Game::Travel()
{
	this->characters[activeCharacter].travel();

	Event event;

	event.generateEvent(this->characters[activeCharacter]);
}