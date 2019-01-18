//
// Created by victor on 1/18/19.
//

#ifndef LABSOS_RANGEEL_H
#define LABSOS_RANGEEL_H

#include <string>
#include "IRegExpEl.h"

class RangeEl : public IRegExpEl {
private:
    IRegExpEl* el;

public:
    explicit RangeEl(IRegExpEl* el) : IRegExpEl("") {
        this->el = el;
    }

    IRegExpEl *child() override {
        return this->el;
    }

    int type() override {
        return REXP_RANGE;
    }
};


#endif //LABSOS_RANGEEL_H
