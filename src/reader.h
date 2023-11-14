#ifndef READER_H
#define READER_H

#include <stdio.h>
#include <stdlib.h>
#include "edge.h"
#include "node.h"
#include "algorithm.h"

typedef enum ReaderState
{
    START,
    NODE_1, NODE_2,
    VALUE,
    END
} readerState;
void ReadGraf(graf_item *graf, node_item **nodesArray, size_t *nodesCount, char* file_path);
#endif