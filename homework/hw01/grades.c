#define MAX_GRADES (5)

#include <stdio.h>
#include <stdlib.h>


float calcGrades(int, int[]);

int main (int argc, const char* argv[]) {

  int all_grades[MAX_GRADES] = {}; // Define and allocate the array

  if (argc < 2) { // Check that there was an entry
    printf("Must enter a number on the command line!\n");
    return 1; // Indicate failure
  }

  if (argc > MAX_GRADES + 2){
    printf("Can only enter %d number(s)!\n", MAX_GRADES + 1);
    return 1; // Indicate failure
  }

  for(int i = 1; i < argc; i++){
    all_grades[i-1] = atoi(argv[i]);
  }

  printf("AVG GRADE: %f\n", calcGrades(argc - 1, all_grades));
  return 0; // Indicate success!
}

float calcGrades(int num, int grades[]){
  int totalGrade = 0;
  for(int i = 0; i < num; i++){
    totalGrade += grades[i];
  }
  return totalGrade / num;
}
