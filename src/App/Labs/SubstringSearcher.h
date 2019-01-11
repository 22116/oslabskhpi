//
// Created by victor on 1/9/19.
//

#ifndef LABSOS_SUBSTRINGSEARCHER_H
#define LABSOS_SUBSTRINGSEARCHER_H


#include "ILab.h"

# define NO_OF_CHARS 256

class SubstringSearcher : public ILab {
    int getId() override;
    void execute(char **argv) override;
};


#endif //LABSOS_SUBSTRINGSEARCHER_H
