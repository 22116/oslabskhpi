//
// Created by victor on 1/18/19.
//

#ifndef LABSOS_SWITCHEREL_H
#define LABSOS_SWITCHEREL_H

#include <string>
#include "IRegExpEl.h"

class SwitcherEl : public IRegExpEl {
public:
    SwitcherEl(const std::string &pattern) : IRegExpEl(pattern) {}

    int type() override {
        return REXP_SWITCHER;
    }
};


#endif //LABSOS_SWITCHEREL_H
