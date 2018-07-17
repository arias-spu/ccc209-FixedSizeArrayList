#include "object.h"
#include "list.h"
#include "fsarraylist.h"

#include <string>
#include <typeinfo>

using std::string;


FSArrayList::FSArrayList(size_t capacity) : _capacity(capacity){
    _data = new Object*[_capacity];
    for (size_t i = 0; i < _capacity; i++) {
        _data[i] = nullptr;
    }
}
FSArrayList::FSArrayList(const FSArrayList& rhs){

}
FSArrayList FSArrayList::operator=(const FSArrayList& rhs){
    return FSArrayList(0);
}
FSArrayList::~FSArrayList(){
    for (size_t i = 0; i < _size; i++) {
        delete _data[i];
    }
    delete[] _data;
}

bool FSArrayList::Equals(const Object* rhs)const{
    if (rhs == nullptr)
        return false;
    if (typeid(*rhs) != typeid(*this))
        return false;
    if (rhs == this)
        return true;
    const FSArrayList* other = dynamic_cast<const FSArrayList*>(rhs);
    for (size_t i = 0; i < _size; i++) {
        if (!Get(i)->Equals(other->Get(i)))
            return false;
    }
    return true;
}

bool FSArrayList::Insert(Object* element, size_t position){
    // The list is Full
    if (_size == _capacity)
        return false;
    // Invalid position
    if (position > _size)
        return false;
    // Push elements if necessary
    for (size_t i = _size; i > position ; i--) {
        _data[i] = _data[i - 1];
    }
    // Insert the element
    _data[position] = element;
    _size++;
    return true;
}
bool FSArrayList::Remove(size_t position){
    // Invalid position
    if (position >= _size)
        return false;
    // Separating the element to remove
    Object* temporal = _data[position];
    _data[position] = nullptr;
    // Pushing the elements if necessary
    for (size_t i = position; i < _size - 1; i++) {
        _data[i] = _data[i + 1];
    }
    // Set to null the "last" element, just copied
    // to the previous element
    _data[_size - 1] = nullptr;
    _size--;
    // release the memory
    delete temporal;
    return true;
}
Object* FSArrayList::Get(size_t position)const{
    if (position >= _size)
        return nullptr;
    return _data[position];
}
int FSArrayList::IndexOf(const Object* rhs)const{
    for (size_t i = 0; i < _size; i++) {
        if (Get(i)->Equals(rhs))
            return i;
    }
    return -1;
}
