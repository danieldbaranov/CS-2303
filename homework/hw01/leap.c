#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* Very simple program to demo reading a number from the command line.
 * Created by <your name, your account>
 *
 * Usage:
 *   ./num some_number
 * Example:
 *   ./num 2303
 *
 */

int main (int argc, const char* argv[]) {
  int n; // Integer read from the command line goes here.
  bool l;

  if (argc < 2) { // Check that there was an entry
    printf("Must enter a number on the command line!\n");
    return 1; // Indicate failure
  }

  n = atoi(argv[1]); // Get string from command line; convert to int

  if (n < 1752){
    printf("This program cannot test the year %d.\nIt only handles the year 1752 and after\n", n);
    return 1;
  }

  if(n % 4 == 0){
    if(n % 100 == 0){
      if(n % 400 == 0){
        l = true;
      } else {
        l = false;
      }
    } else {
      l = true;}

  } else {
    l = false;
  }


  if(l){
      printf("The year %d is a leap year!\n", n);
  } else {
    printf("The year %d is not a leap year and is a common year!\n", n);
  }
  return 0; // Indicate success!
}
