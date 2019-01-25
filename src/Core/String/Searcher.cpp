//
// Created by victor on 1/15/19.
//

#include <iostream>
#include <map>
#include <utility>
#include "Searcher.h"
#include "RegExp/RegExp.h"

std::vector<int> Searcher::buildSuffTable(std::string s) {
    std::vector<int> p(s.length());

    int k = 0;
    p[0] = 0;
    for (int i = 1; i < s.length(); ++i) {
        while (k > 0 && s[k] != s[i]) {
            k = p[k - 1];
        }
        if (s[k] == s[i]) {
            ++k;
        }
        p[i] = k;
    }
    return p;
}

int Searcher::find(std::string s, std::string t) {
    if (s.length() < t.length()) {
        return -1;
    }

    if (!t.length()) {
        return s.length();
    }

    typedef std::map<char, int> TStopTable;
    typedef std::map<int, int> TSufficsTable;
    TStopTable stop_table;
    TSufficsTable suffics_table;

    for (int i = 0; i < t.length(); ++i) {
        stop_table[t[i]] = i;
    }

    std::string rt(t.rbegin(), t.rend());
    std::vector<int> p = this->buildSuffTable(t), pr = this->buildSuffTable(rt);
    for (int i = 0; i < t.length() + 1; ++i) {
        suffics_table[i] = t.length() - p.back();
    }

    for (int i = 1; i < t.length(); ++i) {
        int j = pr[i];
        suffics_table[j] = std::min(suffics_table[j], i - pr[i] + 1);
    }

    for (int shift = 0; shift <= s.length() - t.length();) {
        int pos = t.length() - 1;

        while (t[pos] == s[pos + shift]) {
            if (pos == 0)
                return shift;
            --pos;
        }

        if (pos == t.length() - 1) {
            TStopTable::const_iterator stop_symbol = stop_table.find(s[pos + shift]);
            int stop_symbol_additional = pos - (stop_symbol != stop_table.end() ? stop_symbol->second : -1);
            shift += stop_symbol_additional;
        } else {
            shift += suffics_table[t.length() - pos - 1];
        }
    }

    return -1;
}

std::pair<int, int> Searcher::findRegexp(std::string source, std::string pattern) {
    return (new RegExp(pattern))->match(source);
}

std::string Searcher::findReplace(std::string &content, std::vector<std::pair<std::string, std::string>> matches) {
    std::string buff;

    for (int i = 0; i < content.length(); i++) {
        bool isReplaced = false;

        for (auto &match : matches) {
            bool found = true;

            if (content.length() - i < match.first.length()) {
                continue;
            }

            for (int j = 0; j < match.first.length(); j++) {
                if (match.first[j] != content[i + j]) {
                    found = false;
                    break;
                }
            }

            if (found) {
                buff += match.second;
                i += match.first.length() - 1;
                isReplaced = true;
                break;
            }
        }

        if (!isReplaced) {
            buff += std::string(1, content[i]);
        }
    }

    return buff;
}
