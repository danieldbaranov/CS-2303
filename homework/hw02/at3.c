/** file at3.c
 * @author
 *
 * Program to demonstrate fixed-size arrays of doubles in C.
 */

#include "print_double_array.h"
#include "array_sort.h"
#include <stdio.h>
#include <stdlib.h>

/** Main program for demonstrating arrays. It fills them and prints them.
 * @return 0, Indicating success.
 */
#
int main(int argc, char argv[]) {
  int size = atoi(argv[2]);
  int maximum = atoi(argv[1]);
  int a[size + 1];

/**
  if(sizeof(argv) < 3){
    printf("You are missing the required parameters!\n");
    return 1;
  }
**/

  fill_random_array(a, size, maximum);

  // Fills the Array with the doubles from input
  printf("Before Sorting:\n");
  print_int_array(a, size);

  // Now print it out
  printf("\nAfter Sorting:\n");
  sort_int_array(size, a);
  print_int_array(a, size);

  return 0; // Success!
}
