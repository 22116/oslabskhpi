//
// Created by victor on 1/11/19.
//

#ifndef LABSOS_ARGUMENTFETCHER_H
#define LABSOS_ARGUMENTFETCHER_H

#include <string>
#include <vector>

class ArgumentFetcher {
public:
    explicit ArgumentFetcher(int argc, char** argv);
    bool isOptionExists(std::string option);
    bool isArgumentExists(int index);
    bool isArgumentExists(std::string argument);
    std::string getArgument(int index);
    std::string getArgument(std::string argument);

private:
    std::vector <std::string> tokens;
    std::vector <std::string> getArgumentFormattedTokens();
    const std::string& getCmdOption(const std::string &option);
    bool cmdOptionExists(std::vector<std::string> tokens, const std::string &option);
};


#endif //LABSOS_ARGUMENTFETCHER_H
