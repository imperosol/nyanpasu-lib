#include <string.h>
#include "nyanpasu_lib.h"

void *safe_malloc(size_t n) {
    void *p = malloc(n);
    if (p == NULL) {
        fprintf(stderr, "Fatal: failed to allocate %zu bytes.\n", n);
        exit(1);
    }
    return p;
}

#ifdef _WIN32
/* Windows only function */
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
#endif

#ifndef _WIN32
/* Function compatible with any OS, but do not return the precise error in case of failure */
FILE *open_file(const char *fileName, const char *mode) {
    FILE *toOpen = NULL;
    toOpen = fopen(fileName, mode);
    if (toOpen == NULL) {
        fprintf(stderr, "cannot open file");
        exit(1);
    } else {
        return toOpen;
    }
}
#endif

void input_word(char **word) {
    if (*word != NULL)
        free(*word);
    char temp[50];
    fgets(temp, 49, stdin);
    temp[strlen(temp) - 1] = '\0';
    *word = safe_malloc(sizeof(char) * strlen(temp) + 1);
    strcpy(*word, temp);
}

int scan_int(void) {
    char temp[50];
    fgets(temp, 49, stdin);
    return strtol(temp, NULL, 10);
}

void clear_buffer(void) {
    char c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int power_of_two(int power) {
    return 0b1 << power;
}

void swap(void *restrict a, void *restrict b, const size_t len) {
    void *tmp = safe_malloc(len);
    tmp = memcpy(tmp, a, len);
    memcpy(a, b, len);
    memcpy(b, tmp, len);
    free(tmp);
}
