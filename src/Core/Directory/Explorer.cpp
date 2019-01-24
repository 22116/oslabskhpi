//
// Created by victor on 1/15/19.
//

#include "Explorer.h"

#include <utility>
#include <iostream>
#include <functional>
#include <string>

Explorer::Explorer(IStrategy *strategy) {
    this->strategy = strategy;
}

void Explorer::explore(std::string path, std::function<void(std::string)> callback) {
    this->strategy->explore(std::move(path), std::move(callback));
}

std::vector<std::string> Explorer::getFileList(std::string path) {
    std::vector<std::string> list;

    this->explore(std::move(path), [&list](std::string file) -> void {
        list.emplace_back(file);
    });

    return list;
}