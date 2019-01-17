//
// Created by victor on 1/13/19.
//

#ifndef LABSOS_IENCODING_H
#define LABSOS_IENCODING_H

class IEncoding {
public:
    virtual std::string getId() = 0;
    virtual unsigned char* getMask() = 0;
};

#endif //LABSOS_IENCODING_H
