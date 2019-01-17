//
// Created by victor on 1/17/19.
//

#ifndef LABSOS_SUBSTRINGREPLACER_H
#define LABSOS_SUBSTRINGREPLACER_H


#include "ICommand.h"
#include "../../Core/File/FileWriter.h"
#include "../../Core/File/FileReader.h"
#include "../../Core/Directory/Explorer.h"
#include "../../Core/String/Searcher.h"

class SubstringReplacer : public ICommand {
private:
    FileReader* fileReader;
    FileWriter* fileWriter;
    Explorer* explorer;
    Searcher* searcher;

public:
    SubstringReplacer(FileReader* fileReader, FileWriter* fileWriter, Explorer* explorer, Searcher* searcher);
    std::string getId() override;
    void execute(ArgumentFetcher *argumentFetcher) override;
    bool verify(ArgumentFetcher *argumentFetcher) override;
    std::string getHelp() override;
};


#endif //LABSOS_SUBSTRINGREPLACER_H
