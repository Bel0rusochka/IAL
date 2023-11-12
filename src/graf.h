#ifndef GRAF_H
#define GRAF_H



#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef enum ReaderState
{
    START,
    NODE_1, NODE_2,
    VALUE,
} readerState;

void ReadGrafs();

#endif