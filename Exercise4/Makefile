# File: Makefile
# Author: Mari Lotjonen
# Description: build an executable named Exercise4 from Exercise4.c and PrimeFactors.c

all: Exercise4.c PrimeFactors.c
	gcc -Wextra -Wall -std=c11 -c Exercise4.c PrimeFactors.c
	gcc Exercise4.o PrimeFactors.o -o Exercise4

clean:
	$(RM) *.o Exercise4
