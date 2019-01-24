//
// Created by victor on 1/9/19.
//

#ifndef LABSOS_FILEREADER_H
#define LABSOS_FILEREADER_H

#include <string>
#include <functional>

class FileReader {
public:
    /** @brief: read full file to the buffer */
    std::string read(std::string path);
    /** @brief: read file by block with left disposition */
    void read(std::string path, int buffSize, int disposition, const std::function<bool(std::string)> &callback);
    /** @brief: read file by line */
    void read(std::string path, const std::function<bool(std::string)> &callback);
};


#endif //LABSOS_FILEREADER_H
