#define MAX_GRADES (5)

#include <stdio.h>
#include <stdlib.h>


float calcGrades(int, int[]);

int main (int argc, const char* argv[]) {

  int all_grades[MAX_GRADES]; // Define and allocate the array
  int i = 0;

  if (argc < 2) { // Check that there was an entry
    printf("Must enter a number on the command line!\n");
    return 1; // Indicate failure
  }

  while(*argv[i + 1] != '\0' || i >= MAX_GRADES){
    all_grades[i] = atoi(argv[i + 1]);
  }

  printf("AVG GRADE: %f\n", calcGrades(i + 1, all_grades));
  return 0; // Indicate success!
}

float calcGrades(int num, int grades[]){
  int totalGrade = 0;
  for(int i = 0; i < num; i++){
    totalGrade += grades[i];
  }
  return totalGrade / num;
}
