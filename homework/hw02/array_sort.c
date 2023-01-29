/** file array_sort.c
 * @author
 *
 * function that sorts an array of numbers
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


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

int create_random_number(int rand_max){
  time_t t;

  srand((unsigned) time(&t));

  return (rand() % rand_max);
}

void fill_random_array(int array[], int size, int max){
  for (int i; i < size; i++){
    array[i] = create_random_number(max);
  }
  return;
}
