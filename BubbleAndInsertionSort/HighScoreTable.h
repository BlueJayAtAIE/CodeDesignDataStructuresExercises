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

	// Accepts a range of elements to sort. Used as part of the MergeSort function to merge subsections of the array.
	// p is the first index to start merging and sorting from.
	// q is the index between p and r.
	// r is the last index to merge and sort through.
	void Merge(size_t p, size_t q, size_t r);
	// Using the Merge Sort method, organizes the enries in descending order.
	// p is the first index to start sorting from.
	// r is the last index to start sorting from.
	void MergeSort(size_t p, size_t r);

	// Extra: Prints the values of all the highscore entries to the console.
	void printValues();

	// Save the conents of hsVector back to highscores.txt in CSV format.
	void saveToFile(string fileName);
};