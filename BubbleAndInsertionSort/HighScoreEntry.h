#include <iostream>
#pragma once

using std::string;

class HighScoreEntry
{
public:
	string name;
	int score;
	int level;

	HighScoreEntry();
	HighScoreEntry(string Name, int Score, int Level);
	~HighScoreEntry();
};

