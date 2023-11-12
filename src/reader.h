#ifndef READER_H
#define READER_H



#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef enum ReaderState
{
    START,
    NODE_1, NODE_2,
    VALUE,
    END
} readerState;

void ReadGrafs();

#endif