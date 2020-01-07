#include <iostream>
#include <fstream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::getline;

// TEXT FILES

int main()
{
	char userInput = '?';
	std::fstream file;
	std::string outputFromText;
	std::string inputFromConsole;
	int lineCount = 0;

	while (userInput != '!')
	{
		cout << "---------------------------------------------------------------" << endl;
		cout << "Press '?' for help." << endl << endl;
		cout << " > ";
		cin >> userInput;
		cout << endl;

		switch (userInput)
		{
		default:
			cout << "Unrecognized command." << endl;
			break;
		case '?':
			cout << "D: Display. Displays the contents of the text file." << endl << "W: Write. Write a new line onto the end of the text file." << endl;
			cout << "C: Clear. Clear the entirety of the contents of the text file." << endl << "!: Exit. Closes the program." << endl;
			break;
		case '!':
			cout << "Exiting...";
			break;
		case 'd':
			// Display
			file.open("text.txt", std::ios::in);

			if (!file.is_open())
			{
				std::cerr << "Something went wrong! File not found." << endl;
				return -1;
			}

			lineCount = 0;
			while (getline(file, outputFromText))
			{
				cout << outputFromText << endl;
				lineCount++;
			}
			cout << endl << "[" << lineCount << " lines printed.]" << endl;

			file.close();
			// -----------------------------------------------------------------
			break;
		case 'c':
			// Clear
			file.open("text.txt", std::ios::out);

			if (!file.is_open())
			{
				std::cerr << "Something went wrong! File not found." << endl;
				return -1;
			}

			file << "";
			file.flush();
			file.close();

			cout << "Text cleared." << endl;
			// ----------------------------------------------------------------
			break;
		case 'w':
			// Write
			file.open("text.txt", std::ios::app);

			if (!file.is_open())
			{
				std::cerr << "Something went wrong! File not found." << endl;
				return -1;
			}

			cout << "Enter the phrase you want to copy to the text file:" << endl;

			getline(cin, inputFromConsole, '\n');
			getline(cin, inputFromConsole, '\n');
			file << inputFromConsole << endl;
			file.flush();
			file.close();

			int test = 0;
			for (size_t i = 0; i < inputFromConsole.length(); i++)
			{
				if (inputFromConsole[i] >= 48 && inputFromConsole[i] <= 57)
				{
					test++;
				}
			}
			if (test == inputFromConsole.length())
			{
				cout << "You entered a whole number!" << endl;
			}

			test = 0;
			bool periodUsed = false;
			for (size_t i = 0; i < inputFromConsole.length(); i++)
			{
				if ((inputFromConsole[i] >= 48 && inputFromConsole[i] <= 57) || inputFromConsole[i] == 46)
				{
					test++;
					if (inputFromConsole[i] == 46)
					{
						if (periodUsed == false)
						{
							periodUsed = true;
						}
						else
						{
							periodUsed = false;
							break;
						}
					}

				}
			}
			if (test == inputFromConsole.length() && periodUsed)
			{
				cout << "You entered a decimal number!" << endl;
				if (inputFromConsole[inputFromConsole.length() - 1] == 46)
				{
					inputFromConsole += '0';
				}
			}

			if (inputFromConsole == "true" || inputFromConsole == "false")
			{
				cout << "You entered a bool!" << endl;
			}

			file << inputFromConsole << endl;
			file.flush();
			cout << endl << "[Copied: '" << inputFromConsole << "'.]" << endl;
			file.close();
			// -----------------------------------------------------------------
			break;
		}
	}

	return 0;
}