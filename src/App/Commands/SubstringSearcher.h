//
// Created by victor on 1/9/19.
//

#ifndef LABSOS_SUBSTRINGSEARCHER_H
#define LABSOS_SUBSTRINGSEARCHER_H


#include "ICommand.h"

# define NO_OF_CHARS 256

class SubstringSearcher : public ICommand {
public:
    std::string getId() override;
    void execute(ArgumentFetcher* argumentFetcher) override;
    bool verify(ArgumentFetcher *argumentFetcher) override;
    std::string getHelp() override;
};


#endif //LABSOS_SUBSTRINGSEARCHER_H
