all: at2 at3

at3: at3.o print_double_array.o array_sort.o
	gcc --std=c11 at3.o print_double_array.o array_sort.o -o at3

at3.o: at3.c print_double_array.h array_sort.h
	gcc --std=c11 -c at3.c

at2: at2.o print_double_array.o array_sort.o
	gcc --std=c11 at2.o print_double_array.o array_sort.o -o at2

at2.o: at2.c print_double_array.h array_sort.h
	gcc --std=c11 -c at2.c

print_arrays.o: print_double_array.c print_double_array.h
	gcc --std=c11 -c print_double_array.c

array_sort.o: array_sort.c array_sort.h
	gcc --std=c11 -c array_sort.c

clean:
	rm -f *.o
	rm -f at2
	rm -f at3
	rm -f -r html

docs:
	doxygen
	cp -p ./html/* ~/public_html/cs2303_hw02/
