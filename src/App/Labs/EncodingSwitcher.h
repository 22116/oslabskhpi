//
// Created by victor on 1/9/19.
//

#ifndef LABSOS_ENCODINGSWITCHER_H
#define LABSOS_ENCODINGSWITCHER_H


#include "ILab.h"
#include "../../Core/File/FileReader.h"
#include "../../Core/File/FileWriter.h"
#include <locale>

class EncodingSwitcher : public ILab {
    int getId() override;
    void execute(char* argv[]) override;


public:
    explicit EncodingSwitcher(FileReader* fileReader, FileWriter* fileWriter);

private:
    FileReader* fileReader;
    FileWriter* fileWriter;
};


#endif //LABSOS_ENCODINGSWITCHER_H
