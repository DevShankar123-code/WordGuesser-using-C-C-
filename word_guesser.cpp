#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <cstring>
#include <cctype>
#include <cassert>
#include "util.h"
using namespace std;

const int MAXINPUTLEN = 100;
const int MAXWORDS = 9000;
bool isAllLower(const char word[])
{
	for (int i = 0; i < strlen(word); i++)
		if (!islower(word[i]))
			return false;
	return true;
}

bool inArray(const char probe[], const char words[][MAXWORDLEN + 1], int nWords)
{
	for (int i = 0; i < nWords; i++)
		if (strcmp(probe, words[i]) == 0)
			return true;
	return false;
}

string countRocksandPebbles(const char probe[], const char secret[], int& rocks, int& pebbles)
{
	const char rock_block = 'R';
	const char pebble_block = 'P';
	char probeCopy[MAXWORDLEN + 1];
	strcpy(probeCopy, probe);
	char secretCopy[MAXWORDLEN + 1];
	strcpy(secretCopy, secret);

	int minLen = (strlen(probeCopy) < strlen(secretCopy)) ? strlen(probeCopy) : strlen(secretCopy);
	rocks = 0;
	for (int i = 0; i < minLen; i++)
		if (probeCopy[i] == secretCopy[i])
		{
			rocks++;
			probeCopy[i] = rock_block;
			secretCopy[i] = rock_block;
		}

	pebbles = 0;
	for (int i = 0; i < strlen(probeCopy); i++)
	{
		if (probeCopy[i] == rock_block)
			continue;
		for (int j = 0; j < strlen(secretCopy); j++)
		{
			if (probeCopy[i] == secretCopy[j])
			{
				pebbles++;
				probeCopy[i] = pebble_block;
				secretCopy[j] = pebble_block;
				break;
			}
		}
	}
	string rocksAndPebblesLoc = probeCopy;
	for (int k = 0; k < rocksAndPebblesLoc.length(); k++)
		if (rocksAndPebblesLoc[k] != rock_block && rocksAndPebblesLoc[k] != pebble_block)
			rocksAndPebblesLoc[k] = ' ';
	return rocksAndPebblesLoc;
}

int manageOneRound(const char words[][MAXWORDLEN + 1], int nWords, int wordnum)
{
	if (nWords < 0 || wordnum < 0 || wordnum >= nWords)
		return -1;

	char secretWord[MAXWORDLEN + 1];
	strcpy(secretWord, words[wordnum]);

	char input[MAXINPUTLEN];
	int nTries = 0;
	int rocks = 0;
	int pebbles = 0;
	string location = "";
	while (true)
	{
		cout << "Probe word: ";
		cin.getline(input, MAXINPUTLEN);

		if (strlen(input) < MINWORDLEN || strlen(input) > MAXWORDLEN || !isAllLower(input))
		{
			cout << "Your probe word must be a word of " << MINWORDLEN << " to " << MAXWORDLEN << " lower case letters.\n";
			continue;
		}
		if (!inArray(input, words, nWords))
		{
			cout << "I don't know that word.\n";
			continue;
		}
		nTries++;
		if (strcmp(input, secretWord) == 0)
			return nTries;
		location = countRocksandPebbles(input, secretWord, rocks, pebbles);
		cout << endl << "            " << location << endl;
		cout << "Rocks: " << rocks << ", Pebbles: " << pebbles << endl;

	}
}

int main()
{
	char wordList[MAXWORDS][MAXWORDLEN + 1];
	int numWords = loadWords(wordList, MAXWORDS);
	if (numWords < 1)
	{
		cout << "No words were loaded, so I can't play the game.";
		return 1;
	}

	cout.setf(ios::fixed);
	cout.precision(2);

	int rounds = 0;
	cout << "How many rounds do you want to play? ";
	cin >> rounds;
	cin.ignore(10000, '\n');
	if (rounds <= 0)
	{
		cout << "The number of rounds must be positive." << endl;
		return 1;
	}

	int randPointer = 0;
	char sWord[MAXWORDLEN + 1] = "";
	int numTries = 0;
	int totalTries = 0;
	int minTries = 0;
	int maxTries = 0;
	for (int i = 1; i <= rounds; i++)
	{
		cout << endl << "Round " << i << endl;
		randPointer = randInt(0, numWords - 1);
		strcpy(sWord, wordList[randPointer]);
		cout << "The secret word is " << strlen(sWord) << " letters long." << endl;
		numTries = manageOneRound(wordList, numWords, randPointer);
		if (numTries == -1)
		{
			cout << "**** Internal program error:  manageOneRound returned -1!" << endl;
			return 1;
		}
		cout << "You got it in " << numTries;
		if (numTries == 1)
			cout << " try";
		else
			cout << " tries";
		cout << "." << endl;
		if (i == 1)
		{
			minTries = numTries;
			maxTries = numTries;
		}
		else if (numTries < minTries)
			minTries = numTries;
		else if (numTries > maxTries)
			maxTries = numTries;
		totalTries += numTries;
		cout << "Average: " << ((double)(totalTries) / i) << ", minimum: " << minTries << ", maximum: " << maxTries << endl;
	}
}