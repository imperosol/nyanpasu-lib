//
// Created by thgir on 27/02/2021.
//

#ifndef NYANPASU_LIB_H
#define NYANPASU_LIB_H

#include <stdio.h>
#include <stdlib.h>

/**
 * Works in the same way as a classical malloc(), but handles exceptions
 * @example int *array = safe_malloc(ARRAY_SIZE * sizeof(int));
 * @param n : the size of the memory to allocate
 * @return a pointer to the allocated memory
 */
__attribute__((unused)) void * safe_malloc(size_t n);

/**
 * Works in the same way as a classical fopen(), but handles exceptions
 * @example FILE * file = open_file("example.txt", "r");
 * @param fileName : the name of the file to open
 * @param mode : the opening mode
 * @return a pointer to the opened file
 */
__attribute__((unused)) FILE *open_file(const char *restrict fileName, const char *restrict mode);

/**
 * Secured alternative to scanf("%s", word).
 * Scans the whole line and allocate the exact memory size needed for it
 * @example char * str;  input_word(&str);
 * @param word : a pointer to the char array
 */
__attribute__((unused)) void input_word(char **word);

/**
 * Works the same way as input_word(), but the input stream can be explicitly selected
 * Useful when needing to read a string from a file
 * @example char * str;  input_word(&str, stdin);
 * @example char * str; FILE *foo = fopen(filename, "r");  input_word(&str, foo);
 * @param word : a pointer to the char array
 */
__attribute__((unused)) void input_word_from_file(char **word, struct _iobuf *stream);

/**
 * Secured alternative to scanf("%d", var).
 * Scans an int and returns it, without buffer overflow.
 * @example int foo = scant_int("please input an integer :"); // with message
 * @example int foo = scant_int(NULL); // without message
 * @return the integer scanned from the stdin
 */
__attribute__((unused)) int input_int(const char *message);

/**
 * Works the same way as input_int(), but the  input stream can be explicitly selected
 * @return the integer scanned from the selected stream
 */
__attribute__((unused)) int input_int_from_file(struct _iobuf *stream);

/**
 * Works the same way as scan_int_from_file(), but multiple values can be scanned
 * The values can be input by user one on each line or all on the same line, with whitespace as a separator,
 * both methods work.
 * @example int array[5]; scan_int_array(stdin, array, 5);
 * @param stream : the stream from which the data must be read
 * @param array : the address of the array to fill wit values
 * @param nb_values : the number of values to be read
 */
__attribute__((unused)) void scan_int_array(struct _iobuf *stream, int *array, int nb_values);

/**
 * Clear the buffer.
 * @warning If stdin contains no \ n character, the program will freeze until the user press enter
 */
__attribute__((unused)) void clear_buffer(void);

/**
 * calculates 2^n, with n given by the user.
 * @param power : the power of n
 * @return an int corresponding to 2^n
 */
__attribute__((unused)) int power_of_two(int power);

/**
 * Swaps two variables, whatever their v_type is
 * @example swap(&varA, &varB, sizeof(a))
 * @param a : a pointer to the first variable
 * @param b  : a pointer to the second variable
 * @param len : the size in memory of a and b
 */
__attribute__((unused)) void swap(void *restrict a, void *restrict b, size_t len);

/**
 * Counts the number of times a character appears in a string
 * @param str : the string in which the character must be searched
 * @param searched_char : the searched character
 * @return the number of times the wanted character has been found in the str
 * @example char foo[] = "Hello, World!"; unsigned int bar = count_char(foo, 'l');
 */
__attribute__((unused)) unsigned int count_char(const char *str, char searched_char);


#endif //NYANPASU_LIB_H
