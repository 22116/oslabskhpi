//
// Created by victor on 1/9/19.
//

#include <iostream>
#include "EncodingSwitcher.h"
#include <string>
#include <vector>
#include "../../Core/File/EncodingFacade.h"
#include "../../Core/File/Encoding/KOI8.h"
#include "../../Core/File/Encoding/CP1251.h"

EncodingSwitcher::EncodingSwitcher(FileReader* fileReader, FileWriter* fileWriter, EncodingFacade* encodingFacade) {
    this->fileReader = fileReader;
    this->fileWriter = fileWriter;
    this->encodingFacade = encodingFacade;
}

std::string EncodingSwitcher::getId() {
    return "switch-encoding";
}

void EncodingSwitcher::execute(ArgumentFetcher* argumentFetcher) {
    std::string path, from, to;

    path = argumentFetcher->isArgumentExists("path")
        ? argumentFetcher->getArgument("path") : argumentFetcher->getArgument(1);

    from = argumentFetcher->isArgumentExists("from")
        ? argumentFetcher->getArgument("from") : argumentFetcher->getArgument(2);

    to = argumentFetcher->isArgumentExists("to")
       ? argumentFetcher->getArgument("to") : argumentFetcher->getArgument(3);

    std::string content = this->fileReader->read((char*)path.c_str());

    this->fileWriter->putContent((char*)path.c_str(), (char*)this->encodingFacade->encode(
            content, this->encodingFacade->parseEncoding(from), this->encodingFacade->parseEncoding(to)
    ));
}

bool EncodingSwitcher::verify(ArgumentFetcher *argumentFetcher) {
    return  (argumentFetcher->isArgumentExists("path") || argumentFetcher->isArgumentExists(1)) &&
            (argumentFetcher->isArgumentExists("from") || argumentFetcher->isArgumentExists(2)) &&
            (argumentFetcher->isArgumentExists("to") || argumentFetcher->isArgumentExists(3));
}

std::string EncodingSwitcher::getHelp() {
    return std::string() + " Help. This command changes file encoding.\n\n"

          + " Arguments:\n"
          + "     path - file path;\n"
          + "     from - source encoding;\n"
          + "     to   - target encoding;\n\n"

          + " Examples:\n"
          + "     ./command switch-encoding path from to\n"
          + "     ./command switch-encoding --path ./path --from utf8 --to cp1251\n";
}
