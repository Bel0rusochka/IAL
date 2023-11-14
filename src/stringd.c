#include "stringd.h"

void initDynamicString(DynamicString *str, size_t initialCapacity) {
    str->data = (char *)malloc(initialCapacity * sizeof(char));
    if (str->data == NULL) {
        fprintf(stderr, "Error: Memory allocation failed\n");
        exit(2);
    }
    str->length = 0;
    str->capacity = initialCapacity;
}


void appendToDynamicString(DynamicString *str, char ch) {
    if (str->length + 1 >= str->capacity) {
        str->capacity *= 2;
        str->data = (char *)realloc(str->data, str->capacity * sizeof(char));
        if (str->data == NULL) {
            fprintf(stderr, "Error: Memory reallocation failed\n");
            exit(2);
        }
    }
    str->data[str->length] = ch;
    str->length++;
    str->data[str->length] = '\0';
}


void freeDynamicString(DynamicString *str) {
    free(str->data);
    str->length = 0;
    str->capacity = 0;
}


char* copyDynamicString(DynamicString *str) {
    char *copy = (char *)malloc((str->length + 1) * sizeof(char));
    if (copy == NULL) {
        fprintf(stderr, "Error: Memory allocation failed\n");
        exit(2);
    }
    strcpy(copy, str->data);
    return copy;
}