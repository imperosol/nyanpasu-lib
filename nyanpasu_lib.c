#include "nyanpasu_lib.h"
#include <string.h>

__attribute__((unused)) void *safe_malloc(const size_t n) {
    void *p = malloc(n);
    if (p == NULL) {
        fprintf(stderr, "Fatal: failed to allocate %zu bytes.\n", n);
        exit(1);
    }
    return p;
}

#ifdef _WIN32
/* Windows only function */
__attribute__((unused)) FILE *open_file(const char * restrict const fileName, const char * restrict const mode) {
    int err;
    FILE *toOpen = NULL;
    if ((err = fopen_s(&toOpen, fileName, mode))) {
        fprintf(stderr, "cannot open file '%s': %s\n", fileName, strerror(err));
        exit(err);
    } else {
        return toOpen;
    }
}
#endif

#ifndef _WIN32
/* Function compatible with any OS, but do not return the precise error in case of failure */
__attribute__((unused)) FILE *open_file(const char * restrict const fileName, const char * restrict const mode) {
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

__attribute__((unused)) void input_word(char **word) {
    char temp[50];
    fgets(temp, 49, stdin);
    temp[strlen(temp) - 1] = '\0';
    *word = safe_malloc(sizeof(char) * strlen(temp) + 1);
    strcpy(*word, temp);
}

__attribute__((unused)) void input_word_from_file(char **word, struct _iobuf *stream) {
    char temp[50];
    fgets(temp, 49, stream);
    temp[strlen(temp) - 1] = '\0';
    *word = safe_malloc(sizeof(char) * strlen(temp) + 1);
    strcpy(*word, temp);
}

__attribute__((unused)) int input_int(const char * const message) {
    if (message != NULL)
        printf("%s ", message);
    char temp[50];
    fgets(temp, 49, stdin);
    return strtol(temp, NULL, 10);
}

__attribute__((unused)) int input_int_from_file(struct _iobuf *stream) {
    char temp[50];
    fgets(temp, 49, stream);
    return strtol(temp, NULL, 10);
}

__attribute__((unused)) void scan_int_array(struct _iobuf *stream, int *const array, const int nb_values) {
    int current_value;
    char input[100];
    char *remaining;
    for (int index = 0; index < nb_values;) { // index is updated in the inner loop
        fgets(input, 99, stream);
        remaining = input;
        while (*remaining != '\n' && *remaining != '\0' && index < nb_values) {
            current_value = strtol(remaining, &remaining, 10);
            array[index] = current_value;
            index++;
        }
    }
}

__attribute__((unused)) void clear_buffer(void) {
    char c;
    while ((c = getchar()) != '\n' && c != EOF);
}

__attribute__((unused)) int power_of_two(int power) {
    return 0b1 << power;
}

__attribute__((unused)) void swap(void *restrict const a, void *restrict const b, const size_t len) {
    void *tmp = safe_malloc(len);
    tmp = memcpy(tmp, a, len);
    memcpy(a, b, len);
    memcpy(b, tmp, len);
    free(tmp);
}

__attribute__((unused)) unsigned int count_char(const char *restrict const str, const char searched_char) {
    unsigned int count = 0;
    for (int i = 0; str[i] != '\0'; ++i) {
        if (str[i] == searched_char) {
            ++count;
        }
    }
    return count;
}
