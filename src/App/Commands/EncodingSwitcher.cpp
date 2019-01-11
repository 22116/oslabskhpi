//
// Created by victor on 1/9/19.
//

#include <iostream>
#include "EncodingSwitcher.h"
#include <string>
#include <vector>

using namespace std;

EncodingSwitcher::EncodingSwitcher(FileReader* fileReader, FileWriter* fileWriter) {
    this->fileReader = fileReader;
    this->fileWriter = fileWriter;
}

std::string EncodingSwitcher::getId() {
    return "switch-encoding";
}

void EncodingSwitcher::execute(ArgumentFetcher* argumentFetcher) {

}

bool EncodingSwitcher::verify(ArgumentFetcher *argumentFetcher) {
    return false;
}

void EncodingSwitcher::showHelp() {

}
