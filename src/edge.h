#ifndef EDGE_H
#define EDGE_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "node.h"

//Temporary struct for node
struct node_item;

//Struct for edge, contains node_from - node where edge starts, node_to - node where edge ends, value - value of edge
typedef struct edge_item{
    int value;
    struct node_item *node_from;
    struct node_item *node_to;
}edge_item;

/**
 * @brief Function for creating edge
 * 
 * @param edge Pointer to edge
 * @param value Value of edge
 * @param node_from Pointer to node where edge starts
 * @param node_to Pointer to node where edge ends
*/
void init_edge(edge_item* edge, int value,  struct node_item *node_from, struct node_item *node_to);

#endif
