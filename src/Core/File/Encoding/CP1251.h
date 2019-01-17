//
// Created by victor on 1/13/19.
//

#ifndef LABSOS_CP1251_H
#define LABSOS_CP1251_H


#include <string>
#include "IEncoding.h"

class CP1251 : public IEncoding {
public:
    std::string getId() override;
    unsigned char* getMask() override;
};


#endif //LABSOS_CP1251_H
