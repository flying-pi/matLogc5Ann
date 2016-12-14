//
// Created by Yura Braiko on 14.12.16.
//

#include "PredicatParser.h"
#include <fstream>
#include <iostream>

using namespace std;

PredicatParser::PredicatParser(char *fileName) {

    ifstream in(fileName);
    in >> countLine;
    input = new char *[countLine];

    for (int i = 0; i < countLine; i++) {
        input[i] = new char[MAX_LINE_LENGTH];
    }

    in.getline(input[0], MAX_LINE_LENGTH);
    for (int i = 0; i < countLine; i++) {
        in.getline(input[i], MAX_LINE_LENGTH);
        cout << input[i] << endl;
    }
    in.close();
}

PredicatParser::~PredicatParser() {
    for (int i = 0; i < countLine; i++)
        delete[] input[i];
    delete[] input;

}

std::vector<Predicat*> PredicatParser::getParsedPredicat() {
    if(predicats.size() == 0)
        for(int i=0;i<countLine;i++)
            predicats.push_back(new Predicat(input[i]));
    return predicats;
}
