#ifndef NODE_H
#define NODE_H



#include "edge.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_EDGES 4

struct edge_item;


typedef struct node_item{
    char name;
    struct edge_item *edge[MAX_EDGES];
    int num_edges;
} node_item;


void init_node(node_item *node_it, char name);
// void graf_insert(graf *graf_it, int *value);
// void graf_delete_all(graf *graf_it);

typedef struct graf_item{
    node_item *nodes;     // pole uzl 
    int size;   
}graf_item;

void add_edge(graf_item *graf, node_item *node_itm_from, node_item *node_itm_to, int value);
void init_graf(graf_item *graf);
void add_node(graf_item *graf, node_item* node);
bool search_node(graf_item *graf, node_item *node);
node_item* find_node(graf_item *graf, char name); 
void delete_graf(graf_item *graf);

#endif




