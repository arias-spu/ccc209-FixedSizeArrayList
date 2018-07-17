#include "object.h"
#include "fsarraylist.h"

#include <iostream>
#include <string>
#include <sstream>
#include <typeinfo>

using std::cout;
using std::cerr;
using std::endl;
using std::string;
using std::stringstream;

class Integer: public Object{
    int _value;
public:
    Integer(int = 0);
    virtual string ToString()const;
    virtual bool Equals(const Object*)const;
    int GetValue()const;
};

Integer::Integer(int value): _value(value){

}
string Integer::ToString()const{
    stringstream retVal;
    retVal << _value;
    return retVal.str();
}
int Integer::GetValue()const{
    return _value;
}
bool Integer::Equals(const Object* rhs)const{
    if (rhs == nullptr)
        return false;
    if (typeid(*rhs) != typeid(*this))
        return false;
    if (rhs == this)
        return true;
    const Integer* other = dynamic_cast<const Integer*>(rhs);
    if (other->GetValue() == _value)
        return true;
    else
        return false;
}

int main(int argc, char* argv[]){
    FSArrayList list(5);
    cout << list.Insert(new Integer(4), 0) << endl;
    cout << list.ToString() << endl;
    cout << list.Insert(new Integer(8), 1) << endl;
    cout << list.ToString() << endl;
    cout << list.Insert(new Integer(-1), 3) << endl;
    cout << list.ToString() << endl;
    cout << list.Insert(new Integer(2), 2) << endl;
    cout << list.ToString() << endl;
    cout << list.Insert(new Integer(9), 1) << endl;
    cout << list.ToString() << endl;
    cout << list.Insert(new Integer(3), 0) << endl;
    cout << list.ToString() << endl;
    cout << list.Insert(new Integer(-2), 0) << endl;
    cout << list.ToString() << endl;


    return 0;
}
