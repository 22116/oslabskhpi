//
// Created by victor on 1/9/19.
//

#include <string.h>
#include "CommandFactory.h"
#include "Commands/EncodingSwitcher.h"
#include "Commands/SubstringSearcher.h"
#include "Exception/InvalidCommandIdentifierException.h"

ICommand* CommandFactory::create(std::string id) {
    std::string list;

    for (auto &command : this->getCommands()) {
        list += " " + command->getId();
        if (command->getId() == id) {
            return command;
        }
    }

    throw InvalidCommandIdentifierException(
            "Invalid command identifier.\nAvailable commands:" + list
        );
}

std::vector<ICommand*> CommandFactory::getCommands() {
    std::vector<ICommand*> list;

    list.push_back(new EncodingSwitcher(new FileReader, new FileWriter));
    list.push_back(new SubstringSearcher());

    return list;
}
