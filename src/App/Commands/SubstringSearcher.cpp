//
// Created by victor on 1/9/19.
//

#include "SubstringSearcher.h"
#include <string.h>
#include <stdio.h>
#include <iostream>
#include <map>

using namespace std;

std::string SubstringSearcher::getId() {
    return "find-string";
}

void SubstringSearcher::execute(ArgumentFetcher* argumentFetcher) {
    std::string path, str;

    path = argumentFetcher->isArgumentExists("path")
           ? argumentFetcher->getArgument("path") : argumentFetcher->getArgument(1);

    str = argumentFetcher->isArgumentExists("string")
           ? argumentFetcher->getArgument("string") : argumentFetcher->getArgument(2);


}

bool SubstringSearcher::verify(ArgumentFetcher *argumentFetcher) {
    return  (argumentFetcher->isArgumentExists("path") || argumentFetcher->isArgumentExists(1)) &&
            (argumentFetcher->isArgumentExists("string") || argumentFetcher->isArgumentExists(2));
}

std::string SubstringSearcher::getHelp() {
    return std::string() + " Help. This command searches for pattern in directory recursively.\n\n"

           + " Arguments:\n"
           + "     path   - file path;\n"
           + "     string - message to find;\n\n"

           + " Examples:\n"
           + "     ./command find-string path string\n"
           + "     ./command find-string --path ./path --string 'hello world'\n";
}
