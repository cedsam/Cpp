/*
 * main.cpp
 *
 *  Created on: 15 janv. 2016
 *      Author: SAMARDZIJA Cédric
 */

//C++ library
#include <string> //Need string variables.
//Own library (see the header file for more explanation). List: askUser, mixtureWord
#include "openclassroom.h"

int main () // "Guess the word" game in OCR lessons.
{
		std::string wannaPlay;
		int gameAmounts=0;
		int gameWin=0;
		int defeats=0;
		int attempts=0;

		do 
		{
			bool isGuessedResult = false;
			int numberAttempts=0;
			std::string const dictionnaryDirectory("C:/Users/user/dico.txt");
			std::string word(pickOneWord(dictionnaryDirectory));
			std::string mixedWord (mixtureWord(word));
			std::string guessWord (askUser ("Guess the following word in the correct order: " + mixedWord + " \n"));
			gameAmounts++;

			while (isGuessedResult == false)//int guessResult = 0; ==> wasn't clear enough, replace with isGuessedResult
			{
				if ((guessWord!=word) && (numberAttempts!=4))
				{
					attempts++;
					numberAttempts++;
					guessWord=askUser("You are wrong, try again ");
				}
				else if (guessWord==word)
				{
					gameWin++;
					isGuessedResult = true;
					wannaPlay = (askUser("Wanna play again? [yes/no] "));
				}
				else if ((guessWord!=word) && (numberAttempts==4))
				{
					defeats++;
					isGuessedResult  = true;
					wannaPlay = (askUser("The solution was " + word + ". \n" "Wanna play again? [yes/no] "));
					
					while ((wannaPlay != "no") && (wannaPlay != "n") && (wannaPlay != "yes") && (wannaPlay != "y"))
					{
						wannaPlay = (askUser("Wanna play again? [yes/no] "));
					} 
				}
			}

			word.clear();
			mixedWord.clear();
			guessWord.clear();

			isGuessedResult = true;

		} while ((wannaPlay != "no") && (wannaPlay != "n"));
		gameStatistics(gameAmounts,gameWin,defeats,attempts);

		//clearing all variable.
		wannaPlay.clear();
		gameAmounts = 0;
		gameWin = 0;
		defeats = 0;
		attempts = 0;

		//end of program
		exit(EXIT_SUCCESS);
}