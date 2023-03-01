Daniel Baranov
CS 2303

To build program, simply type make.

fed2cs2303 takes the free-zipcode-database.csv and processes it into an output
csv that contains only relevant information on massachusetts zipcodes

to run: ./fed2cs2303 free-zipcode-database.csv [OUTPUT NAME].csv


zipcode takes the output of fed2cs2303 and not only sorts it, but lets You
type in cities and only display the zip codes and their information for that city.

to run: ./zipcode [OUTPUT NAME].csv


I had to grab a function from the web for removing whitespace because
I was having trouble with that.
