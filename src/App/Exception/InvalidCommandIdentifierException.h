//
// Created by victor on 1/9/19.
//

#ifndef LABSOS_INVALIDLABIDENTIFIEREXCEPTION_H
#define LABSOS_INVALIDLABIDENTIFIEREXCEPTION_H

#include <exception>
#include <string>

struct InvalidCommandIdentifierException : std::exception {
private:
    std::string message;

public:
    explicit InvalidCommandIdentifierException(std::string message);

    const char *what () const throw () override;
};


#endif //LABSOS_INVALIDLABIDENTIFIEREXCEPTION_H
