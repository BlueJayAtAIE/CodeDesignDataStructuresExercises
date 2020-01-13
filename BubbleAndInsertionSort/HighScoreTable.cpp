#include <fstream>
#include <iostream>
#include <string>
#include "HighScoreTable.h"

using std::getline;

vector<HighScoreEntry> HighScoreTable::topNNScores(int topRows)
{
	return vector<HighScoreEntry>();
}

bool HighScoreTable::pruneBottomNNScores(int bottomRows)
{
	return true;
}

HighScoreTable::HighScoreTable(string fileName)
{
	// Open highscore file.
	std::fstream file;
	file.open(fileName, std::ios::in);
	if (!file.is_open())
	{
		std::cerr << "Something went wrong! File not found." << std::endl;
	}

	// Create HighScoreEntry temp.
	HighScoreEntry temp;
	string tempNumber;

	// While the file isn't at it's end.
	while (!file.eof())
	{
		// Set parameters of temp accordingly with the .CSV.
		getline(file, temp.name, ',');
		getline(file, tempNumber, ',');
		temp.score = std::stoi(tempNumber);
		getline(file, tempNumber);
		temp.level = std::stoi(tempNumber);

		// Add temp to hsVector.
		hsVector.push_back(temp);
	}

	// CLOSE HIGHSCORE FILE!!!!
	file.close();
}

HighScoreTable::~HighScoreTable()
{

}
