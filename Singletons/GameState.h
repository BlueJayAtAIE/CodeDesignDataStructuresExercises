#pragma once

enum GStates
{
	MainMenu = 0,
	PlayerSelect,
	InGame,
	GameOver
};

class GameState
{
private:
	GStates currentState = MainMenu;  // Current Game state.
	GameState();                      // Default constructor. Prevents external use.
	GameState(GameState const&);      // Copy constructor. Prevents external use.
	void operator=(GameState const&); // Copy assignment. Prevents external use.

public:
	GStates getState();              // Return the current game state.
	void setState(GStates newState); // Set the game state accordingly.
	static GameState& GetInstance(); // Returns the singleton instance.
	~GameState();                    // Destructor.
};

