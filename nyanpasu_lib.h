//
// Created by thgir on 27/02/2021.
//

#ifndef NF05_PROJET_REMAKE_STANDARD_FUNCTIONS_H
#define NF05_PROJET_REMAKE_STANDARD_FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>

void * safe_malloc(size_t n);

FILE* open_file(const char* fileName, const char* mode);

int input_word(char **word);

void clear_buffer(void);

unsigned long power_of_two(int power);

void swap(void *a, void *b, size_t len);

int str_to_int(const char * str);

#endif //NF05_PROJET_REMAKE_STANDARD_FUNCTIONS_H
