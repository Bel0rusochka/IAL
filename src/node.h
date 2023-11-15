#ifndef NODE_H
#define NODE_H




#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "edge.h"


#define MAX_EDGES 5

struct edge_item;

//Struct for node, contains name of node(char), array of edges and number of edges. Max number of edges is 5.
typedef struct node_item{
    char name;
    struct edge_item *edge[MAX_EDGES];
    int num_edges;
} node_item;

/**
 * @brief Function for initializing the node.
 * 
 * @param node_it Pointer to the node to be initialized.
 * @param name Name of the node.
*/
void init_node(node_item *node_it, char name);

//Struct for graph, contains array of nodes and size of array.
typedef struct graf_item{
    node_item *nodes; 
    int size;   
}graf_item;

/**
 * @brief Function for initializing the graph.
 * 
 * @param graf Pointer to the graph to be initialized.
*/
void init_graf(graf_item *graf);

/**
 * @brief Function for unite node_from with edge to node_to with value.
 * 
 * @param graf Pointer to the graph.
 * @param node_itm_from Pointer to the node_from, where edge will be unite. This node must be in the graph, otherwise the program will exit with an error.
 * @param node_itm_to Pointer to the node_to, this node wil be added to the edge.
 * @param value Value of the edge.
*/
void add_edge(graf_item *graf, node_item *node_itm_from, node_item *node_itm_to, int value);

/**
 * @brief Function for adding node to the graph.
 * 
 * @param graf Pointer to the graph.
 * @param node Pointer to the node to be added.
*/
void add_node(graf_item *graf, node_item* node);

/**
 * @brief Function for searching node in the graph.
 * 
 * @param graf Pointer to the graph.
 * @param node Pointer to the node to be searched.
 * @return true If the node is in the graph.
 * @return false If the node is not in the graph.
*/
bool search_node(graf_item *graf, node_item *node);

/**
 * @brief Function for getting node from the graph.
 * 
 * @param graf Pointer to the graph.
 * @param name Name of the node to be searched.
 * @return node_item* Pointer to the node.
*/
node_item* get_node(graf_item *graf, char name);

/**
 * @brief Function for deleting the graph.
 * 
 * @param graf Pointer to the graph to be deleted.
*/
void delete_graf(graf_item *graf);

#endif




