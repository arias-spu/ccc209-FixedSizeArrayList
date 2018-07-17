#pragma once

#include "object.h"
#include "list.h"

#include <string>

using std::string;


class FSArrayList : public List{
    Object** _data;
    size_t _capacity;
    FSArrayList(const FSArrayList&);
    FSArrayList operator=(const FSArrayList&);

public:
    FSArrayList(size_t capacity);
    virtual ~FSArrayList();


    virtual bool Equals(const Object*)const;

    virtual bool Insert(Object*, size_t);
    virtual bool Remove(size_t);
    virtual Object* Get(size_t)const;
    virtual int IndexOf(const Object*)const;
};
