#include "reader.h"
#include "edge.h"
#include "node.h"
#include "algorithm.h"


void ReadGrafs() {

    FILE* ptr;
    ptr = fopen("./grafs/graf_1.txt", "r");

    if (NULL == ptr) {
        fprintf(stderr, "File can't be opened \n");
        exit(1);
    }

    char ch = fgetc(ptr);

    graf_item graf;
    init_graf(&graf);
    node_item *new_node_from = NULL;
    node_item *new_node_to = NULL;
    readerState state = START;
    while (ch != EOF){
        if(ch=='('){
            new_node_from = (node_item *)malloc(sizeof(node_item));
            new_node_to = (node_item *)malloc(sizeof(node_item));
            state = START;
        }else if(state == START && ch!=','){
            init_node(new_node_from, ch);
            add_node(&graf, new_node_from);
            state = NODE_1;
        }else if(state == NODE_1 && ch!=','){
            
            init_node(new_node_to, ch);
            add_node(&graf, new_node_to);
            state = NODE_2;
        }else if(state == NODE_2 && ch!=','){
            
            int value = ch - '0';
            add_edge(&graf, new_node_from, new_node_to, value);
            add_edge(&graf, new_node_to, new_node_from, value);
            state = VALUE;
            new_node_from = NULL;
            new_node_to = NULL;
        }
        ch = fgetc(ptr);

    }
    

    free(new_node_from);
    free(new_node_to);
    fclose(ptr);
    start_algorithm(graf);
    // for(int i = 0; i<graf.size; i++){
        
    //     for(int j = 0; j<graf.nodes[i].num_edges; j++){
    //         printf("From %c to %c for %i\n",graf.nodes[i].edge[j]->node_from->name,graf.nodes[i].edge[j]->node_to->name, graf.nodes[i].edge[j]->value);
    //     }

    // }

    delete_graf(&graf);
}