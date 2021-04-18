//
// Created by thgir on 27/02/2021.
//

#include <string.h>
#include <ctype.h>
#include "standard_functions.h"

void *safe_malloc(size_t n) {
    void *p = malloc(n);
    if (p == NULL) {
        fprintf(stderr, "Fatal: failed to allocate %zu bytes.\n", n);
        exit(1);
    }
    return p;
}

FILE *open_file(const char *fileName, const char *mode) {
    int err;
    FILE *toOpen = NULL;
    if ((err = fopen_s(&toOpen, fileName, mode))) {
        fprintf(stderr, "cannot open file '%s': %s\n", fileName, strerror(err));
        exit(1);
    } else {
        return toOpen;
    }
}

int input_word(char **word) {
    char temp[40];
    fgets(temp, 40, stdin);
    *word = safe_malloc(sizeof(char) * strlen(temp) + 1);
    strcpy(*word, temp);
    printf("%s\n", *word);
    return 0;
}

void clear_buffer(void) {
    char c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int power_of_two(int power) {
    return 0b1 << power;
}

void swap(void *a, void *b, size_t len) {
    unsigned char *p = a, *q = b, tmp;
    for (size_t i = 0; i != len; ++i) {
        tmp = p[i];
        p[i] = q[i];
        q[i] = tmp;
    }
}

int str_to_int(const char * str) {
    int number = 0;
    /* security check */
    for (int i = 0; str[i] != '\0'; ++i) {
        if (!is_digit(str[i]))
            return 0;
    }
    /* conversion */
    for (int i = strlen(str) - 1, power = 1; i >= 0; --i, power *= 10)
        number += (str[i] - '0') * power;
    return number;
}
