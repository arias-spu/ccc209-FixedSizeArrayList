#include "object.h"

#include <string>
#include <sstream>

using std::string;
using std::stringstream;

Object::Object(){

}

string Object::ToString()const{
    stringstream ss;
    ss << this;
    return ss.str();
}
