/** file print_double_array.c
 * @author
 *
 * Functions for printing an array of doubles.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "print_double_array.h"

/** Print an array of ints, one per line.
    @param a Array to print
    @param num_entries Number of entries in the array
*/

void print_int_array(int a[], int num_entries) {
  int i; // Loop counter

  for (i = 0; i <= num_entries; i++) {
    printf("%d\n", a[i]);
  }
}

/** Print an array of doubles, one per line.
    @param a Array to print
    @param num_entries Number of entries in the array
*/

void print_double_array(double a[], int num_entries) {
  int i; // Loop counter

  for (i = 0; i <= num_entries; i++) {
    printf("%f\n", a[i]);
  }
}

void scan_double_array(int argc, char *argv[], double a[], int size){
  for(int i = 1; i < size + 1; i++){
    a[i - 1] = atoi(argv[i]);
    }
}
