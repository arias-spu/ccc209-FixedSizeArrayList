#include "integer.h"
#include "fsarraylist.h"

#include <iostream>
#include <string>
#include <sstream>

using std::cout;
using std::cerr;
using std::endl;
using std::string;
using std::stringstream;




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
