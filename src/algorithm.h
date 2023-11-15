#ifndef ALGORITHM_H
#define ALGORITHM_H

#include <limits.h>
#include <stdio.h> 
#include <stdlib.h>
#include <time.h>
#include "edge.h"
#include "list.h"
#include "set.h"
#include "node.h"



/**
 * @brief Function for finding the shortest edge in the graph. Then removes this edge from the list of available edges(in both directions). And also add edges from the new processed node to the list of available edges.
 * 
 * @param listAvailableEdge Pointer to the list of available edges
 * @param set Pointer to the set of nodes that have not yet been processed
 * @param queueProcesEdge Pointer to the list of processed edges
 * @param graf Pointer to the graph
*/
void algorithm_step(list *listAvailableEdge, CharSet* set,list *queueProcesEdge,graf_item *graf);


/**
 * @brief Function implementing the Prim's algorithm for finding the shortest paths in the graph.
 * 
 * @param graf Graph in which we are looking for the shortest paths
*/
void start_algorithm(graf_item graf);

#endif
