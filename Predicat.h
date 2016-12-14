//
// Created by Yura Braiko on 14.12.16.
//

#ifndef MATLOGIC5_ANN_PREDICAT_H
#define MATLOGIC5_ANN_PREDICAT_H


class Predicat {
public:
    Predicat(char *line);
    char *getPredicatSource();
    bool getvalue();

private:
    const int MAX_LINE_LENGTH = 1024;

    char *line;
    int VOWEL_LETTERS_COUNT = 40;
    char *vowelLetters;
    bool calculatePredicat(char *input);
    bool checkWord(char *input,int length);

    int cachedValue=-1;
};


#endif //MATLOGIC5_ANN_PREDICAT_H
