//
// Created by victor on 1/11/19.
//

#include <iostream>
#include "App.h"
#include "CommandFactory.h"
#include "Exception/InvalidCommandIdentifierException.h"

App::App(ArgumentFetcher* argumentFetcher) {
    this->argumentFetcher = argumentFetcher;
}

void App::run() {
    auto commandFactory = new CommandFactory();

    std::string commandIdentifier;

    if (argumentFetcher->isArgumentExists("id")) {
        commandIdentifier = argumentFetcher->getArgument("id");
    } else if (argumentFetcher->isArgumentExists(0)) {
        commandIdentifier = argumentFetcher->getArgument(0);
    }

    ICommand* command;

    try {
        command = commandFactory->create(commandIdentifier);
    } catch (InvalidEncodingException &err) {
        std::cout << err.what() << std::endl;
        return;
    }

    if (command->verify(argumentFetcher)) {
        try {
            command->execute(argumentFetcher);
            std::cout << " Operation completed successfuly. Exit.";
        } catch (InvalidEncodingException &err) {
            std::cout << err.what() << std::endl;
        }

    } else {
        std::cout << " Invalid params for '" << command->getId() << "' command." << std::endl << std::endl;
        std::cout << command->getHelp();
    }

    std::cout << std::endl;
}
