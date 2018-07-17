array:	fsarraylist.o main.o object.o list.o integer.o
	g++ fsarraylist.o main.o object.o list.o integer.o -o array

fsarraylist.o: fsarraylist.cpp fsarraylist.h
	g++ -c fsarraylist.cpp

list.o:	list.h list.cpp
	g++ -c list.cpp

object.o:	object.h object.cpp
	g++ -c object.cpp

main.o:	main.cpp
	g++ -c main.cpp

unittest:	fsarraylist.o object.o list.o integer.o character.o test.o
	g++ fsarraylist.o unittest.o object.o list.o integer.o character.o -o unittest

integer.o:	integer.h integer.cpp
	g++ -c integer.cpp

character.o:	character.h character.cpp
		g++ -c character.cpp

test.o:	unittest.cpp
	g++ -c unittest.cpp

clean:
	rm *.o unittest array
