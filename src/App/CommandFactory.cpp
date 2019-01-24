//
// Created by victor on 1/9/19.
//

#include <string.h>
#include "CommandFactory.h"
#include "Commands/EncodingSwitcher.h"
#include "Commands/SubstringSearcher.h"
#include "Exception/InvalidCommandIdentifierException.h"
#include "Commands/SubstringReplacer.h"

#ifdef __unix__
#include "../Core/Directory/Strategy/UnixStrategy.h"
#endif

#ifdef OS_Windows
#include "../Core/Directory/Strategy/WinStrategy.h"
#endif


ICommand* CommandFactory::create(std::string id) {
    std::string list;

    for (auto &command : this->getCommands()) {
        list += " " + command->getId();
        if (command->getId() == id) {
            return command;
        }
    }

    throw InvalidEncodingException(
            "Invalid command identifier.\nAvailable commands:" + list
        );
}

std::vector<ICommand*> CommandFactory::getCommands() {
    std::vector<ICommand*> list;
    IStrategy* strategy;

    #ifdef __unix__
    strategy = new UnixStrategy;
    #endif

    #ifdef OS_Windows
    strategy = new WinStrategy;
    #endif

    list.push_back(new EncodingSwitcher(new FileReader, new FileWriter, new EncodingFacade));
    list.push_back(new SubstringSearcher(new FileReader, new Explorer(strategy), new Searcher));
    list.push_back(new SubstringReplacer(
            new FileReader, new FileWriter, new Explorer(strategy), new Searcher)
    );

    return list;
}
