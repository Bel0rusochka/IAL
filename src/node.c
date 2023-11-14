#include "node.h"

void init_graf(graf_item *graf){
    graf->size=0;
    graf->nodes = NULL;
}

bool search_node(graf_item *graf, node_item *node){
    int size = 0;
    while(size != graf->size){
        if(graf->nodes[size].name == node->name){
            return true;
        }
        size++;
    }
    return false;
}

void add_node(graf_item *graf, node_item* node){
    if (!search_node(graf, node)){
        graf->size++;
        graf->nodes = realloc(graf->nodes, graf->size * sizeof(node_item));
        graf->nodes[graf->size - 1] = *node;
    }
}

void init_node(node_item *node_itm, char name){
    node_itm->name = name;
    node_itm->num_edges = 0;
}

node_item* get_node(graf_item *graf, char name) {
    for (int i = 0; i < graf->size; i++){
        if (graf->nodes[i].name == name){
            return &graf->nodes[i];
        }
    }
    
    return NULL; 
}

void add_edge(graf_item *graf, node_item *node_itm_from, node_item *node_itm_to,int value ){

    node_item *tmp = get_node(graf, node_itm_from->name);
    if(tmp==NULL){
        fprintf(stderr,"Error: Using an uninitialized variable\n");
        exit(3);
    }
    
    if (tmp->num_edges < MAX_EDGES) {
        edge_item *new_edge = (edge_item *)malloc(sizeof(edge_item));
        new_edge->node_from = node_itm_from;
        new_edge->node_to = node_itm_to;
        
        new_edge->value = value;
        tmp->edge[tmp->num_edges] = new_edge;
        tmp->num_edges++;

    }else{
        fprintf(stderr,"Error: Node has reached the maximum number of edges\n");
        exit(4);
    }
}


void delete_graf(graf_item *graf){
    for (int i = 0; i < graf->size; ++i) {
        for (int j = 0; j < graf->nodes[i].num_edges; ++j) {
            free(graf->nodes[i].edge[j]);
        }
    }

    free(graf->nodes);
    graf->size = 0;
}