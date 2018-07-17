/**************************************************
Unit Test Program:  This program has the logic for
                    executing all the operations
                    of the ADT List with the Fixed
                    Size Array implementation.
                    If any assert fails the Program
                    will crash and indicate which
                    assert failed.
Author:             Carlos R. Arias
Date:               2018 - 07 - 16
**************************************************/


#include "object.h"
#include "integer.h"
#include "character.h"
#include "fsarraylist.h"

#include <iostream>
#include <string>
#include <sstream>
#include <cassert>


using std::cout;
using std::cerr;
using std::endl;
using std::string;
using std::stringstream;


int main(int argc, char* argv[]){
    FSArrayList list(5);
    Integer* toInsert = nullptr;
    Integer toCompare;

    assert(list.IsEmpty() == true);
    assert(list.Get(0) == nullptr);
    assert(list.Get(1) == nullptr);
    toInsert = new Integer(4);
    assert(list.Insert(toInsert, 0) == true);
    assert(list.Size() == 1);
    assert(list.IsEmpty() == false);
    toCompare.SetValue(4);
    assert(list.Get(0)->Equals(&toCompare));
    toInsert = new Integer(2);
    assert(list.Insert(toInsert, 2) == false);
    assert(list.Insert(toInsert, 1) == true);
    assert(list.Get(0)->Equals(&toCompare) == true);
    toCompare.SetValue(2);
    assert(list.Get(1)->Equals(&toCompare) == true);
    assert(list.Insert(new Integer(7), 0) == true);
    assert(list.Size() == 3);
    toCompare.SetValue(7);
    assert(list.Get(0)->Equals(&toCompare) == true);
    toCompare.SetValue(4);
    assert(list.Get(1)->Equals(&toCompare) == true);
    toCompare.SetValue(2);
    assert(list.Get(2)->Equals(&toCompare) == true);
    assert(list.Insert(new Integer(3), list.Size()) == true);
    assert(list.Insert(new Integer(9), list.Size()) == true);
    assert(list.Insert(toInsert, list.Size()) == false);
    toCompare.SetValue(0);
    for (size_t i = 0; i < list.Size(); i++) {
        assert(list.Get(i)->Equals(&toCompare) == false);
    }
    assert(list.IsEmpty() == false);
    assert(list.Remove(5) == false);

    assert(list.Remove(0) == true);
    assert(list.Size() == 4);
    toCompare.SetValue(4);
    assert(list.Get(0)->Equals(&toCompare) == true);
    toCompare.SetValue(2);
    assert(list.Get(1)->Equals(&toCompare) == true);
    toCompare.SetValue(3);
    assert(list.Get(2)->Equals(&toCompare) == true);
    toCompare.SetValue(9);
    assert(list.Get(3)->Equals(&toCompare) == true);

    assert(list.Remove(2) == true);
    assert(list.Size() == 3);
    toCompare.SetValue(4);
    assert(list.Get(0)->Equals(&toCompare) == true);
    toCompare.SetValue(2);
    assert(list.Get(1)->Equals(&toCompare) == true);
    toCompare.SetValue(9);
    assert(list.Get(2)->Equals(&toCompare) == true);

    assert(list.Remove(list.Size() - 1) == true);
    assert(list.Size() == 2);
    toCompare.SetValue(4);
    assert(list.Get(0)->Equals(&toCompare) == true);
    toCompare.SetValue(2);
    assert(list.Get(1)->Equals(&toCompare) == true);

    toCompare.SetValue(4);
    assert(list.IndexOf(&toCompare) == 0);
    toCompare.SetValue(2);
    assert(list.IndexOf(&toCompare) == 1);
    toCompare.SetValue(5);
    assert(list.IndexOf(&toCompare) == -1);

    cerr << "All Unit Tests Passed. Congratulations" << endl;


}
