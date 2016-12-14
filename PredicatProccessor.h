//
// Created by Yura Braiko on 14.12.16.
//

#ifndef MATLOGIC5_ANN_PREDICATPROCCESSOR_H
#define MATLOGIC5_ANN_PREDICATPROCCESSOR_H

#include <vector>
#include "Predicat.h"

using namespace std;

class PredicatProccessor {
public:
    PredicatProccessor(vector<Predicat *> predicats);
    virtual  ~PredicatProccessor();

    bool getCommonKvantor();
    bool getExistKvanotor();
    bool getCommonKvantorAnti();
    bool getExistKvantorAnti();

private:
    vector<Predicat*> predicats;
    bool *predicatCache;

};


#endif //MATLOGIC5_ANN_PREDICATPROCCESSOR_H
