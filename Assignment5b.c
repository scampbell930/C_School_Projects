/*
 ============================================================================
 Name        : Assignment5b.c
 Author      : Sean Campbell
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {

	// Creating a file pointer and variables to store values from file
	FILE *fPtr;
	int numValues;

	// Attempting to open file
	if ((fPtr = fopen("C:\\Dev\\eclipse-workspace\\intConversion.txt", "r")) == NULL){
		puts("File could not be opened");
	}

	else {
		fscanf(fPtr, "%d", &numValues);

		// Initializing counter
		int counter = 0;

		// Loop reading and printing new values numValues times
		while (counter < numValues) {

			// Initializing current values to be converted
			int value;
			fscanf(fPtr, "%d", &value);

			// Convert integer into string
			char valueStr[50];
			sprintf(valueStr, "%d", value);

			// Declaring index for string
			int index = 0;

			while (index < strlen(valueStr)) {

				// Number of times values is repeated
				int repeat = 1;

				// Checking if number is being repeated
				while (valueStr[index] == valueStr[index + 1]) {
					repeat++;
					index++;
				}

				printf("%d%c", repeat, valueStr[index]);
				fflush(stdout);
				index++;

			}
			puts("");
			counter++;
		}

	}
	return EXIT_SUCCESS;
}






