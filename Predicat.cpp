//
// Created by Yura Braiko on 14.12.16.
//

#include "Predicat.h"
#include <iostream>

using namespace std;

Predicat::Predicat(char *line) {

    vowelLetters = new char[VOWEL_LETTERS_COUNT]{'B', 'C', 'D', 'F', 'G', 'H', 'J', 'K', 'L', 'M', 'N', 'P', 'Q', 'R', 'S', 'T', 'V', 'W', 'X', 'Z'
            ,'b', 'c', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'm', 'n', 'p', 'q', 'r', 's', 't', 'v', 'w', 'x', 'z'};

    this->line = line;
    cachedValue = calculatePredicat(line);
}


bool Predicat::calculatePredicat(char *input) {
    int spacesCount = 0;
    int begin = 0;
    int end = 0;
    for (int i = 0; i < MAX_LINE_LENGTH; i++) {
        end++;
        if (input[i] == ' ' || input[i] == '\0') {
            spacesCount++;
            if (spacesCount % 2 == 1 && checkWord(input + begin, (end - begin)))
                return true;
            begin = end;
        }
        if (input[i] == '\0')
            break;
    }
    return false;
}

bool Predicat::checkWord(char *input, int length) {
    cout << "check word :: '";
    for (int i = 0; i < length; i++)
        cout << input[i];

    int vowelLetterCount = 0;
    for (int i = 0; i < length; i++) {
        for (int c = 0; c < VOWEL_LETTERS_COUNT; c++) {
            if (vowelLetters[c] == input[i]) {
                vowelLetterCount++;
                break;
            }
        }
    }
    cout << "' count vowel :: " << vowelLetterCount << endl;
    return vowelLetterCount > (length - vowelLetterCount);
}

char *Predicat::getPredicatSource() {
    return line;

}

bool Predicat::getvalue() {
    if(cachedValue == -1)
        cachedValue = calculatePredicat(line);
    return cachedValue!=0;
}
