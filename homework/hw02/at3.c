/** file at3.c
 * @author
 *
 * Program to demonstrate fixed-size arrays of doubles in C.
 */

#include "print_double_array.h"
#include "array_sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/** Main program for demonstrating arrays. It fills them and prints them.
 * @return 0, Indicating success.
 */

int main(int argc, char argv[]) {


  //checks to see If the number of inputs is correct
  if(argc < 3){
    printf("You are missing the required parameters!\n");
    return 1;
  }

  int size = atoi(&argv[2]);
  printf("size: %d\n", size);
  int maximum = atoi(&argv[1]);
  int a[size + 1];






  fill_random_array(a, size, maximum);

  // prints the random array before sorting
  printf("Before Sorting:\n");
  print_int_array(a, size);

  // printing it after sorting
  printf("\nAfter Sorting:\n");
  sort_int_array(size, a);
  print_int_array(a, size);

  return 0; // Success!
}
