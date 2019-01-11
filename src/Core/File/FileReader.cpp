//
// Created by victor on 1/9/19.
//

#include "FileReader.h"
#include <iostream>


char *FileReader::getFileContent(char *path) {
    char * buffer = nullptr;
    long length;
    FILE * f = fopen(path, "rb");

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

    return buffer;
}
