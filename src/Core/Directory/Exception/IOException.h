//
// Created by victor on 1/17/19.
//

#ifndef LABSOS_IOEXCEPTION_H
#define LABSOS_IOEXCEPTION_H

#include <bits/exception.h>
#include <string>

class IOException : std::exception {
private:
    std::string message;

public:
    explicit IOException(std::string message);
    const char *what() const throw() override;
};


#endif //LABSOS_IOEXCEPTION_H
