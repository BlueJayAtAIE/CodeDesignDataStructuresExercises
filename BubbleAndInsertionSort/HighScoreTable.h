#include "HighScoreEntry.h"
#include <vector>
#pragma once

using std::vector;

class HighScoreTable
{
public:
	// Contains all current entries within the highscore table.
	vector<HighScoreEntry> hsVector;


	// Constructs a table with no entries.
	HighScoreTable();

	// Constructs and populates a table with entries from a CSV.
	HighScoreTable(string fileName);


	// Returns a new vector containing the top number of high score entries.
	//   - topRows defines how many entries to return.
	vector<HighScoreEntry> topNNScores(int topRows);

	// Removes removes a number of entries from the bottom of the table.
	//   - bottomRows represents how many entries to remove.
	//   - Returns true if the number of entries removed matches the number requested.
	bool pruneBottomNNScores(int bottomRows);

	// Using the Bubble Sort method, organizes the enries in descending order.
	void bubbleSort();

	// Using the Insertion Sort method, organizes the enries in descending order.
	void insertionSort();

	// Extra: Prints the values of all the highscore entries to the console.
	void printValues();

	// Save the conents of hsVector back to highscores.txt in CSV format.
	void saveToFile();
};