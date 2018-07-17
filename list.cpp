#include "list.h"

#include <sstream>
#include <string>

using std::string;
using std::stringstream;

List::List(){
    size = 0;
}
List::~List(){

}
size_t List::Size()const{
    return size;
}
bool List::IsEmpty()const{
    return size == 0;
}
string List::ToStrig()const{
    stringstream retVal;
    retVal << "[";
    
}
