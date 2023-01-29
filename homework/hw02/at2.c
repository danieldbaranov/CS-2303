/** file at2.c
 * @author
 *
 * Program to demonstrate fixed-size arrays of doubles in C.
 */

#include "print_double_array.h"
#include "array_sort.h"
#include <stdio.h>

#define ARRAY_SIZE (10)

/** Main program for demonstrating arrays. It fills them and prints them.
 * @return 0, Indicating success.
 */

int main(int argc, char argv[]) {
  int i; // Loop counter
  int n;
  double a[ARRAY_SIZE + 1]; // Sample array for demonstration

  if( argc - 1 > ARRAY_SIZE){ // checks to make sure that the amount of arguments isn't going over limit
    printf("Your input is above the array limit of %d. will truncate to limit.\n", ARRAY_SIZE);
    n = ARRAY_SIZE;
  } else {
    n = argc - 1;
  }
    scan_double_array(argc, argv, a, n);

  // Fills the Array with the doubles from input
  printf("Before Sorting:\n");
  print_double_array(a, n-1);

  // Now print it out
  printf("\nAfter Sorting:\n");
  sort_double_array(n-1, a);
  print_double_array(a, n-1);

  return 0; // Success!
}
