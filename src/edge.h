#ifndef EDGE_H
#define EDGE_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "node.h"

struct node_item;

typedef struct edge_item{
    int value;
    struct node_item *node_from;
    struct node_item *node_to;
}edge_item;


void init_edge(edge_item* edge,int value,  struct node_item *node_from, struct node_item *node_to);

#endif