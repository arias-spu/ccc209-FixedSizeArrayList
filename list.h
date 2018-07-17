#pragma once

#include "object.h"

class List: public Object{
protected:
    size_t size;
public:
    List();
    virtual ~List();
    virtual string ToString()const;

    virtual bool Insert(Object*, size_t) = 0;
    virtual bool Remove(size_t) = 0;
    virtual Object* Get(size_t)const = 0;
    virtual int IndexOf(Object*)const = 0;
    size_t Size()const;
    bool IsEmpty()const;
};
