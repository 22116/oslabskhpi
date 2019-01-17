//
// Created by victor on 1/14/19.
//

#include "ISO_8859_5.h"

std::string ISO_8859_5::getId() {
    return "iso_8859_5";
}

unsigned char *ISO_8859_5::getMask() {
    static unsigned char arr[] = {
        0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0xD5, 0xF2, 0xD6, 0xD7, 0xD8,
        0xD9, 0xDA, 0xDB, 0xDC, 0xDD, 0xDE, 0xDF, 0xE0, 0xE1, 0xE2,
        0xE3, 0xE4, 0xE5, 0xE6, 0xE7, 0xE8, 0xE9, 0xEA, 0xEB, 0xEC,
        0xED, 0xEE, 0xEF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4, 0xB5, 0xA1,
        0xB6, 0xB7, 0xB8, 0xB9, 0xBA, 0xBB, 0xBC, 0xBD, 0xBE, 0xBF,
        0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9,
        0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF
    };

    return arr;
}
