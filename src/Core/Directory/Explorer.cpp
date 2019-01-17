#include <utility>

//
// Created by victor on 1/15/19.
//

#include "Explorer.h"

#include <iostream>
#include <functional>
#include <string>

Explorer::Explorer(IStrategy *strategy) {
    this->strategy = strategy;
}

std::vector<std::string> Explorer::getFileList(std::string path) {
    std::vector<std::string> list;

    this->strategy->explore(std::move(path), [&list](std::string file) -> void {
        list.emplace_back(file);
    });

    return list;
}
