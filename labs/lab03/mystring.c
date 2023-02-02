/** mystring.c
 * @author Mike Ciaraldi, Blake Nelson
 * Custom versions of some of the C-style string functions
*/

#include <string.h>
#include <stdlib.h>
// Have to #include stdlib.h because it is needed to use malloc()
#include "mystring.h"

/** Duplicates a C-style string.
 @param src Pointer to string to be copied
 @return Pointer to freshly-allocated string containing a duplicate of src
         or null if no memory is available
*/
char* mystrdup(const char* src) {
  int length; 	// Length of the source string
  char* newstr; // Pointer to memory which will hold new string

  length = mystrlen(src) + 1;  		// Leave space for the terminator
  newstr = (char*) malloc(length); 	// Must cast!

  // If no memory was available, return null pointer immediately
  if (newstr == 0) {
	return (char *) 0;
  }

  // Otherwise, copy the string and return pointer to new string
  mystrcpy(newstr, src);
  return newstr;
}

/** Duplicates a C-style string.
 @param src Pointer to the string in question
 @return the length of the string, not including the end character '\0'
*/

int mystrlen(const char* src){
  int i = 0;
  while(src[i] != '\0'){
    i++;
  }
  return i;
}

char *mystrcpy(char *dest, const char *src){
  int i;
  if(sizeof(dest) < sizeof(src)){
    dest = (char*) realloc (dest, sizeof(src));
  }

  for(i = 0; src[i] != '\0'; i++){
    dest[i] = src[i];
  }
  dest[i] = '\0';
  return dest;
}
