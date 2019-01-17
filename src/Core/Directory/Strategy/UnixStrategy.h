//
// Created by victor on 1/15/19.
//

#ifndef LABSOS_UNIXSTRATEGY_H
#define LABSOS_UNIXSTRATEGY_H


#include "IStrategy.h"
#include <string>

class UnixStrategy : public IStrategy {
public:
    void explore(std::string path, std::function<void(std::string)> callback) override;
};


#endif //LABSOS_UNIXSTRATEGY_H
