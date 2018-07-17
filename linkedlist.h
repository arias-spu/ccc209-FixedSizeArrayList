#pragma once

class LinkedList : public Object{
    struct Node{
        Node* next;
        Node* prev;
        Object* data;
    };
    Node* head;
    size_t size;
public:
    LinkedList();
    virtual ~LinkedList();
    virtual string ToString()const;
    virtual bool Equals(const Object*)const;


}
