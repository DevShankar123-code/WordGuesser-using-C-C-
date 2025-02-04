#define _CRT_SECURE_NO_DEPRECATE
#include "util.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <cctype>
#include <random>
#include <utility>
using namespace std;
const char WORDFILENAME[] = "C:/Dev/c++worddetectorminiproject/words.txt";
int loadWords(char words[][MAXWORDLEN + 1], int maxWords)
{
    ifstream wordfile(WORDFILENAME);
    if (!wordfile)
    {
        cout << "Cannot open " << WORDFILENAME << "!" << endl;
        return -1;
    }
    const int MAXFILELINELEN = 10000;
    char line[MAXFILELINELEN];
    int numWords = 0;
    while (wordfile.getline(line, MAXFILELINELEN))
    {
        if (numWords == maxWords)
        {
            cout << "Using only the first " << numWords << " words from "
                << WORDFILENAME << "." << endl;
            break;
        }


        int k;
        for (k = 0; islower(line[k]); k++)
            ;
        if (line[k] == '\r')
            line[k] = '\0';

        if (line[k] == '\0' && k >= MINWORDLEN && k <= MAXWORDLEN)
        {
            strcpy(words[numWords], line);
            numWords++;
        }
    }
    return numWords;
}

int randInt(int min, int max)
{
    if (max < min)
        swap(max, min);
    static random_device rd;
    static mt19937 generator(rd());
    uniform_int_distribution<> distro(min, max);
    return distro(generator);
}