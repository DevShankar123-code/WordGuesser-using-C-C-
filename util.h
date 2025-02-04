#pragma once
#include <cstdlib>
#include <ctime>
#include <cstring>

const int MINWORDLEN = 4;
const int MAXWORDLEN = 6;

int loadWords(char words[][MAXWORDLEN + 1], int maxWords) {
    const char* wordList[] = {
        "game", "word", "play", "quiz", "test", "code", "java", "cplus", "html", "css"
    };

    int numWords = sizeof(wordList) / sizeof(wordList[0]);
    int wordsLoaded = 0;

    for (int i = 0; i < numWords && wordsLoaded < maxWords; ++i) {
        int len = strlen(wordList[i]);
        if (len >= MINWORDLEN && len <= MAXWORDLEN) {
            strncpy(words[wordsLoaded], wordList[i], MAXWORDLEN + 1);
            wordsLoaded++;
        }
    }

    return wordsLoaded; 
}

int randInt(int min, int max) {
    return min + rand() % (max - min + 1);
}
void seedRandom() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
}
