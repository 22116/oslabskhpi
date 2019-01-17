//
// Created by victor on 1/11/19.
//

#include "ArgumentFetcher.h"
#include <string>
#include <string.h>
#include <algorithm>
#include <iostream>

ArgumentFetcher::ArgumentFetcher(int argc, char **argv) {
    for (int i = 1; i < argc; ++i) {
        this->tokens.emplace_back(argv[i]);
    }
}

const std::string& ArgumentFetcher::getCmdOption(const std::string &option) {
    std::vector<std::string>::const_iterator itr;
    itr =  std::find(this->tokens.begin(), this->tokens.end(), option);

    if (itr != this->tokens.end() && ++itr != this->tokens.end()) {
        return *itr;
    }

    return nullptr;
}

bool ArgumentFetcher::cmdOptionExists(std::vector<std::string> tokens, const std::string &option) {
    return std::find(tokens.begin(), tokens.end(), option) != tokens.end();
}

bool ArgumentFetcher::isOptionExists(std::string option) {
    return this->cmdOptionExists(this->tokens, "-" + option);
}

bool ArgumentFetcher::isArgumentExists(int index) {
    return this->getArgumentFormattedTokens().size() > index;
}

bool ArgumentFetcher::isArgumentExists(std::string argument) {
    return this->cmdOptionExists(this->tokens, "--" + argument);
}

std::string ArgumentFetcher::getArgument(int index) {
    return this->getArgumentFormattedTokens()[index];
}

std::string ArgumentFetcher::getArgument(std::string argument) {
    return this->getCmdOption("--" + argument);
}

std::vector<std::string> ArgumentFetcher::getArgumentFormattedTokens() {
    std::vector<std::string> tokens;

    for (int i = 0; i < this->tokens.size(); i++) {

        if (this->tokens[i].rfind("-", 0) == 0) {
            continue;
        }

        if (i != 0 && this->tokens[i - 1].rfind("-", 0) == 0) {
            continue;
        }

        tokens.push_back(this->tokens[i]);
    }

    return tokens;
}



