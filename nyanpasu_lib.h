//
// Created by thgir on 27/02/2021.
//

#ifndef NF05_PROJET_REMAKE_STANDARD_FUNCTIONS_H
#define NF05_PROJET_REMAKE_STANDARD_FUNCTIONS_H


#ifdef __unix
#define fopen_s(pFile,filename,mode) ((*(pFile))=fopen((filename),(mode)))==NULL
#endif


#include <stdio.h>
#include <stdlib.h>

void * safe_malloc(size_t n);
FILE* open_file(const char* fileName, const char* mode);
void update_tm(struct tm* time, const int year, const int month, const int m_day,
               const int hour, const int minute, const int seconds);
int input_word(char **word);
void clear_buffer(void);
int power_of_two(int power);
void swap(void *a, void *b, size_t len);
int str_to_int(const char * str);

#endif //NF05_PROJET_REMAKE_STANDARD_FUNCTIONS_H
