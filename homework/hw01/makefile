all: num grades

num: num.o
	gcc num.o -o num

num.o: num.c
	gcc -c num.c

grades: grades.o
	gcc grades.o -o grades

grades.o: grades.c
	gcc -c grades.c

clean:
	rm -f num.o num grades.o grades
