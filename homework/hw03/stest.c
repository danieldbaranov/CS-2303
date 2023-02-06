#include <stdio.h>
#include <stdlib.h>
#include "mystruct.h"

int main(){
  struct Employee e1;
  e1 = *make_employee("Daniel B", 2004, 2022);
  print_employee(e1);

  printf("\n");

  Employee** e2 = create_random_employee_array(10);
  print_employee_array(e2);

  free_employee_array(e2);
  return 0;
}
