//
// Created by victor on 1/17/19.
//

#include "IOException.h"

const char *IOException::what() const throw() {
    return this->message.c_str();
}

IOException::IOException(std::string message) {
    this->message = message;
}
