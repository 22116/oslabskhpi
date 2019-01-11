#include <iostream>
#include "src/App/LabFactory.h"
#include "src/App/Exception/InvalidLabIdentifierException.h"

int main(int argc, char *argv[]) {
    int labId = argv[1][0] - '0';
    auto labFactory = new LabFactory();

    try {
        labFactory->create(labId)->execute(argv);
    } catch (InvalidLabIdentifierException err) {
        std::cout << err.what();
    }

    std::cout << std::endl;

    return 0;
}