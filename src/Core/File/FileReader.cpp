//
// Created by victor on 1/9/19.
//

#include "FileReader.h"
#include <iostream>
#include <functional>
#include <cstdio>
#include <string.h>

std::string FileReader::read(std::string path) {
    char * buffer = nullptr;
    long length;
    FILE * f = fopen(path.c_str(), "r");

    if (f)
    {
        fseek (f, 0, SEEK_END);
        length = ftell(f);
        fseek (f, 0, SEEK_SET);
        buffer = (char*)malloc(length);
        if (buffer)
        {
            fread (buffer, 1, length, f);
        }
        fclose(f);
    }

    return std::string(buffer);
}

void FileReader::read(std::string path, const std::function<bool(std::string)> &callback) {
    FILE* f = fopen(path.c_str(), "r");;
    char* line = nullptr;

    if (f) {
        size_t len = 0;
        ssize_t read;

        while ((read = getline(&line, &len, f)) != -1) {
            if (callback(line)) {
                break;
            }
        }

        fclose(f);
        free(line);
    }
}

void FileReader::read(std::string path, int buffSize, int disposition, const std::function<bool(std::string)> &callback) {
    FILE * f = fopen(path.c_str(), "r");

    if (f)
    {
        std::string dBuffer;
        char* buffer = (char*)malloc(sizeof(char)*buffSize);

        while (fread(buffer, sizeof(char), static_cast<size_t>(buffSize), f) != 0) {
            if (callback(dBuffer + std::string(buffer))) {
                break;
            }

            dBuffer = std::string(buffer).substr(std::string(buffer).length() - disposition);
        }

        free(buffer);
        fclose(f);
    }
}
