/* File: PrimeFactors.c
* Author: Mari Lotjonen
* Description: primefactors and the code inside the function
*/


#include <stdio.h>
#include "PrimeFactors.h"



int primeFactors(int primeCandinate)
{
	int div = 2; 		// creating the variables
	int maxFactor = 0;
		
	while (primeCandinate != 0)	// continue while "primeCandinate" is not zero
	{		
		if (primeCandinate % div != 0) 
		{
		div = div + 1; 
		}
		else 
		{
		maxFactor = primeCandinate;
		primeCandinate = primeCandinate / div;

			if (primeCandinate == 1) 
			{
			break;	
			}
		}
	}
	return maxFactor;	
}

