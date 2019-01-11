//
// Created by victor on 1/11/19.
//

#ifndef LABSOS_APP_H
#define LABSOS_APP_H


#include "../Core/Cli/ArgumentFetcher.h"

class App {
private:
    ArgumentFetcher* argumentFetcher;

public:
    explicit App(ArgumentFetcher* argumentFetcher);
    void run();
};


#endif //LABSOS_APP_H
