/*
 * openclassroom.h
 *
 *  Created on: 15 janv. 2016
 *      Author: SAMARDZIJA Cédric
 */
#ifndef OPENCLASSROOM_H_
#define OPENCLASSROOM_H_

/* This function allow you to print a question for the user, and store the answer
 * into string variable.
 */
std::string askUser(std::string message);

/* This function allow you to mix a word and store the mixed word into string
 * variable.
 */
std::string mixtureWord (std::string word);

/* This function does statistics based on numbers of wins, numbers of loses,
 * number of games.
 */
void gameStatistics(int gameNumber, int gameWin, int defeats, int tries);

/* This function open a text file, pick and return a random word from the text file. */
std::string pickOneWord(std::string fileDirectory);

#endif /* OPENCLASSROOM_H_ */ 