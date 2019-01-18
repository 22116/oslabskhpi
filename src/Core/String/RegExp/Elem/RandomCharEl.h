//
// Created by victor on 1/18/19.
//

#ifndef LABSOS_RANDOMCHAREL_H
#define LABSOS_RANDOMCHAREL_H

#include <string>
#include "IRegExpEl.h"

class RandomCharEl : public IRegExpEl {
public:
    RandomCharEl(const std::string &pattern) : IRegExpEl(pattern) {}

    int type() override {
        return REXP_RCHAR;
    }
};


#endif //LABSOS_RANDOMCHAREL_H
