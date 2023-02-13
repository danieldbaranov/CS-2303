Daniel Baranov
Homework 4

sorttest takes in an arbitrary amount of numbers in the command line and
prints them before and after sorting them using bubble sort. It then prints the
time before and after sorting and finds how long the algorithm took.

sorttest2 is similar to sorttest but it takes in how many random numbers to
generate for sorting, which allows for much better testing of algorithm times.
Then, you can choose whether you want sort_descending or alt_sort_descending algorithm.
alt_sort_descending uses pointers.


HOW TO USE:

make

./sorttest num1 num2 num3 ...

./sorttest2 num_of_random_nums {either sort_descending or alt_sort_descending}


SORT TIMES:
using numbers 100 1000 10000 and 100000 respectively for testing

sort_descending:
Time spent sorting: Seconds: 0, Microseconds: 28
Time spent sorting: Seconds: 0, Microseconds: 1500
Time spent sorting: Seconds: 0, Microseconds: 150991
Time spent sorting: Seconds: 25, Microseconds: 19053

alt_sort_descending:
Time spent sorting: Seconds: 0, Microseconds: 20
Time spent sorting: Seconds: 0, Microseconds: 862
Time spent sorting: Seconds: 0, Microseconds: 67430
Time spent sorting: Seconds: 6, Microseconds: 568525

The pointers are faster than incrementing
They are exponentially faster the larger the array becomes.
at 100, they are only a little bit faster, but inconsequential
at 1000 they are 2 times faster
at 10000 they are 2.5 times faster
at 100000 they are about 4 times faster and saves serious time.
