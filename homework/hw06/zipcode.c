/** Program demonstrating parsing and linked lists. This program
 * supports zip code lookup for any town in Massachusetts
 *
 * @author Blake Nelson
 *
 */

 #include <stdio.h>
 #include <string.h>
 #include <stdlib.h>

 #include <forward_list>

 #include "zipfed.hpp"


/** Function that compares alphabetically city names of 2 zip codes
 *
 * @param pZip1 is the 1st zip code
 * @param pZip2 is the 2nd zip code
 */

bool comparator_function(Zipfed* pZip1, Zipfed* pZip2) {
  int cmp = strcmp(pZip1->getcity().c_str(), pZip2->getcity().c_str());
  if (cmp > 0) {
      // pZip1 is alphabetically lower than pZip2
      return false;
  } else {
      // pZip2 is alphabetically higher than pZip1 or equal
      return true;
  }
}

/** Simple function that removes any white space or special character for comparison
 * @param str is the string being edited to remove whitespace
 */

void remove_whitespace(char *str) {
    char *start = str;
    char *end = str + strlen(str) - 1;

    // Remove leading white space and newlines
    while (isspace(*start) || *start == '\n') {
        start++;
    }

    // Remove trailing white space and newlines
    while (isspace(*end) || *end == '\n') {
        end--;
    }
    *(end+1) = '\0';

    // Remove white space and newlines in the middle of the string
    char *p = start;
    while (*p != '\0') {
        if (!isspace(*p) && *p != '\n') {
            *start = *p;
            start++;
        }
        p++;
    }
    *start = '\0';
}

/** program to find the zip code for any town in Massachusetts
 *
 * @param argc is the number of field on command line - should be 1
 * @param argv is array of strings entered on command line - prog name
 * @return 0 for success
 */

int main(int argc, char *argv[])
{
    FILE *fin;
    char line[100];
    char *zip, *type, *city, *state;
    double lat, lon;

    std::forward_list<Zipfed *> llist;

    if(argc < 2){
      printf("Please specify input csv!\n");
      return 1;
    }

    char* input = argv[1];

    fin = fopen(input, "r");
    while (fgets(line, 100, fin)) // read each line
    {
        zip = strtok(line, ",");
        type = strtok(NULL, ",");
        city = strtok(NULL, ",");
        state = strtok(NULL, ",");
        lat = atof(strtok(NULL, ","));
        lon = atof(strtok(NULL, "\n"));

        /*
        printf("Zip: %s\n", zip);
        printf("Type: %s\n", type);
        printf("City: %s\n", city);
        printf("State: %s\n", state);
        printf("Latitude: %f\n", lat);
        printf("Longitude: %f\n", lon);
        printf("\n");
        */

        Zipfed *tempZip = new Zipfed(zip, type, city, state, lat, lon);

        llist.push_front(tempZip);

    }
    fclose(fin); // close the file

    llist.sort(comparator_function);

    //uncomment to see the zip codes sorted alphabetically by city name
    /*
    for (Zipfed *z : llist) {
      z->print(fdOut);
    }
    */


    char* rline = NULL;
    size_t rlen = 0;
    ssize_t read;

    printf("Enter a city (or press ctrl-d to exit):\n");

    while ((read = getline(&rline, &rlen, stdin)) != -1) {

        std::string city(rline);

        remove_whitespace(rline);

        for (Zipfed *z : llist) {
          if(strcmp(z->getcity().c_str(), rline) == 0){
            z->print();
          }
        }

        free(rline);
        rline = NULL;
        rlen = 0;

        printf("Enter another city (or press ctrl-d to exit):\n");
    }

    free(rline);
    rline = NULL;

    return 0;
}
