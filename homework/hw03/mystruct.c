/** mystruct.c
 * @author Daniel
 * Functions for struct HW03
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "mystruct.h"
#include "mystring.h"


/** Makes an employee struct
 @param name the name of employee.
 @param birth_year the birth year of employee.
 @param start_year the start year of employee's job.
 @return returns the created employee.
*/
Employee* make_employee(char* name, int birth_year, int start_year) {
  Employee *e = malloc(sizeof(Employee));
  mystrcpy(e->name, name);
  e->birth_year = birth_year;
  e->start_year = start_year;

  return e;
}

/** prints the employee and its atributes
 @param e the employee in question.
*/

void print_employee(Employee e){
  printf("Name: %s\n", &e.name[0]);
  printf("Birth Year: %d\n", e.birth_year);
  printf("Start Year: %d\n", e.start_year);
}

/** makes a random char A-Z, a-z, 0-9
  @return returns said char.
*/

char random_char() {
  int r = rand() % 62;
  if (r < 26) return 'A' + r;
  else if (r < 52) return 'a' + (r - 26);
  else return '0' + (r - 52);
}

/** makes a random int based on MAX_YEAR
  @return returns said int.
*/

int random_int() {
  int r = rand() % MAX_YEAR;
  return r;
}

/** Creates a random string based on random_char
  @param max takes in max character count
  @return returns the string.
*/

char *create_random_string(int max){
  srand(time(NULL));
  char* c = malloc(max + 1);
  for (int i = 0; i < max; i++) {
    c[i] = random_char();
  }
  c[max] = '\0';
  return c;
}

/** Initializes an employee and then gives it random values
  @return returns said employee.
*/

Employee* create_random_employee(){
  srand(time(NULL));
  Employee* e = (Employee*)malloc(sizeof(Employee));
  char *c = create_random_string(NAME_SIZE);
  e = make_employee(c, random_int(), random_int());
  free(c);
  return e;
}

/** Makes an array of Employees from create_random_employee
  @param count how big to make the array.
  @return returns said array of employees.
*/

Employee **create_random_employee_array(int count){
  Employee** employee_array = (Employee**)malloc(count * sizeof(Employee*));
  for (int i = 0; i < count; i++) {
    employee_array[i] = (Employee*)malloc(sizeof(Employee));
  }
  for(int i = 0; i < count; i++){
    employee_array[i] = create_random_employee();
  }
  return employee_array;
}

/** prints the whole array of employees.
  @param employee_array takes in the array;
*/

void print_employee_array(Employee** employee_array){
  for(int i = 0; i < sizeof(employee_array); i++){
    print_employee(*employee_array[i]);
    printf("\n");
  }
  return;
}

/** Frees the whole array of employees from memory
  @param employee_array the employee array to be freed
*/

void free_employee_array(Employee** employee_array){
  for(int i = 0; i < sizeof(employee_array); i++){
    free(employee_array[i]);
  }
  free(employee_array);
}
