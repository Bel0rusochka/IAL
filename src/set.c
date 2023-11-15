#include "set.h"


//Implementation of the set.h header file

void initSet(CharSet *set, size_t capacity){
    set->elements = (char *)malloc(capacity * sizeof(char));
    if (set->elements == NULL) {
        fprintf(stderr, "Error: Memory allocation failed\n");
        exit(2);
    }
    set->size = 0;
    set->capacity = capacity;
}


void addToSet(CharSet *set, char value){

    if (set->size < set->capacity) {
        set->elements[set->size++] = value;
    }else {
        fprintf(stderr, "Error: Set has reached the maximum number of elements\n");
        exit(4);
    }
}


void removeFromSet(CharSet *set, char value){
    for (size_t i = 0; i < set->size; ++i) {
        if (set->elements[i] == value) {
            for (size_t j = i; j < set->size - 1; ++j) {
                set->elements[j] = set->elements[j + 1];
            }
            set->size--;
            return;
        }
    }
}


bool containsInSet(const CharSet *set, char value){

    for (size_t i = 0; i < set->size; ++i) {
        if (set->elements[i] == value) {
            return true;
        }
    }
    return false;
}


void printSet(const CharSet *set){
    printf("Set: { ");
    for (size_t i = 0; i < set->size; ++i) {
        printf("%c ", set->elements[i]);
    }
    printf("}\n");
}


void freeSet(CharSet *set){
    free(set->elements);
    set->elements = NULL;
    set->size = 0;
    set->capacity = 0;
}

