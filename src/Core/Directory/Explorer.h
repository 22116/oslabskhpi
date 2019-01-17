//
// Created by victor on 1/15/19.
//

#ifndef LABSOS_EXPLORER_H
#define LABSOS_EXPLORER_H

#include <string>
#include <vector>
#include "Strategy/IStrategy.h"

class Explorer {
public:
    Explorer(IStrategy* strategy);
    std::vector<std::string> getFileList(std::string path);

private:
    IStrategy* strategy;
};


#endif //LABSOS_EXPLORER_H
