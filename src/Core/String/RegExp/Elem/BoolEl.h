//
// Created by victor on 1/18/19.
//

#ifndef LABSOS_BOOLEL_H
#define LABSOS_BOOLEL_H

#include <string>
#include "IRegExpEl.h"


class BoolEl : public IRegExpEl {
public:
    BoolEl(const std::string &pattern) : IRegExpEl(pattern) {}

    int type() override {
        return REXP_BOOL;
    }
};


#endif //LABSOS_BOOLEL_H
