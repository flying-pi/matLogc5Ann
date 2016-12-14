#include <iostream>
#include <fstream>
#include "PredicatParser.h"
#include "PredicatProccessor.h"

using namespace std;


int main() {
    char *fileName = "/Users/yurabraiko/dev/temp/c++/matLogic5_Ann/test.txt";
    PredicatParser parser(fileName);
    vector<Predicat *> predicatList = parser.getParsedPredicat();
    PredicatProccessor proccessor(predicatList);
    cout << "______________________________________________________________" << endl;
    cout << "common kvantor result :: " << proccessor.getCommonKvantor() << endl;
    cout << "exist kvantor result :: " << proccessor.getExistKvanotor() << endl;
    cout << "common kvantor with negativ result :: " << proccessor.getCommonKvantorAnti() << endl;
    cout << "exist kvantor with negativ result :: " << proccessor.getExistKvantorAnti() << endl;
    cout << "______________________________________________________________";
    return 0;
}