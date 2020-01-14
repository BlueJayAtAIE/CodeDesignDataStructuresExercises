#include <fstream>
#include <iostream>
#include <string>
#include "HighScoreTable.h"

using std::getline;

HighScoreTable::HighScoreTable() { }

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

vector<HighScoreEntry> HighScoreTable::topNNScores(int topRows)
{
	vector<HighScoreEntry> temp;

	for (size_t i = 0; i < topRows; i++)
	{
		// If asking for more rows than we have entries, break early.
		if (i >= hsVector.size())
		{
			break;
		}

		temp.push_back(hsVector[i]);
	}

	return temp;
}

bool HighScoreTable::pruneBottomNNScores(int bottomRows)
{
	if (bottomRows > hsVector.size())
	{
		// Can't remove that many! Thats outside the bounds of the array.
		return false;
	}

	for (size_t i = 0; i < bottomRows; i++)
	{
		hsVector.pop_back();
	}

	return true;
}

void HighScoreTable::bubbleSort()
{
	for (size_t i = 0; i < (hsVector.size() - 1); i++)
	{
		// For each element i...
		for (size_t j = (hsVector.size() - 1); j >= i + 1; j--)
		{
			// Compare to each element j... 
			if (hsVector[j].score < hsVector[j-1].score)
			{
				// If j is less than i, swap the values.
				HighScoreEntry temp = hsVector[j];
				hsVector[j] = hsVector[j - 1];
				hsVector[j - 1] = temp;
			}
		}
	}
}

void HighScoreTable::insertionSort()
{
	// Starting with the SECOND value, for each value in the array...
	for (size_t i = 1; i < hsVector.size(); i++)
	{
		// the key is the value at the current index.
		HighScoreEntry key = hsVector[i];
		size_t j = i - 1;

		// while the key'd value is less than the value to it's left...
		while (j >= 0 && hsVector[j].score > key.score)
		{
			// Swap the values.
			hsVector[j + 1] = hsVector[j];
			j = j - 1;
			hsVector[(j + 1)] = key;

			// Extra check to make sure j never overflows.
			if (j > hsVector.size())
			{
				j = 0;
			}
		}
	}
}

void HighScoreTable::Merge(size_t p, size_t q, size_t r)
{
	size_t leftEnd = q - p + 1;
	size_t rightEnd = r - q;

	// Create two empty containers.
	vector<HighScoreEntry> containerL;
	containerL.resize(leftEnd);
	vector<HighScoreEntry> containerR;
	containerR.resize(rightEnd);

	// Copy values from hsVector to the respective containers.
	for (size_t i = 0; i < leftEnd; i++)
	{
		containerL[i] = hsVector[p + i];
	}
	for (size_t j = 0; j < rightEnd; j++)
	{
		containerR[j] = hsVector[q + j + 1];
	}

	size_t i = 0;
	size_t j = 0;

	for (size_t k = p; k <= r; k++)
	{
		if ((j >= rightEnd) || (i < leftEnd && containerL[i].score <= containerR[j].score))
		{
			hsVector[k] = containerL[i];
			i++;
		}
		else
		{
			hsVector[k] = containerR[j];
			j++;
		}
	}
}

void HighScoreTable::MergeSort(size_t p, size_t r)
{
	if (p < r)
	{
		size_t q = (p + r) / 2;
		MergeSort(p, q);
		MergeSort(q + 1, r);
		Merge(p, q, r);
	}
}

void HighScoreTable::printValues()
{
	for (size_t i = 0; i < hsVector.size(); i++)
	{
		std::cout << "Name: " << hsVector[i].name << ", Score: " << hsVector[i].score << ", Level: " << hsVector[i].level << std::endl;
	}
}

void HighScoreTable::saveToFile(string fileName)
{
	// Open highscore file.
	std::fstream file;
	file.open(fileName, std::ios::out);
	if (!file.is_open())
	{
		std::cerr << "Something went wrong! File not found." << std::endl;
	}

	// For each entry in hsVector...
	for (size_t i = 0; i < hsVector.size(); i++)
	{
		// Print the values of the highscore entry into the file, separated by a ,.
		file << hsVector[i].name << "," << hsVector[i].score << "," << hsVector[i].level;

		// As long as this isn't the last entry, start a new line.
		if (i != hsVector.size() - 1)
		{
			file << std::endl;
		}

		file.flush();
	}

	// CLOSE HIGHSCORE FILE!!!!
	file.close();
}