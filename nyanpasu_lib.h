//
// Created by thgir on 27/02/2021.
//

#ifndef NYANPASU_LIB_H
#define NYANPASU_LIB_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Works in the same way as a classical malloc(), but handles exceptions
 * @example int *array = safe_malloc(ARRAY_SIZE * sizeof(int));
 * @param n : the size of the memory to allocate
 * @return a pointer to the allocated memory
 */
void * safe_malloc(size_t n);

/**
 * Works in the same way as a classical fopen(), but handles exceptions
 * @example FILE * file = open_file("example.txt", "r");
 * @param fileName : the name of the file to open
 * @param mode : the opening mode
 * @return a pointer to the opened file
 */
FILE *open_file(const char *fileName, const char *mode);

/**
 * Secured alternative to scanf("%s", word).
 * Scans the whole line and allocate the exact memory size needed for it
 * @example char * str;  input_word(&str);
 * @param word : a pointer to the char array
 */
void input_word(char **word);

/**
 * Clear the buffer.
 * @warning If stdin contains no \ n character, the program will freeze until the user press enter
 */
void clear_buffer(void);

/**
 * calculates 2^n, with n given by the user.
 * @param power : the power of n
 * @return an int corresponding to 2^n
 */
int power_of_two(int power);

/**
 * Swaps two variables, whatever their type is
 * @example swap(&varA, &varB, sizeof(a))
 * @param a : a pointer to the first variable
 * @param b  : a pointer to the second variable
 * @param len : the size in memory of a and b
 */
void swap(void *restrict a, void *restrict b, size_t len);

/**
 * Come on, are you really dumb enough to use this function
 * instead of the atoi() function of <stdlib.h> ?
 */
int str_to_int(const char * str);

#endif //NYANPASU_LIB_H

