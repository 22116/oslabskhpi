//
// Created by victor on 1/14/19.
//

#ifndef LABSOS_MACINTOSH_H
#define LABSOS_MACINTOSH_H


#include <string>
#include "IEncoding.h"

class ISO_8859_5 : public IEncoding {
public:
    std::string getId() override;

    unsigned char *getMask() override;
};


#endif //LABSOS_MACINTOSH_H
