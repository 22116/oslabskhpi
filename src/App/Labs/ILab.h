//
// Created by victor on 1/9/19.
//

#pragma once

class ILab {
public:
    virtual int getId() = 0;
    virtual void execute(char* argv[]) = 0;
};