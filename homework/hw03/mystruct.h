/** mystruct.h
 * @author Daniel Baranov
 * Function Headers for struct HW03
*/
#ifndef MYSTRUCT_H		// Remember guard
#define MYSTRUCT_H

#define NAME_SIZE 20
#define MAX_YEAR 3000

typedef struct Employee{
  char name[NAME_SIZE];
  int birth_year;
  int start_year;
} Employee;

Employee* make_employee(char* name, int birth_year, int start_year);

void print_employee(Employee e);

char random_char();

int random_int();

char *create_random_string(int max);

Employee *create_random_employee();

Employee **create_random_employee_array(int count);

void print_employee_array(Employee** employee_array);

void free_employee_array(Employee** employee_array);

#endif
