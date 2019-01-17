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

    str = argumentFetcher->isArgumentExists("pattern")
           ? argumentFetcher->getArgument("pattern") : argumentFetcher->getArgument(2);

    auto files = this->explorer->getFileList(path);

    for (auto &filePath: files) {
        auto content = this->fileReader->getFileContent((char*)filePath.c_str());
        auto result = this->searcher->find(content, str);

        if (result != -1) {
            std::cout << " Found in '" << filePath << "', position '" << result << "'\n";
        }
    }
}

bool SubstringSearcher::verify(ArgumentFetcher *argumentFetcher) {
    return  (argumentFetcher->isArgumentExists("path") || argumentFetcher->isArgumentExists(1)) &&
            (argumentFetcher->isArgumentExists("pattern") || argumentFetcher->isArgumentExists(2));
}

std::string SubstringSearcher::getHelp() {
    return std::string() + " Help. This command searches for pattern in directory recursively.\n\n"

           + " Arguments:\n"
           + "     path   - file path;\n"
           + "     pattern - message to find;\n\n"

           + " Examples:\n"
           + "     ./command find-string path pattern\n"
           + "     ./command find-string --path ./path --pattern 'hello world'\n";
}

SubstringSearcher::SubstringSearcher(FileReader *fileReader, Explorer *explorer, Searcher* searcher) {
    this->fileReader = fileReader;
    this->explorer = explorer;
    this->searcher = searcher;
}
