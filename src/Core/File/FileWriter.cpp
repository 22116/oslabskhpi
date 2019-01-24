//
// Created by victor on 1/9/19.
//

#include "FileWriter.h"
#include <iostream>
#include <fstream>

using namespace std;

void FileWriter::putContent(char *path, char *content) {
    ofstream stream (path);
    stream.write("", 0);
    stream << content;
    stream.close();
}

void FileWriter::append(char *path, char *content) {
    ofstream stream(path, stream.app | stream.out);
    stream << content;
    stream.close();
}
