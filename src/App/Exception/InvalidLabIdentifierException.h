//
// Created by victor on 1/9/19.
//

#ifndef LABSOS_INVALIDLABIDENTIFIEREXCEPTION_H
#define LABSOS_INVALIDLABIDENTIFIEREXCEPTION_H

#include <exception>

struct InvalidLabIdentifierException : std::exception {
    const char *what () const throw ()
    {
        return "Invalid lab identifier";
    }
};


#endif //LABSOS_INVALIDLABIDENTIFIEREXCEPTION_H
