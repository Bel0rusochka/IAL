#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>



#ifndef SET_H
#define SET_H

typedef struct {
    char *elements;
    size_t size;
    size_t capacity;
} CharSet;

void initSet(CharSet *set, size_t capacity);
void addToSet(CharSet *set, char value);
void removeFromSet(CharSet *set, char value);
bool containsInSet(const CharSet *set, char value);
void printSet(const CharSet *set);
void freeSet(CharSet *set);

#endif