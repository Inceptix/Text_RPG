#include "Game.h"


#include <random>


using namespace std;

int main()
{
	
	/*default_random_engine randomGenerator(time(NULL));
	uniform_real_distribution<float> attackRoll(0.0f, 1.0f);
	uniform_int_distribution<int> initialXP(5, 10);

	

	cout << "*** Welcome to Gladiator Simulator! ***\n" <<
			"============================================================================================================\n\n" <<
			"Your village was attacked by bandits and you were captured.\n" <<
			"The bandits have taken you back to their camp and enlisted you as a gladiator.\n" <<
			"As a gladiator, every fight, you either die or emerge victorious, while other poeple place bets on you.\n" <<
			"With every win you get a small share of money and gain experience.\n" <<
			"If you die...well let's just say that you want to stay alive.\n" <<
			"Now, what is your name, lad?\n";
	cin >> playerName;
		
	cout << "Well, " << playerName << " take a look around while you wait for your next match.\n";
	cout << "Also, based on your previous experiences from life you have " << initialXP(randomGenerator) << " experience\n" <<
			" points available to use to make yourself stronger.\n";*/

	srand(time(NULL));
	Game game;

	while (game.getStartGame())
	{
		game.mainMenu();

	}

	while (game.getPlaying())
	{
		game.gameMenu();

		while (game.getStartGame())
		{
			game.mainMenu();

		}
	}
	
	//system("pause");
	return 0;
}