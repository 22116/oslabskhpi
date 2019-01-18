//
// Created by victor on 1/18/19.
//

#ifndef LABSOS_IREGEXPEL_H
#define LABSOS_IREGEXPEL_H

#include <string>

#define REXP_SWITCHER 0
#define REXP_CHAR     1
#define REXP_RCHAR    2
#define REXP_RANGE    3
#define REXP_BOOL     3

class IRegExpEl {
private:
    std::string pattern;
    IRegExpEl* el;

public:
    explicit IRegExpEl(std::string pattern) {
        this->pattern = std::move(pattern);
    }

    IRegExpEl(IRegExpEl* pattern) { }

    std::string value() {
        return this->pattern;
    }

    virtual IRegExpEl* child() {
        return this->el;
    }

    virtual int type() = 0;
};


#endif //LABSOS_IREGEXPEL_H
