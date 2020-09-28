/* File: Exercise5.c
* Author: Mari Lotjonen
* Description: read how many languages user wants to input and then ask more info about languages
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define NAME 40
#define ISO 5
#define FAMILY 30
#define SPEAKERS 6

struct Languages		// define what is stored into struct
{
	char name[NAME];
	char isoCode[ISO];
	char family[FAMILY];
	char speakers[SPEAKERS];
};

void addLanguage(struct Languages *ptr, int numberOfLanguages); 
void printLanguages(struct Languages *ptr, int numberOfLanguages); 

int main() 
{
	int numberOfLanguages = 0;		
	char inputBuffer[20] = "";		// create buffer where to store the user input

	printf("\nHow many languages you want to add?\n");
	fgets(inputBuffer, sizeof(inputBuffer), stdin);
	int argumentLength = strlen(inputBuffer);	
	inputBuffer[strlen(inputBuffer) - 1] = '\0';		// removes newline
		
	for ( int count = 0; count < argumentLength - 1; count++)
	{
		if ((isdigit(inputBuffer[count])) == 0)		// check that the input is valid
		{
			printf("\nArgument you have given is not valid!\n");
			return 0;
		}

	}
	numberOfLanguages = atoi(inputBuffer);	

	struct Languages *ptr = NULL;		// pointer to struct
	ptr = (struct Languages*) malloc(numberOfLanguages * sizeof(struct Languages));
	if(ptr == NULL)
	{
		printf("Memory allocation failed!");
		return 0;
	}
	
	addLanguage(ptr, numberOfLanguages);	
	printLanguages(ptr, numberOfLanguages);
	free(ptr);
	return 0;
}

void addLanguage(struct Languages *ptr, int numberOfLanguages)
{
	for(int languageNumber = 0; languageNumber < numberOfLanguages; languageNumber++)
	{	
		while(1)
		{
			printf("Enter language name: ");
			fgets(ptr -> name, sizeof(ptr -> name), stdin);

			if ((strlen(ptr -> name) > 0) && (ptr ->name[strlen (ptr -> name) -1 ] == '\n'))	// remove new line
			{
				ptr -> name[strlen (ptr -> name) - 1] = '\0';
			}

			if (ptr -> name[0] != '\0')		// check that language name will not be empty, if language name is inserted break, otherwise print error message
			{
				break;
			}
			printf("Language name shall not be empty!\n");
		}

		printf("Enter ISO 639-1 code: ");
		fgets(ptr -> isoCode, sizeof(ptr -> isoCode), stdin);

		if ((strlen(ptr -> isoCode) > 0) && (ptr -> isoCode[strlen (ptr -> isoCode) -1 ] == '\n'))
		{
			ptr -> isoCode[strlen (ptr -> isoCode) - 1] = '\0';
		}
		
		printf("Enter family: ");
		fgets(ptr -> family, sizeof(ptr -> family), stdin);

		if ((strlen(ptr -> family) > 0) && (ptr -> family[strlen (ptr -> family) -1 ] == '\n'))
		{
			ptr -> family[strlen (ptr -> family) - 1] = '\0';
		}
		
		printf("Enter number of speakers in millions: ");
		fgets(ptr -> speakers, sizeof(ptr -> speakers), stdin);

		if ((strlen(ptr -> speakers) > 0) && (ptr -> speakers[strlen (ptr -> speakers) -1 ] == '\n'))
		{
			ptr -> speakers[strlen (ptr -> speakers) - 1] = '\0';
		}
		ptr++;
		printf("\n");
	}
}

void printLanguages(struct Languages *ptr, int numberOfLanguages) 
{
	if (numberOfLanguages == 0)
	{
		printf("\nYou have not given any argument! You should add something! Try again! Give a number how many languages you want to add!\n");
	}
	else
	{
		printf("\n***  LIST OF LANGUAGES ***\n");	
		for (int i= 0; i < numberOfLanguages; i++)			// print languages from the struct with a pointer
		{

			printf("\n\nName: 		%s", ptr -> name);
			printf("\nCode: 		%s", ptr-> isoCode);
			printf("\nFamily: 	%s", ptr -> family);
			printf("\nSpeakers: 	%s", ptr -> speakers);
			ptr++;
		}
		printf("\n");
	}

}
