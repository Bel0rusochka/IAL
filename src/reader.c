#include "reader.h"
#include "edge.h"
#include "node.h"
#include "algorithm.h"
#define MAX_NODES 512

void ReadGrafs() {

    FILE* ptr;
    ptr = fopen("./grafs/graf_2.txt", "r");

    if (NULL == ptr) {
        fprintf(stderr, "Error: File can't be opened \n");
        exit(1);
    }

    char ch = fgetc(ptr);

    graf_item graf;
    init_graf(&graf);
    node_item *new_node_from = NULL;
    node_item *new_node_to = NULL;

    node_item *nodesArray[MAX_NODES];
    int nodesCount = 0;


    int value =0;

    readerState state = START;
    while (ch != EOF){
        if(ch=='('){
            new_node_from = (node_item *)malloc(sizeof(node_item));
            new_node_to = (node_item *)malloc(sizeof(node_item));
            if (new_node_from == NULL || new_node_to == NULL) {
                fprintf(stderr, "Error: Memory allocation failed\n");
                exit(2);
            }
            state = START;
        }else if(state == START && ch!=','){
            init_node(new_node_from, ch);
            add_node(&graf, new_node_from);
            nodesArray[nodesCount++] = new_node_from; 
            state = NODE_1;
        }else if(state == NODE_1 && ch!=','){
            
            init_node(new_node_to, ch);
            add_node(&graf, new_node_to);
            nodesArray[nodesCount++] = new_node_to;
            state = NODE_2;
        }else if(state == NODE_2 && ch!=','){
            if(ch!=')'){
                value =10 * value + (ch - '0');
            }else{
                add_edge(&graf, new_node_from, new_node_to, value);
                add_edge(&graf, new_node_to, new_node_from, value);
                state = VALUE;
                value =0;
            }
            
            
            
        }
        ch = fgetc(ptr);

    }
    
    fclose(ptr);


    start_algorithm(graf);
    for (int i = 0; i < nodesCount; ++i){
        free(nodesArray[i]);
    }
    delete_graf(&graf);
}
