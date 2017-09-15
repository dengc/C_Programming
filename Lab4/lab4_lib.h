/**
 * lab4_lib.h
 *
 * Provides the function prototypes for lab4_lib.c.
 *
 *		 ----------------------------
 * 		|	DO NOT MODIFY THIS FILE. |
 *		 ----------------------------
 *
 *      Authors: Coder Group
 *      Email:	shivaghose@purdue.edu
 *      Course: CNIT 315
 *      Lab:	3
 *		Created on:	30-Jan-2015
 */

#ifndef LAB4_LIB_H_
#define LAB4_LIB_H_

/**
 * Function: Add function name for accept string info here.
 *
 * Generates a function to accept a string
 *
 * Parameters:
 *
 * 	@param
 *
 * Returns:
 * 	@return 	0 - Successful.
 * 				1 - Fail/Error.
 *
 * Expectations:
 * 	- None
 */
int generate_random_int_array(int* array, int array_length); /*Change to correct function prototype */

/**
 * Function: Add function name for length of string info here.
 *
 * Add description for length of string function
 *
 * Parameters:
 * 	@param
 *
 *
 * Returns:
 * 	@return 	0 - Successful.
 * 				1 - Fail/Error.
 *
 * Expectations:
 * 	- Sorted array is the same size as the unsorted array.
 */
int bubble_sort(int* array_unsorted, int array_length, int* array_sorted);/*Change to correct function prototype */

/**
 * Function: Add function for number of vowels info here
 *
 * Sorts an integer array in ascending order using the selection sort
 * algorithm. The function does not modify the input array, and instead
 * returns a sorted copy.
 *
 * Parameters:
 * 	@param array_unsorted	Pointer to the unsorted integer array.
 * 	@param array_length		Number of elements in the array.
 * 	@param array_sorted		Pointer to the desired sorted array.
 *
 * Returns:
 * 	@return 	0 - Successful.
 * 				1 - Fail/Error.
 *
 * Expectations:
 * 	- Sorted array is the same size as the unsorted array.
 */
int selection_sort(int* array_unsorted, int array_length, int* array_sorted);/*Change to correct function prototype */

/**
 * Function: add function for number of words info here
 *
 * Sorts an integer array in ascending order using the insertion sort
 * algorithm. The function does not modify the input array, and instead
 * returns a sorted copy.
 *
 * Parameters:
 * 	@param array_unsorted	Pointer to the unsorted integer array.
 * 	@param array_length		Number of elements in the array.
 * 	@param array_sorted		Pointer to the desired sorted array.
 *
 * Returns:
 * 	@return 	0 - Successful.
 * 				1 - Fail/Error.
 *
 * Expectations:
 * 	- Sorted array is the same size as the unsorted array.
 */
int insertion_sort(int* array_unsorted, int array_length, int* array_sorted);/*Change to correct function prototype */

/**
 * Function: Add function for determine if character is alphanumeric info here
 *
 * Searches through an integer array to find the first occurrence of a value.
 * If the value is found, the function stores the location in the corresponding
 * variable, otherwise, -1 is used.
 *
 * Parameters:
 * @param array			Pointer to the integer array.
 * @param array_length  Number of elements in the array.
 * @param value			Integer that the algorithm searches for.
 * @param location		Pointer to the location of the search:
 * 							-1 - indicates that the value was not found.
 * 							location>=0 - 	indicates the position of the first
 * 											occurrence of the search value.
 *
 * Returns:
 * 	@return 	0 - Successful completion of the function.
 * 				1 - An error during operation.
 *
 * Expectations:
 * 	- None.
 */
int linear_search(int* array, int array_length, int value, int* location);/*Change to correct function prototype */
/**
 * Function: add substring function info here
 *
 * Searches through a sorted integer array to find the first occurrence of a
 * value using the binary search algorithm. If the value is found, the
 * function stores the location in the corresponding variable, otherwise, -1
 * is used to indicate that the query value was not found inside the array.
 *
 * Parameters:
 * @param array			Pointer to the sorted integer array.
 * @param array_length  Number of elements in the array.
 * @param value			Integer that the algorithm searches for.
 * @param location		Pointer to the location of the search:
 * 							-1 - indicates that the value was not found.
 * 							location>=0 - 	indicates the position of the first
 * 											occurrence of the search value.
 *
 * Returns:
 * 	@return 	0 - Successful completion of the function.
 * 				1 - An error during operation.
 *
 * Expectations:
 * 	- The input array is sorted.
 */
int binary_search(int* array, int array_length, int value, int* location);/*Change to correct function prototype */
/**
 * Function: void concat(char [], char [])
 *
 * Concatenates two strings into one
 *
 * Parameters:
 * @param char[]
 * @param char[]
 *
 *
 *
 * Returns:
 * 	@return 	0 - Successful completion of the function.
 * 				1 - An error during operation.
 *
 * Expectations:
 *
 */

void concat(char [], char []);
/**
 * Function: void remove(char* string1, char* string2)
 *
 * Accepts a two strings from user and removes string 2 from string 1.
 *
 * Parameters:
 * @param string1	The string with all the words.
 * @param string2  The string of characters that needs to be removed from string1
 *
 * Returns:
 * 	@return 	0 - Successful completion of the function.
 * 				1 - An error during operation.
 *
 * Expectations:
 *
 */
//void remove(char* string1, char* string2)  this function is defined in stdio.h
void removeString(char* string1, char* string2);

int acceptString(char string[]);

int vowelCount(char string[]);

int findLength(char string[]);

int wordCount(char string[]);

int alphanum(char c);
/**
 * Takes the character and determines if it is a letter A-Z or a number 1-9
 *
 * Accepts one character from the user
 *
 * Parameters:
 * @param c     Character enetered by the user
 *
 * Returns:
 * 1 -successful  completion
 * 0- an error occured during the operation.
 */
void substring(char string[], char sub[], int pos, int len);
/**
 *Takes the substring of a string entered by the user given the paramerters
 *
 * Accepts 1 string from user and the position and length of the substring
 *
 * Parameters:
 * @param string[]     string enetered by user
 * @param sub[]        substring retruned to user
 * @param pos          start position of substring (first position = 1)
 * @param len          end position of substring
 *
 * Returns:
 * sub[] if user input is valid
 * Null (/0) if user input is invalid
 *
 * Expectations:
 * None
 */
int removestr(char *line, char *search);

#endif /* LAB4_LIB_H_ */