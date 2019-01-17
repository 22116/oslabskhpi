//
// Created by victor on 1/9/19.
//

#ifndef LABSOS_INVALIDENCODINGEXCEPTION_H
#define LABSOS_INVALIDENCODINGEXCEPTION_H

#include <exception>
#include <string>

struct InvalidEncodingException : std::exception {
private:
    std::string message;

public:
    explicit InvalidEncodingException(std::string message);

    const char *what () const throw () override;
};


#endif //LABSOS_INVALIDENCODINGEXCEPTION_H
