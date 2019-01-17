//
// Created by victor on 1/15/19.
//

#include "UnixStrategy.h"
#include "../Exception/IOException.h"
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

void UnixStrategy::explore(std::string path, std::function<void(std::string)> callback) {
    DIR* dir;
    struct dirent* dp;

    if ((dir = opendir(path.c_str())) == nullptr) {
        throw new IOException("Can't read a directory '" +  path);
    }

    while ((dp = readdir(dir)) != nullptr) {
        struct stat buf{};
        int x;
        std::string child = path + "/" + dp->d_name;

        x = lstat(child.c_str(), &buf);

        if (S_ISLNK(buf.st_mode) || strcmp(dp->d_name, ".") == 0 || strcmp(dp->d_name, "..") == 0) {
            continue;
        } else if (S_ISDIR(buf.st_mode)) {
            try {
                this->explore(child, callback);
            } catch (IOException &exception) {
                continue;
            }
        } else {
            callback(child);
        }
    }

    closedir(dir);
}
