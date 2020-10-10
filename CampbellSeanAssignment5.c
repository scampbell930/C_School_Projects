/*
 ============================================================================
 Name        : CampbellSeanAssignment5.c
 Author      : Sean Campbell
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Structure borrowed from book fig 12.3
struct listNode {
	char data;
	struct listNode *nextPtr;
};

typedef struct listNode ListNode;
typedef ListNode *ListNodePtr;

int checkRows(char board[9][9]); //checkRows prototype
int checkColumns(char board[9][9]); //checkColumns prototype
int checkThrees(char board[9][9]); //checkThhrees prototype
int size(ListNodePtr *sPtr); //size prototype
void insert(ListNodePtr *sPtr, char value); //insert prototype
int isEmpty(ListNodePtr *sPtr); //isEmpty prototype
void printList(ListNodePtr currnetPtr); //printList prototype
void removeDuplicates(ListNodePtr *sPtr); //removeDuplicates prototype

int main(void) {

	// Creating file pointer and variables where data will be stored
	FILE *fPtr;
	char boardsText[500];
	int numBoards;

	if ((fPtr = fopen("C:\\Dev\\eclipse-workspace\\gameboards.txt", "r")) == NULL) {
			puts("File could not be opened");
		}

	else {

		// Reading number of gameboards
		fscanf(fPtr, "%d", &numBoards);

		// Initializing gamboard arrays
		char gameboard1[9][9];
		char gameboard2[9][9];
		int i = 0;

		// Looping through file
		while (!feof(fPtr)) {

			// Reading line of text
			fscanf(fPtr, "%s", boardsText);

			// Checking if it is the first or second gameboard
			if (i < 9) {
				for (int j = 0; j < 9; j++) {
					if (boardsText[j] >= 'A' && boardsText[j] <= 'I') {
						gameboard1[i][j] = boardsText[j];
					}
				}

			}
			else {
				for (int j = 0; j < 9; j++) {
					if (boardsText[j] >= 'A' && boardsText[j] <= 'I') {
						gameboard2[i - 9][j] = boardsText[j];
					}
				}
			}
			i++;
		}

		// Checking if board solves sudoku
		if (checkRows(gameboard1) == 9) {
			if (checkColumns(gameboard1) == 9) {
				if (checkThrees(gameboard1) == 9) {
					puts("Valid");
				}
				else {
					puts("Invalid");
				}
			}
			else {
				puts("Invalid");
			}
		}
		else {
			puts("Invalid");
		}

		// Printing gameboard
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				printf("%c", gameboard1[i][j]);
				if (j == 8) {
					puts(" ");
				}
			}
		}

		puts(" ");
		// Checking if board solves sudoku
		if (checkRows(gameboard2) == 9) {
			if (checkColumns(gameboard2) == 9) {
				if (checkThrees(gameboard2) == 9) {
					puts("Valid");
				}
				else {
					puts("Invalid");
				}
			}
			else {
				puts("Invalid");
			}
		}
		else {
			puts("Invalid");
		}

		// Printing gameboard
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				printf("%c", gameboard2[i][j]);
				if (j == 8) {
					puts(" ");
				}
			}
		}
	}
	return EXIT_SUCCESS;
}

int checkRows(char board[9][9]) {

	// Counter for number of valid rows
	int valid = 0;
	// Looping through rows
	for (int i = 0; i < 9; i++) {

		ListNodePtr startPtr = NULL;

		for (int j = 0; j < 9; j++) {
			// Add current character to linked list
			insert(&startPtr, board[i][j]);
		}

		removeDuplicates(&startPtr);

		if (size(&startPtr) == 9) {
			valid++;
		}
	}

	return valid;

} //checkRows

int checkColumns(char board[9][9]) {

	// Counter for number of valid columns
	int valid = 0;
	// Looping through columns
	for (int j = 0; j < 9; j++) {

		ListNodePtr startPtr = NULL;

		for (int i = 0; i < 9; i++) {
			// Add current character to linked list
			insert(&startPtr, board[i][j]);
		}

		removeDuplicates(&startPtr);

		if (size(&startPtr) == 9) {
			valid++;
		}
	}

	return valid;

} //checkColumns

int checkThrees(char board[9][9]) {

	// Counter for number of valid threes
	int valid = 0;

	ListNodePtr startPtr = NULL;

	// Loop through 3x3 sections
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			insert(&startPtr, board[i][j]);
		}
	}

	removeDuplicates(&startPtr);

	if (size(&startPtr) == 9) {
		valid++;
	}

	startPtr = NULL;

	// Loop through 3x3 sections
	for (int i = 0; i < 3; i++) {
		for (int j = 3; j < 6; j++) {
			insert(&startPtr, board[i][j]);
		}
	}

	removeDuplicates(&startPtr);

	if (size(&startPtr) == 9) {
		valid++;
	}

	startPtr = NULL;

	// Loop through 3x3 sections
	for (int i = 0; i < 3; i++) {
		for (int j = 6; j < 9; j++) {
			insert(&startPtr, board[i][j]);
		}
	}

	removeDuplicates(&startPtr);

	if (size(&startPtr) == 9) {
		valid++;
	}

	startPtr = NULL;

	// Loop through 3x3 sections
	for (int i = 3; i < 6; i++) {
		for (int j = 0; j < 3; j++) {
			insert(&startPtr, board[i][j]);
		}
	}

	removeDuplicates(&startPtr);

	if (size(&startPtr) == 9) {
		valid++;
	}

	startPtr = NULL;

	// Loop through 3x3 sections
	for (int i = 3; i < 6; i++) {
		for (int j = 3; j < 6; j++) {
			insert(&startPtr, board[i][j]);
		}
	}

	removeDuplicates(&startPtr);

	if (size(&startPtr) == 9) {
		valid++;
	}

	startPtr = NULL;

	// Loop through 3x3 sections
	for (int i = 3; i < 6; i++) {
		for (int j = 6; j < 9; j++) {
			insert(&startPtr, board[i][j]);
		}
	}

	removeDuplicates(&startPtr);

	if (size(&startPtr) == 9) {
		valid++;
	}

	startPtr = NULL;

	// Loop through 3x3 sections
	for (int i = 6; i < 9; i++) {
		for (int j = 0; j < 3; j++) {
			insert(&startPtr, board[i][j]);
		}
	}

	removeDuplicates(&startPtr);

	if (size(&startPtr) == 9) {
		valid++;
	}

	startPtr = NULL;

	// Loop through 3x3 sections
	for (int i = 6; i < 9; i++) {
		for (int j = 3; j < 6; j++) {
			insert(&startPtr, board[i][j]);
		}
	}

	removeDuplicates(&startPtr);

	if (size(&startPtr) == 9) {
		valid++;
	}

	startPtr = NULL;

	// Loop through 3x3 sections
	for (int i = 6; i < 9; i++) {
		for (int j = 6; j < 9; j++) {
			insert(&startPtr, board[i][j]);
		}
	}

	removeDuplicates(&startPtr);

	if (size(&startPtr) == 9) {
		valid++;
	}

	return valid;

} //checkThrees

// Insert function borrowed from book fig 12.3
void insert(ListNodePtr *sPtr, char value) {
	// Creating node
	ListNodePtr newPtr = malloc(sizeof(ListNode));

	// Checking if there is space available
	if (newPtr != NULL) {
		newPtr->data = value;
		newPtr->nextPtr = NULL;

		// Creating two pointers for traversing list
		ListNodePtr previousPtr = NULL;
		ListNodePtr currentPtr = *sPtr;

		// Looping to find correct spot for newPtr
		while (currentPtr != NULL && (strcmp(&value, &currentPtr->data)) > 0) {
				previousPtr = currentPtr;
				currentPtr = currentPtr->nextPtr;
		}

		// Insert new node at beginning of list
		if (previousPtr == NULL) {
			newPtr->nextPtr = *sPtr;
			*sPtr = newPtr;
		}
		else {
			previousPtr->nextPtr = newPtr;
			newPtr->nextPtr = currentPtr;
		}
	}
	else {
		printf("%c not inserted. No memory available.\n", value);
	}

} //insert

// Calculates how many elements are in a linked list
int size(ListNodePtr *sPtr) {

	// Initializing node pointer and counter
	ListNodePtr currentNode = *sPtr;
	int count = 0;

	while (currentNode != NULL && isalpha(currentNode->data)) {
		currentNode = currentNode->nextPtr;
		count++;
	}

	return count;

} //size

// Determines if list is empty
int isEmpty(ListNodePtr *sPtr) {
	return sPtr == NULL;
}

// Prints current linked list
void printList(ListNodePtr currentPtr) {

	// Checks if list is empty
	if (isEmpty(&currentPtr)) {
		puts("List is empty.\n");
	}
	else {
		puts("The list is: ");

		// Checking if youve reached the end of the list
		while (currentPtr != NULL) {
			printf("%c --> ", currentPtr->data);
			currentPtr = currentPtr->nextPtr;
		}
		puts("NULL");
	}
}

void removeDuplicates(ListNodePtr *sPtr) {
	if (!isEmpty(sPtr)) {
		ListNodePtr currentPtr = *sPtr;

		while (currentPtr->nextPtr != NULL) {
			if (currentPtr->data == currentPtr->nextPtr->data) {
				ListNodePtr afterNext = currentPtr->nextPtr->nextPtr;
				free(currentPtr->nextPtr);
				currentPtr->nextPtr = afterNext;
			}
			else {
				currentPtr = currentPtr->nextPtr;
			}
		}
	}
}
