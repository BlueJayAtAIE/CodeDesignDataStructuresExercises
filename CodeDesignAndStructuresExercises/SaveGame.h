#pragma once
class SaveGame
{
public:
	SaveGame();
	~SaveGame();

	int money;
	float speed; // I would never actually store player speed in a save file... but as a concept it's really funny and its just an exercise.
	bool isCool;
	char name[50];
};

