//
// Created by victor on 1/9/19.
//

#include "LabFactory.h"
#include "Labs/EncodingSwitcher.h"
#include "Labs/SubstringSearcher.h"
#include "Exception/InvalidLabIdentifierException.h"

ILab* LabFactory::create(int id) {
    auto labs = this->getLabs();

    for (auto &lab : labs) {
        if (lab->getId() == id) {
            return lab;
        }
    }

    throw InvalidLabIdentifierException();
}

std::vector<ILab*> LabFactory::getLabs() {
    std::vector<ILab*> list;

    list.push_back(new EncodingSwitcher(new FileReader, new FileWriter));
    list.push_back(new SubstringSearcher());

    return list;
}
