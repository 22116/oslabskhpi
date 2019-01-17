//
// Created by victor on 1/15/19.
//

#ifndef LABSOS_ISTRATEGY_H
#define LABSOS_ISTRATEGY_H

#include <dirent.h>
#include <string>
#include <functional>

class IStrategy {
public:
    virtual void explore(std::string path, std::function<void(std::string)> callback) = 0;
};

#endif //LABSOS_ISTRATEGY_H
