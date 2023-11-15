#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>



#ifndef SET_H
#define SET_H

/*
Structure for storing a set of characters, implemented as a dynamic array. Where each element is a character. 
Has a size(used elements) and a capacity(maximum number of elements).
*/
typedef struct {
    char *elements;
    size_t size;
    size_t capacity;
} CharSet;

/**
 * @brief Function for initializing the set.
 * 
 * @param set Pointer to the set
 * @param capacity The maximum number of elements in the set
*/
void initSet(CharSet *set, size_t capacity);


/**
 * @brief Function for adding an element to the set.
 * 
 * @param set Pointer to the set
 * @param value The value of the element to be added
*/
void addToSet(CharSet *set, char value);


/**
 * @brief Function for removing an element from the set.
 * 
 * @param set Pointer to the set
 * @param value The value of the element to be removed
*/
void removeFromSet(CharSet *set, char value);


/**
 * @brief Function for checking if an element is in the set.
 * 
 * @param set Pointer to the set
 * @param value The value of the element to be checked
 * @return true If the element is in the set
 * @return false If the element is not in the set
*/
bool containsInSet(const CharSet *set, char value);


/**
 * @brief Function for printing the set to the console.
 * 
 * @param set Pointer to the set
*/
void printSet(const CharSet *set);


/**
 * @brief Function for freeing memory allocated for the set.
 * 
 * @param set Pointer to the set
*/
void freeSet(CharSet *set);

#endif