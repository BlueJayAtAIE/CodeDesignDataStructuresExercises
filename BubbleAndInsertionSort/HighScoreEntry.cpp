#include "HighScoreEntry.h"

HighScoreEntry::HighScoreEntry()
{
	name = "Placeholder";
	score = 0;
	level = 0;
}

HighScoreEntry::HighScoreEntry(string Name, int Score, int Level)
{
	name = Name;
	score = Score;
	level = Level;
}

HighScoreEntry::~HighScoreEntry() { }
