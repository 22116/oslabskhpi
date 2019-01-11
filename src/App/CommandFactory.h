//
// Created by victor on 1/9/19.
//

#ifndef LABSOS_LABFACTORY_H
#define LABSOS_LABFACTORY_H

#include "Commands/ICommand.h"
#include <vector>
#include <string>

class CommandFactory {
public:
    ICommand* create(std::string id);

private:
    std::vector<ICommand*> getCommands();
};


#endif //LABSOS_LABFACTORY_H
