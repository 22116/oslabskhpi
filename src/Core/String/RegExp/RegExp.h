//
// Created by victor on 1/18/19.
//

#ifndef LABSOS_REGEXP_H
#define LABSOS_REGEXP_H

#include "Elem/IRegExpEl.h"
#include <vector>

class RegExp {
private:
    std::vector<IRegExpEl*> elems;

public:
    RegExp(std::string &pattern);
    std::pair<int, int> match(std::string &content);
};


#endif //LABSOS_REGEXP_H
