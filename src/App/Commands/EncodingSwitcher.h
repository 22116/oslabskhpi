//
// Created by victor on 1/9/19.
//

#ifndef LABSOS_ENCODINGSWITCHER_H
#define LABSOS_ENCODINGSWITCHER_H

#include "ICommand.h"
#include "../../Core/File/FileReader.h"
#include "../../Core/File/FileWriter.h"
#include <locale>
#include "../../Core/File/EncodingFacade.h"

class EncodingSwitcher : public ICommand {
public:
    explicit EncodingSwitcher(FileReader* fileReader, FileWriter* fileWriter, EncodingFacade* encodingFacade);
    std::string getId() override;
    void execute(ArgumentFetcher* argumentFetcher) override;
    bool verify(ArgumentFetcher *argumentFetcher) override;
    std::string getHelp() override;

private:
    FileReader* fileReader;
    FileWriter* fileWriter;
    EncodingFacade* encodingFacade;
};


#endif //LABSOS_ENCODINGSWITCHER_H
