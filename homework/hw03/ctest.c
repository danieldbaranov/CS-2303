// string.h covers the C-style string functions.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mystring.h"

/** ctest.c
 * Program to demonstrate character arrays and dynamically-allocated memory.
 * @author Mike Ciaraldi, Blake Nelson
 */

const int MAX_CHARS = 20;       // Maximum number of characters in array

int main()
{
  char a1[MAX_CHARS + 1]; 	// Character array--initially empty
  char a2[] = "Hello"; 		// Character array--unsized but initialized
  char a3[MAX_CHARS + 1]; 	// Character array--we will underfill it
  const char *p1 = "Hello";     // Pointer to constant string
  char *p2;           		// Will be a pointer to dynamically-allocated string
  int copy_limit;     		// Maximum characters to copy.


  /* Print the pointers.
     Note: this example prints
     the values of the pointers themselves, not the targets.
  */
  printf("Arrays:   a1: %p, a2: %p, a3: %p\n", a1, a2, a3);
  printf("Pointers: p1: %p, p2: %p\n", p1, p2);

  mystrcpy(a1, "Hi"); 		// Initialize character array a1 with some text
  mystrcpy(a3, "Hello, also");    // Initialize uinderfilled character array


  // Print the values of the C-style strings
  printf("\n");
  printf("C-string values:\n");
  printf("a1: %s\n", a1);
  printf("a2: %s\n", a2);
  printf("a3: %s\n", a3);

  /* Concatenate two character arrays, then print.
  *  Terminator character in the last element of the array as well as after "Hi"
  */
  a1[MAX_CHARS] = '\0';
  mystrcat(a1, a2);
  printf("\n");
  printf("After concatenating a2 to the end of a1\n");
  printf("a1: %s\n", a1);

  // Concatenate two character arrays safely, then print.
  copy_limit = MAX_CHARS - strlen(a1); 	// How much space is left?

  printf("\n");
  printf("Concatenating a2 to a1, with copy_limit = %d\n", copy_limit);
  if (copy_limit > 0) {
	mystrncat(a1, a2, copy_limit);
  }
  printf("a1: %s\n", a1);

  // Concatenate two character arrays safely, then print.
  copy_limit = MAX_CHARS - strlen(a1); 	// How much space is left?
  printf("\n");
  printf("Concatenating a3 to a1, with copy_limit = %d\n", copy_limit);
  if (copy_limit > 0) {
	mystrncat(a1, a3, copy_limit);
  }
  printf("a1: %s\n", a1);

  // Duplicate a string, using my function, then print
  printf("\n");
  printf("Before dup, array a2 = %p, contents = %s\n", a2, a2);
  p2 = mystrdup(a2);
  printf("After dup, pointer p2 =  %p, contents = %s\n", p2, p2);

  // Using strncpy
  char dest1[12];
  char src1[] = "Hello World";
  mystrncpy(dest1, src1, sizeof(dest1) - 1);
  dest1[sizeof(dest1) - 1] = '\0';
  printf("strncpy: %s\n", dest1);

  // Edge case: Truncation
  char dest2[5];
  char src2[] = "Hello World";
  mystrncpy(dest2, src2, sizeof(dest2) - 1);
  dest2[sizeof(dest2) - 1] = '\0';
  printf("strncpy with truncation: %s\n", dest2);

  // Using strndup
  char *src3 = "Hello World";
  char *dup = mystrndup(src3, 5);
  printf("strndup: %s\n", dup);

  char a[20];               // Initially-empty character array
  mystrcpy(a, "ABCDEFGHIJ");  // Fill the first 10 elements,
                            // plus the terminator in a[10].
  printf("String a = %s\n", a);
  mystrncpy(a, "TUVWXYZ", 5);// Only copy first 5 characters.
  printf("String a = %s\n", a);



  // Free the memory allocated on our behalf by mystrdup()
  free(p2);
  free(dup);

  return 0;
}
