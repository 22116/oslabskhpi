//
// Created by victor on 1/11/19.
//

#include "InvalidCommandIdentifierException.h"

InvalidEncodingException::InvalidEncodingException(std::string message) {
    this->message = message;
}

const char *InvalidEncodingException::what() const throw () {
    return this->message.c_str();
}