//
// Created by victor on 1/9/19.
//

#ifndef LABSOS_LABFACTORY_H
#define LABSOS_LABFACTORY_H

#include "Labs/ILab.h"
#include <vector>

class LabFactory {
public:
    ILab* create(int id);

private:
    std::vector<ILab*> getLabs();
};


#endif //LABSOS_LABFACTORY_H
