#ifndef STRINGD_H
#define STRINGD_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct DynamicString{
    char *data;
    size_t length;
    size_t capacity;
} DynamicString;

void initDynamicString(DynamicString *str, size_t initialCapacity);
void appendToDynamicString(DynamicString *str, char ch);
void freeDynamicString(DynamicString *str);
char* copyDynamicString(DynamicString *str);
#endif