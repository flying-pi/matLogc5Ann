//
// Created by Yura Braiko on 14.12.16.
//

#ifndef MATLOGIC5_ANN_PREDICATPROCESSOR_H
#define MATLOGIC5_ANN_PREDICATPROCESSOR_H

#include "Predicat.h"
#include <vector>

class PredicatParser {
public:
    PredicatParser(char *fileName);
    virtual ~PredicatParser();
    std::vector<Predicat *> getParsedPredicat();

private:
    char **input;
    int countLine =0;
    std::vector<Predicat*> predicats;


    const int MAX_LINE_LENGTH = 1024;


};


#endif //MATLOGIC5_ANN_PREDICATPROCESSOR_H
