#pragma once

#include "object.h"

#include <string>

using std::string;

class Integer: public Object{
    int _value;
public:
    Integer(int = 0);
    virtual string ToString()const;
    virtual bool Equals(const Object*)const;
    int GetValue()const;
};
