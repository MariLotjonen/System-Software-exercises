/* File: Exercise4.c
* Author: Mari Lotjonen
* Description: Arrays and primefactors main. Make an array with the length input by user in command line argument.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include "PrimeFactors.h"


int randomNumber();

int main (int argc, char *argv[]) {

	// argc is number of arguments given
	// argv is list of string containing command line arguments
	srand(time(NULL));
	int tonumber = 0;

	printf("\nTotal number of given arguments is %d.", argc - 1);
	printf("\n(Exercise4 as an argument is excluded from this count)\n");
	// total number of given arguments has to be 2 because Exercise4 is counted as one argument and the user has to give one single integer 

	if (argc == 2) 	// one argument plus Exercise4 is inserted!
	{
		int length = strlen(argv[1]);
		printf("\nThe argument you input is %s.\nYou have given %d argument with lenght of %d.\n", argv[1], argc - 1, length);	// print out the length of an argument

		if (argv[1][0] == '0')
		{
			printf("\nERROR: Array lenght can not be zero or begin with zero! Try again!\n");
			return 0;
		}
		else
		{
			for (int i = 0; i < length; i++) 
			{
				if ((isdigit(argv[1][i])) == 0)		// checks if the inserted argument is made of only digits. If not true stop and print error message.
				{
					printf("ERROR: Is not a number! Try again!\n");
					return 0;
				}
			}
		}
		tonumber = atoi(argv[1]);	// convert to number
		printf("\nArgument converted to number: %d. This is the lenght of the array!\n", tonumber);
	}
	else if (argc > 2)  // too many arguments
	{
		printf("\nERROR: You have given more than one argument. You have given %d integers or other arguments. Input has to be one integer!\n", argc - 1);
		return 0;
	}
	else // nothing is inserted but Exercise4 call
	{
		printf("\nERROR: You have not given the integer correctly. There is %d integers. Input has to be one integer!\n", argc - 1);
		return 0;
	}
	
	int *array = NULL;	// array pointer
	array = (int*) malloc(tonumber * sizeof(int));		// using the dynamic memory allocation
	
	printf("Return random numbers between 0 and 1 000 000 in to my array!\n");

	for (int j = 0; j < tonumber; j++) 	// continue while all of the array is looped through
	{
		*(array + j) = randomNumber();		// set randoms into array

	}
	
	for (int k = 0; k < tonumber; k++)
	{
		if (*(array + k) == 1 || *(array + k) == 0) 	// if there is 1 or 0 inside the array, display it has no prime factors
		{		
		printf("\nThere is no prime factors for %d", *(array + k));
		}
		else 
		{		
		printf("\nLargest Prime factor of %d is %d", *(array + k), primeFactors(*(array + k)));		// print randoms out from array
		}
	}
	printf("\n");
	return 0;	
}

int randomNumber()
{
	int r = rand() % 1000000;		// generate random number
	return r;
}

