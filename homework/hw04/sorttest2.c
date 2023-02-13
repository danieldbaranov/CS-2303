#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

#define MAX_NUM 50

/* Program which reads a number of random integers to be processed,
 * outputs them, sorts them in descending order, and outputs the sorted list.
 *
 * Usage:
 *         ./sorttest some_number another_number ...
 * Example:
 *         ./sorttest 2014 15 7000
 *
 */

/** Main program
 * @param argc Number of words on the command line
 * @param argv[] Array of character strings, the words from the command line.
 * @return 0 if success, 1 if error (wrong number of arguments)
 */

int main (int argc, const char* argv[]) {

  int *nums; // space to store numbers entered from the command line.
  time_t t;
  int i; // array index
  int num; // How many random numbers will be stored in the array

  if (argc < 3) {
    printf("Must enter a number on the command line and sort method! Exiting.\n");
    return 1; // Indicate failure
  }

  num = atoi(argv[1]);

  // Allocate an array big enough to hold the numbers
  nums = (int*) calloc(num, sizeof(int));
  if (nums == NULL) {
    fprintf(stderr, "Unable to allocate enougn memory to hold the numbers.\n");
  }

  srand((unsigned) time(&t)); // initializes random number generator

  /* Read all the numbers from the command line and put them into the array */
  for (i = 0; i < num; i++) {
    nums[i] = rand() % MAX_NUM; // store into the array
  }

  // Now print, sort, and print the array, and time how long the sorting took.
  timesort(nums, num, argv[2]);

  return 0; // Indicate success!
}
