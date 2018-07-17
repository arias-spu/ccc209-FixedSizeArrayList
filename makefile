array:	fsarraylist main object list
	g++ fsarraylist.o main.o object.o list.o -o array

fsarraylist: fsarraylist.cpp fsarraylist.h list.h list.cpp object.h object.cpp
	g++ -c fsarraylist.cpp

list:	list.h list.cpp object.h object.cpp
	g++ -c list.cpp

object:	object.h object.cpp
	g++ -c object.cpp

main:	main.cpp fsarraylist.h fsarraylist.cpp list.h list.cpp object.h object.cpp
	g++ -c main.cpp

unittest:	fsarraylist test object list
	g++ fsarraylist.o test.o object.o list.o -o unittest

test:	test.cpp fsarraylist.h fsarraylist.cpp list.h list.cpp object.h object.cpp
	g++ -c unittest.cpp

clean:
	rm *.o unittest array
