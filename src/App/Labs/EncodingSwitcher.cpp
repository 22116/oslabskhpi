//
// Created by victor on 1/9/19.
//

#include <iostream>
#include "EncodingSwitcher.h"
#include <string>
#include <codecvt>
#include <locale>
#include <vector>
#include <locale>

using namespace std;

int EncodingSwitcher::getId() {
    return 1;
}

void EncodingSwitcher::execute(char* argv[]) {
    char* path = argv[2];
    char* content = this->fileReader->getFileContent(path);
    locale locale("en_US.UTF-8");

    // UTF-8 to wstring
    wstring_convert<codecvt_utf8<wchar_t>> wconv;
    wstring wstr = wconv.from_bytes(content);

    // wstring to string
    vector<char> buf(wstr.size());
    use_facet<ctype<wchar_t>>(locale).narrow(wstr.data(), wstr.data() + wstr.size(), '?', buf.data());

    this->fileWriter->putContent(path, (char*)string(buf.data(), buf.size()).c_str());
}

EncodingSwitcher::EncodingSwitcher(FileReader* fileReader, FileWriter* fileWriter) {
    this->fileReader = fileReader;
    this->fileWriter = fileWriter;
}
