//
// Created by victor on 1/11/19.
//

#include "InvalidCommandIdentifierException.h"

InvalidCommandIdentifierException::InvalidCommandIdentifierException(std::string message) {
    this->message = message;
}

const char *InvalidCommandIdentifierException::what() const throw () {
    return this->message.c_str();
}