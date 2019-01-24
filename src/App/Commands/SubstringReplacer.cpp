//
// Created by victor on 1/17/19.
//

#include "SubstringReplacer.h"
#include <iostream>
#include <string.h>
#include <algorithm>

std::string SubstringReplacer::getId() {
    return "replace-string";
}

void SubstringReplacer::execute(ArgumentFetcher *argumentFetcher) {
    std::string path, matchesPath;

    path = argumentFetcher->isArgumentExists("path")
           ? argumentFetcher->getArgument("path") : argumentFetcher->getArgument(1);

    matchesPath = argumentFetcher->isArgumentExists("match-path")
              ? argumentFetcher->getArgument("match-path") : argumentFetcher->getArgument(2);

    std::vector<std::pair<std::string, std::string>> matches;

    this->fileReader->read(matchesPath, [&](std::string buff) -> bool {
        char pattern[100], string[100];
        sscanf(buff.c_str(), "'%[^\t\n']' '%[^\t\n']'", pattern, string);
        matches.emplace_back(std::pair<std::string, std::string>(pattern, string));
        return false;
    });

    if (matches.empty()) {
        std::cout << " No matches were found in the file" << std::endl;
        return;
    }

    std::sort(matches.begin(), matches.end(), [](std::pair<std::string, std::string> i, std::pair<std::string, std::string> j) -> bool {
        return i.first.length() > j.second.length();
    });

    this->explorer->explore(path, [&](std::string filePath) -> void {
        std::string tmpName = filePath + std::string(".temp");
        this->fileReader->read(filePath, [&](std::string buff) -> bool {
            for (auto &match : matches) {
                std::pair<int, int> result;

                while ((result = this->searcher->findRegexp(buff, match.first)).first != -1) {
                    buff.replace(static_cast<unsigned long>(result.first), static_cast<unsigned long>(result.second), match.second);
                    std::cout << " Replaced in '" << filePath << "'" << std::endl;
                }
            }

            this->fileWriter->append((char*)tmpName.c_str(), (char*)buff.c_str());

            return false;
        });
        remove(filePath.c_str());
        rename(tmpName.c_str(), filePath.c_str());
    });
}

bool SubstringReplacer::verify(ArgumentFetcher *argumentFetcher) {
    return  (argumentFetcher->isArgumentExists("path") || argumentFetcher->isArgumentExists(1)) &&
            (argumentFetcher->isArgumentExists("match-path") || argumentFetcher->isArgumentExists(2));
}

std::string SubstringReplacer::getHelp() {
    return std::string() + " Help. This command searches for pattern in directory recursively and replaces it with string.\n\n"

           + " Arguments:\n"
           + "     path          - file path;\n"
           + "     match-path  - file path with matches pairs to replace;\n\n"

           + " Examples:\n"
           + "     ./command replace-string path match-path\n"
           + "     ./command replace-string --path ./path --match-path ./path2\n";
}

SubstringReplacer::SubstringReplacer(
    FileReader *fileReader, FileWriter *fileWriter, Explorer *explorer, Searcher *searcher
) {
    this->fileReader = fileReader;
    this->fileWriter = fileWriter;
    this->explorer = explorer;
    this->searcher = searcher;
}
