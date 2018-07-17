#pragma once

#include "object.h"

#include <string>

using std::string;

class Character: public Object{
    char _value;
public:
    Character(char = 0);
    virtual string ToString()const;
    virtual bool Equals(const Object*)const;
    char GetValue()const;
    void SetValue(char);
};
