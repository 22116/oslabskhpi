//
// Created by victor on 1/18/19.
//

#ifndef LABSOS_CHAREL_H
#define LABSOS_CHAREL_H

#include <string>
#include "IRegExpEl.h"

class CharEl : public IRegExpEl {
public:
    CharEl(const std::string &pattern) : IRegExpEl(pattern) {}

    int type() override {
        return REXP_CHAR;
    }
};


#endif //LABSOS_CHAREL_H
