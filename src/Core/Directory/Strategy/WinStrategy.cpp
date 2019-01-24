//
// Created by victor on 1/17/19.
//

#include "WinStrategy.h"
#include "../Exception/IOException.h"
#include <windows.h>
#include <tchar.h>
#include <stdio.h>
#include <string>

void WinStrategy::explore(std::string path, std::function<void(std::string)> callback) {
    std::string strSpec = path + "\\*.*";
    WIN32_FIND_DATA FindFileData;
    HANDLE handle = FindFirstFile(strSpec.c_str(), &FindFileData);

    if (handle == INVALID_HANDLE_VALUE) {
        throw new IOException("Can't read a directory '" +  path);
    }

    do {
        strSpec = FindFileData.cFileName;
        if (strSpec != "." && strSpec != "..")
        {
            if (!(FindFileData.dwFileAttributes & FILE_ATTRIBUTE_HIDDEN))
            {
                strSpec = path + "\\" + strSpec;
                if (FindFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
                    this->explore(strSpec, callback);
                }
                else {
                    if (FindFileData.nFileSizeLow != 0 || FindFileData.nFileSizeHigh != 0) {
                        callback(strSpec);
                    }
                }
            }
        }
    } while (FindNextFile(handle, &FindFileData));

    FindClose(handle);
}
