/** file array_sort.c
 * @author
 *
 * function that sorts an array of numbers
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/** Sorts an array of doubles in place.
    @param array_size the size of the array
    @param array the actual array to sort
*/

void sort_double_array(int array_size, double array[]) {
  int step, i;
  double tmp;

  for(step = 0; step < array_size - 1; step++){
    for (i = 0; i < array_size - 1 - step; i++){
      if(array[i] > array[i + 1]) {
        tmp = array[i];
        array[i] = array[i + 1];
        array[i + 1] = tmp;
      }
    }
  }
  return;
}

/** Sorts an array of ints in place.
    @param array_size the size of the array
    @param array the actual array to sort
*/

void sort_int_array(int array_size, int array[]) {
  int step, i;
  int tmp;

  for(step = 0; step < array_size - 1; step++){
    for (i = 0; i < array_size - 1 - step; i++){
      if(array[i] > array[i + 1]) {
        tmp = array[i];
        array[i] = array[i + 1];
        array[i + 1] = tmp;
      }
    }
  }
  return;
}

/** Creates a random number based on the time and the maximum value
    @param rand_max the maximum number that can be obtained
*/

int create_random_number(int rand_max){
  time_t t;

  srand((unsigned) time(&t));

  return (rand() % rand_max);
}


/** fills an array with random numbers
    @param array the array itself
    @param size the size of the array
    @param max the maximum possible number in the array
*/
void fill_random_array(int array[], int size, int max){
  for (int i = 0; i < size; i++){
    array[i] = create_random_number(max);
  }
  return;
}
