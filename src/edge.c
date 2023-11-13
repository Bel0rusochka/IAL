#include "edge.h"


void init_edge(edge_item* edge,int value, node_item *node_from, node_item *node_to){
    edge->value = value;
    edge->node_from= node_from;
    edge->node_to= node_to;
    
}


