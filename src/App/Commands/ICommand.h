//
// Created by victor on 1/9/19.
//

#pragma once

#include "../../Core/Cli/ArgumentFetcher.h"

class ICommand {
public:
    virtual std::string getId() = 0;
    virtual void execute(ArgumentFetcher* argumentFetcher) = 0;
    virtual bool verify(ArgumentFetcher* argumentFetcher) = 0;
    virtual void showHelp() = 0;
};