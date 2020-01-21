#include <iostream>
#include "GameState.h"

using std::cout;
using std::cin;
using std::endl;

int main()
{
	char userInput = '?';
	bool gameOn = true;
	int rng = 0;

	while (gameOn)
	{
		cout << "----------------------------------------------------------" << endl;
		switch (GameState::GetInstance().getState())
		{
		case MainMenu:
			// Main Menu
			cout << "You're on the Main Menu. Press [S] to start." << endl;
			cin >> userInput;

			if (userInput == 's' || userInput == 'S')
			{
				GameState::GetInstance().setState(PlayerSelect);
			}
			else
			{
				cout << "I don't recognize that command..." << endl;
			}
			break;
		case PlayerSelect:
			// Player Choice
			cout << "Choose [R]ock, [P]aper, or [S]cissors." << endl;
			cin >> userInput;

			if ((userInput != 'r' && userInput != 'R') && (userInput != 'p' && userInput != 'P') && (userInput != 's' && userInput != 'S'))
			{
				cout << "I don't recognize that command..." << endl;
			}
			else
			{
				GameState::GetInstance().setState(InGame);
			}
			break;
		case InGame:
			// In-game
			// Convert a possible lowercase to uppercase just to make the following bits easier.
			if (userInput >= 97 && userInput <= 122)
			{
				userInput = userInput - 32;
			}

			cout << "You chose: ";
			switch (userInput)
			{
			case 'R':
				cout << "[Rock]" << endl;
				break;
			case 'P':
				cout << "[Paper]" << endl;
				break;
			case 'S':
				cout << "[Scissors]" << endl;
				break;
			default:
				cout << "[NULL]" << endl;
				break;
			}

			cout << "Computer chooses: ";
			rng = rand() % 3;
			switch (rng)
			{
			case 0:
				cout << "[Rock]" << endl;
				break;
			case 1:
				cout << "[Paper]" << endl;
				break;
			case 2:
				cout << "[Scissors]" << endl;
				break;
			default:
				cout << "[NULL]" << endl;
				break;
			}

			if ((userInput == 'R' && rng == 2) || (userInput == 'P' && rng == 0) || (userInput == 'S' && rng == 1))
			{
				cout << "You Win!" << endl;
			}
			else if ((userInput == 'R' && rng == 1) || (userInput == 'P' && rng == 2) || (userInput == 'S' && rng == 0))
			{
				cout << "Computer Wins!" << endl;
			}
			else
			{
				cout << "Tie Game!" << endl;
			}

			GameState::GetInstance().setState(GameOver);
			break;
		case GameOver:
			// Game Over
			cout << "Game Over! Press [S] to play again, or [Q] to quit." << endl;
			cin >> userInput;
			if (userInput == 's' || userInput == 'S')
			{
				GameState::GetInstance().setState(PlayerSelect);
			}
			else if (userInput == 'q' || userInput == 'Q')
			{
				gameOn = false;
			}
			else
			{
				cout << "I don't recognize that command..." << endl;
			}
			break;
		default:
			gameOn = false;
			break;
		}
	}
	return 0;
}