#include "GameState.h"


GameState::GameState() { }
GameState::~GameState() { }

void GameState::operator=(GameState const &) { }

GameState & GameState::GetInstance()
{
	static GameState singletonInstance;
	return singletonInstance;
}

GStates GameState::getState()
{
	return currentState;
}

void GameState::setState(GStates newState)
{
	currentState = newState;
}