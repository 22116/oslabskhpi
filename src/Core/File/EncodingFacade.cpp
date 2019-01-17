//
// Created by victor on 1/13/19.
//

#include "EncodingFacade.h"
#include "Encoding/CP1251.h"
#include "Encoding/KOI8.h"
#include "./Exception/InvalidEncodingException.h"
#include "Encoding/ISO_8859_5.h"
#include <iostream>

unsigned char* EncodingFacade::encode(std::string content, IEncoding *source, IEncoding *target) {
    auto *buffer = static_cast<unsigned char *>(malloc(content.size() * sizeof(unsigned char)));

    for (int i = 0; i < content.size(); i++) {
        buffer[i] = static_cast<unsigned char>(content[i]);

        for (int j = 0; j < 66; j++) {
            if (static_cast<unsigned char>(content[i]) == source->getMask()[j]) {
                buffer[i] = target->getMask()[j];
            }
        }
    }

    return buffer;
}

IEncoding* EncodingFacade::parseEncoding(std::string encoding) {
    std::string list;

    for (auto &encodingObject : this->getEncodings()) {
        list += " " + encodingObject->getId();
        if (encodingObject->getId() == encoding) {
            return encodingObject;
        }
    }

    throw InvalidEncodingException(" Can't recognize encoding: " + encoding + ". Available encodings: " + list);
}

std::vector<IEncoding*> EncodingFacade::getEncodings() {
    std::vector<IEncoding*> list;

    list.push_back(new CP1251);
    list.push_back(new KOI8);
    list.push_back(new ISO_8859_5);

    return list;
}
