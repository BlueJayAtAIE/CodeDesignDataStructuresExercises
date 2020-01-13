#include "HighScoreTable.h"
#include <string>
#include <vector>

using std::vector;

int main()
{
	std::string highscoreTex = "highscores.txt";

	HighScoreTable hst(highscoreTex);
	hst.printValues();
	std::cout << std::endl;

	hst.bubbleSort();
	// Uncomment one of these to see them work!!
	//hst.insertionSort();

	hst.printValues();

	//hst.saveToFile(highscoreTex);

	//vector<HighScoreEntry> topScores = hst.topNNScores(10);
	//// Below is copied from HighScoreTable's printValues() function.
	//for (size_t i = 0; i < (topScores.size() - 1); i++)
	//{
	//	std::cout << "Name: " << topScores[i].name << ", Score: " << topScores[i].score << ", Level: " << topScores[i].level << std::endl;
	//}
	//std::cout << std::endl;

	//hst.pruneBottomNNScores(3);

	//topScores = hst.topNNScores(10);
	//for (size_t i = 0; i < (topScores.size() - 1); i++)
	//{
	//	std::cout << "Name: " << topScores[i].name << ", Score: " << topScores[i].score << ", Level: " << topScores[i].level << std::endl;
	//}

	while (true) { }
	return 0;
}