//
// Created by victor on 1/17/19.
//

#ifndef LABSOS_WINSTRATEGY_H
#define LABSOS_WINSTRATEGY_H


#include "IStrategy.h"

class WinStrategy : public IStrategy {
public:
    void explore(std::string path, std::function<void(std::string)> callback) override;
};


#endif //LABSOS_WINSTRATEGY_H
