//
// Created by victor on 1/18/19.
//

#include "RegExp.h"
#include "Elem/CharEl.h"
#include "Elem/RandomCharEl.h"
#include "Elem/SwitcherEl.h"
#include "Elem/BoolEl.h"
#include "Elem/RangeEl.h"

RegExp::RegExp(std::string &pattern)  {
    for (int i = 0; i < pattern.length(); i++) {
        if (pattern[i] == '.') {
            this->elems.emplace_back(new RandomCharEl(std::string(1, pattern[i])));
            continue;
        }

        if (pattern[i] == '?') {
            this->elems.emplace_back(new BoolEl(std::string(1, pattern[i])));
            continue;
        }

        if (pattern[i] == '[') {
            char next;
            std::string arr;

            while ((next = pattern[++i]) != ']') {
                arr += std::string(1, pattern[i]);
            }

            ++i;

            this->elems.emplace_back(new SwitcherEl(arr));
        }

        if (pattern[i] == '*') {
            IRegExpEl* nCh = new RangeEl(elems.back());
            this->elems.pop_back();
            this->elems.emplace_back(nCh);
        }

        if (pattern[i] == '\\' && i != pattern.length()) {
            this->elems.emplace_back(new CharEl(std::string(1, pattern[i++ + 1])));
            continue;
        } else {
            this->elems.emplace_back(new CharEl(std::string(1, pattern[i])));
            continue;
        }
    }
}

std::pair<int, int> RegExp::match(std::string &content) {
    for (int i = 0; i < content.length(); i++) {
        bool found = true;
        int len = 0;

        for (int j = 0; j < this->elems.size(); j++) {
            len++;
            switch (this->elems[j]->type()) {
                case REXP_CHAR: if (this->elems[j]->value()[0] != content[i + j]) found = false;
                    continue;
                case REXP_BOOL:
                    continue;
                case REXP_SWITCHER: {
                    auto switchers = this->elems[j]->value();
                    bool exists = false;

                    for (int z = 0; z < switchers.length(); z++) {
                        if (switchers[z] == content[i + j]) {
                            exists = true;
                        }
                    }

                    if (!exists) {
                        found = false;
                    }

                    break;
                }
                case REXP_RCHAR: {
                    if (i + j > content.length())
                        found = false;

                    break;
                }
            }
        }

        if (found) {
            return std::pair<int,int>(i, len);
        }
    }

}
