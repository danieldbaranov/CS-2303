All: ctest stest

ctest: ctest.o mystring.o
	gcc ctest.o mystring.o -o ctest

ctest.o: ctest.c mystring.h
	gcc -c ctest.c

stest: stest.o mystruct.o mystring.o
	gcc stest.o mystruct.o mystring.o -o stest

stest.o: stest.c mystruct.h mystring.h
	gcc -c stest.c

mystruct.o: mystruct.c mystruct.h mystring.h
	gcc -c mystruct.c

mystring.o: mystring.c mystring.h
	gcc -c mystring.c

clean:
	rm -f mystring.o ctest.o ctest mystruct.o stest.o stest
	rm -r -f html

docs:
	doxygen
	cp -p ./html/* ~/public_html/cs2303_hw03/
