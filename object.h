#pragma once

#include <string>
using std::string;

class Object{
public:
    Object();
    virtual string ToString()const;
    virtual bool Equals(const Object*)const;
    virtual ~Object();
};
