all: stacktest stacktest_dbg

stacktest: stacktest.o stack.o
	gcc -g stacktest.o stack.o -o stacktest

stacktest_dbg: stacktest_dbg.o stack.o
	gcc -g stacktest_dbg.o stack.o -o stacktest_dbg

stacktest.o: stacktest.c stack.h
	gcc -g -c stacktest.c

stacktest_dbg.o: stacktest.c stack.h
	gcc -g -c -DDEBUG_TEST stacktest.c -o stacktest_dbg.o

stack.o: stack.c stack.h
	gcc -g -c stack.c

docs:
	doxygen
	cp -p html/* ~/public_html/cs2303_hw05

clean:
	rm -f *.o stacktest stacktest_dbg
	rm -r -f html
