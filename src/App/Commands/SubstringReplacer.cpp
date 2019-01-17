//
// Created by victor on 1/17/19.
//

#include "SubstringReplacer.h"
#include <iostream>

std::string SubstringReplacer::getId() {
    return "replace-string";
}

void SubstringReplacer::execute(ArgumentFetcher *argumentFetcher) {
    std::string path, pattern, string;

    path = argumentFetcher->isArgumentExists("path")
           ? argumentFetcher->getArgument("path") : argumentFetcher->getArgument(1);

    pattern = argumentFetcher->isArgumentExists("pattern")
          ? argumentFetcher->getArgument("pattern") : argumentFetcher->getArgument(2);

    string = argumentFetcher->isArgumentExists("string")
              ? argumentFetcher->getArgument("string") : argumentFetcher->getArgument(3);

    auto files = this->explorer->getFileList(path);

    for (auto &filePath: files) {
        std::string content = this->fileReader->getFileContent((char*)filePath.c_str());
        auto result = this->searcher->find(content, pattern);

        if (result != -1) {
            content.replace(static_cast<unsigned long>(result), pattern.length(), string);
            this->fileWriter->putContent((char*)filePath.c_str(), (char*)content.c_str());
            std::cout << " Replaced in '" << filePath << "', position '" << result << "'\n";
        }
    }
}

bool SubstringReplacer::verify(ArgumentFetcher *argumentFetcher) {
    return  (argumentFetcher->isArgumentExists("path") || argumentFetcher->isArgumentExists(1)) &&
            (argumentFetcher->isArgumentExists("pattern") || argumentFetcher->isArgumentExists(2)) &&
            (argumentFetcher->isArgumentExists("string") || argumentFetcher->isArgumentExists(3));
}

std::string SubstringReplacer::getHelp() {
    return std::string() + " Help. This command searches for pattern in directory recursively and replaces it with string.\n\n"

           + " Arguments:\n"
           + "     path    - file path;\n"
           + "     pattern - message to find;\n"
           + "     string  - message to replace;\n\n"

           + " Examples:\n"
           + "     ./command replace-string path pattern string\n"
           + "     ./command replace-string --path ./path --pattern 'hello world' --string 'hello user'\n";
}

SubstringReplacer::SubstringReplacer(
    FileReader *fileReader, FileWriter *fileWriter, Explorer *explorer, Searcher *searcher
) {
    this->fileReader = fileReader;
    this->fileWriter = fileWriter;
    this->explorer = explorer;
    this->searcher = searcher;
}
