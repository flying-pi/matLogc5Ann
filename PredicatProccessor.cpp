//
// Created by Yura Braiko on 14.12.16.
//

#include <iostream>
#include "PredicatProccessor.h"

PredicatProccessor::PredicatProccessor(vector<Predicat*> predicats) {
    this->predicats = predicats;
    predicatCache = new bool[predicats.size()];
    for (int i = 0; i < predicats.size(); i++)
        predicatCache[i] = predicats[i]->getvalue();

    for (int i = 0; i < predicats.size(); i++) {
        cout << "predicat :: " << predicats[i]->getPredicatSource() << " = " << predicats[i]->getvalue() << endl;
    }
}

PredicatProccessor::~PredicatProccessor() {
    delete[] predicatCache;
}

bool PredicatProccessor::getCommonKvantor() {
    bool  result = true;
    for(int i=0;i<predicats.size();i++)
        result &= predicatCache[i];
    return result;
}

bool PredicatProccessor::getExistKvanotor() {
    bool  result = false;
    for(int i=0;i<predicats.size();i++)
        result |= predicatCache[i];
    return result;
}

bool PredicatProccessor::getCommonKvantorAnti() {
    bool  result = true;
    for(int i=0;i<predicats.size();i++)
        result &= (!predicatCache[i]);
    return result;
}

bool PredicatProccessor::getExistKvantorAnti() {
    bool  result = false;
    for(int i=0;i<predicats.size();i++)
        result |= (!predicatCache[i]);
    return result;
}




