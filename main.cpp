#include <iostream>
#include "src/App/App.h"

int main(int argc, char *argv[]) {
    auto app = new App(new ArgumentFetcher(argc, argv));

    try {
        app->run();
    } catch(...) {
        std::cout << "Something went wrong, sorry." << std::endl;
    }

    return 0;
}
