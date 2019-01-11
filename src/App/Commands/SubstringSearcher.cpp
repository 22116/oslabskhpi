//
// Created by victor on 1/9/19.
//

#include "SubstringSearcher.h"
#include <string.h>
#include <stdio.h>
#include <iostream>
#include <map>

using namespace std;

std::string SubstringSearcher::getId() {
    return "find-string";
}

void SubstringSearcher::execute(ArgumentFetcher* argumentFetcher) {
    
}

bool SubstringSearcher::verify(ArgumentFetcher *argumentFetcher) {
    return false;
}

void SubstringSearcher::showHelp() {

}
