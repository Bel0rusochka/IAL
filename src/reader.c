#include "reader.h"


void ReadGraf(graf_item *graf, node_item **nodesArray, size_t *nodesCount,char* file_path){

    FILE* ptr;
    ptr = fopen(file_path, "r");

    if (NULL == ptr) {
        fprintf(stderr, "Error: File can't be opened \n");
        exit(1);
    }

    node_item *new_node_from = NULL;
    node_item *new_node_to = NULL;
    char tmp_char;
    int value =0;
    readerState state = START;
    char ch = fgetc(ptr);

    while (ch != EOF){

        if(state==START&& ch=='('){
            new_node_from = (node_item *)malloc(sizeof(node_item));
            new_node_to = (node_item *)malloc(sizeof(node_item));
            if (new_node_from == NULL || new_node_to == NULL) {
                fprintf(stderr, "Error: Memory allocation failed\n");
                exit(2);
            }

            state = NODE_1;
        }else if(state == NODE_1){
            if(ch!=','){
                tmp_char = ch;
            }else{
                init_node(new_node_from, tmp_char);
                add_node(graf, new_node_from);
                nodesArray[(*nodesCount)++] = new_node_from;
                state = NODE_2;
            }
             
        }else if(state == NODE_2){
            if(ch!=','){
                tmp_char = ch;
            }else{
                init_node(new_node_to, tmp_char);
                add_node(graf, new_node_to);
                nodesArray[(*nodesCount)++] = new_node_to;
                state = VALUE;
            }

        }else if(state == VALUE && ch!=','){
            if(ch!=')'){
                value =10 * value + (ch - '0');
            }else{
                add_edge(graf, new_node_from, new_node_to, value);
                add_edge(graf, new_node_to, new_node_from, value);
                state = END;
                value =0;
            }
            
            
            
        }else if(state == END && ch==','){
            state = START;
        }else{
            
            fprintf(stderr, "Error: Incorrect graph format in the .txt file\n");
            exit(5);
        }
        ch = fgetc(ptr);

    }

    fclose(ptr);
}
