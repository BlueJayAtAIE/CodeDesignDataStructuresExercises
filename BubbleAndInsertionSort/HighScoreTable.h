#include "HighScoreEntry.h"
#include <vector>
#pragma once

using std::vector;

class HighScoreTable
{
public:
	vector<HighScoreEntry> hsVector;
	vector<HighScoreEntry> topNNScores(int topRows);
	bool pruneBottomNNScores(int bottomRows);

	HighScoreTable(string fileName);
	~HighScoreTable();
};

