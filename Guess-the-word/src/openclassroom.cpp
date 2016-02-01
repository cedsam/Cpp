/*
 * openclassroom.cpp
 *
 *  Created on: 15 janv. 2016
 *      Author: SAMARDZIJA Cédric
 */

//C++ library
#include <string> // Need string variables.
#include <iostream> // Need i/o interfaces to interact with the user.
#include <fstream> // Need i/o interfaces to read/write into file.
#include <stdlib.h> // Need for random function.
#include <time.h> // Need for random function.
#include <vector> //Need to store dictionnary file.

std::string pickOneWord(std::string fileDirectory)
{
	std::ifstream file(fileDirectory.c_str());
	
	if (file.is_open())
	{
		std::string line; //Line of the text file
		std::vector<std::string> word;
		int lineAmount=0;

		if (word.empty())
		{
			//Need optimization (Opening the file everytime the program ask question).
			while (getline(file, line))
			{
				lineAmount++;
				word.push_back(line);
			}
		}


		//Get a random word from the text file
		srand(static_cast<unsigned int>(time(NULL))); // Initialize random seed.
		int const randomNumber = rand() % lineAmount;

		return word[randomNumber];
		//clearing all variable and end function with 0 status.
		file.clear();
		return 0;
	}
	else
	{
		std::cout << "Error opening the txt file";
		exit(EXIT_FAILURE);
	}
}

std::string askUser(std::string message)
{
	std::string input;
	std::cout << message;
	//Need optimization (User can spam the \n).
	std::cin >> input;
	return input;
}

std::string mixtureWord (std::string word)
{
	std::string mixedWord;

	while (word.size()!=0)
	{
		srand (static_cast<unsigned int>(time(NULL))); // Initialize random seed. #C4244 -> casting the int into unsigned int.
		int const randomNumber= rand() % word.size();
		mixedWord+=word[randomNumber];
		word.erase(randomNumber, 1);
	}
	return mixedWord;
}

void gameStatistics(int gameAmounts, int gameWin, int defeats, int attempts)
{
	std::cout << "You quit." << std::endl;
	double const winpercentage= static_cast<double>(gameWin) / static_cast<double>(gameAmounts) * 100;
	std::cout << "Win average: " << winpercentage << std::endl;
	std::cout << "Statistics: Number of games played: " << gameAmounts << " Number of win: " << gameWin << " Number of defeat: " << defeats << " Number of tries: " << attempts << std::endl;
}