//
// Created by victor on 1/13/19.
//

#ifndef LABSOS_ENCODINGMANAGER_H
#define LABSOS_ENCODINGMANAGER_H

#include <string>
#include "Encoding/IEncoding.h"
#include <vector>

class EncodingFacade {
private:
    std::vector<IEncoding*> getEncodings();

public:
    unsigned char* encode(std::string content, IEncoding* source, IEncoding* target);
    IEncoding* parseEncoding(std::string encoding);
};


#endif //LABSOS_ENCODINGMANAGER_H
