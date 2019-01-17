//
// Created by victor on 1/14/19.
//

#ifndef LABSOS_KOI8_H
#define LABSOS_KOI8_H


#include <string>
#include "IEncoding.h"

class KOI8 : public IEncoding {
public:
    unsigned char *getMask() override;

    std::string getId() override;
};


#endif //LABSOS_KOI8_H
