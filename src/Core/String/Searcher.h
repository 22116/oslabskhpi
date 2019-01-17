//
// Created by victor on 1/15/19.
//

#ifndef LABSOS_SEARCHER_H
#define LABSOS_SEARCHER_H

#include <vector>
#include <string>


class Searcher {
public:
    int find(std::string source, std::string pattern);

private:
    std::vector<int> buildSuffTable(std::string source);
};


#endif //LABSOS_SEARCHER_H
