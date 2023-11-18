#ifndef READER_H
#define READER_H

#include <stdio.h>
#include <stdlib.h>
#include "edge.h"
#include "node.h"
#include "algorithm.h"


//Enum for representing the state of the reader(parse) from the file.
typedef enum ReaderState
{
    START,
    NODE_1, NODE_2,
    VALUE,
    END
} readerState;

/**
 *
 * @param ch
 * @return true or false
 */
bool is_digit(char ch);

/**
 * @brief Function for reading node from file, and adding it to the graph. In file we have representation of edges in format: (node_from, node_to,value).
 * 
 * @param graf Pointer to the graph
 * @param nodesArray Array of nodes, which is used for freeing memory at the end of the program
 * @param nodesCount Number of nodes in the nodesArray
 * @param file_path Path to the file with graph
 * */
void ReadGraf(graf_item *graf, node_item **nodesArray, size_t *nodesCount, char* file_path);
#endif
