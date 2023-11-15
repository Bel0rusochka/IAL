#include "reader.h"

//Implementation of the reader.h header file

// State for negative number
bool is_negative = false;

// Function for checking if char is digit
bool is_digit(char ch) {
    return (ch >= '0' && ch <= '9');
}

void ReadGraf(graf_item *graf, node_item **nodesArray, size_t *nodesCount, char *file_path) {

    //Opening file for reading
    FILE *ptr;
    ptr = fopen(file_path, "r");

    //Checking if file was opened successfully
    if (NULL == ptr) {
        fprintf(stderr, "Error: File can't be opened \n");
        exit(1);
    }

    //Initializing variables for new nodes
    node_item *new_node_from = NULL;
    node_item *new_node_to = NULL;

    //Initializing variables for value of edge between nodes and variable for name of node represented as char
    char tmp_char;
    int value = 0;

    //Initializing state of the reader
    readerState state = START;
    char ch = fgetc(ptr);

    while (ch != EOF) {

        if (state == START && ch == '(') {
            //Allocating memory for new nodes
            new_node_from = (node_item *) malloc(sizeof(node_item));
            new_node_to = (node_item *) malloc(sizeof(node_item));
            if (new_node_from == NULL || new_node_to == NULL) {
                fprintf(stderr, "Error: Memory allocation failed\n");
                exit(2);
            }

            state = NODE_1;
        } else if (state == NODE_1) {
            //From format of edges we know that node name is one char, after that we have comma, so we can add node to graph after reading comma
            if (ch != ',') {
                tmp_char = ch;
            } else {
                init_node(new_node_from, tmp_char);
                add_node(graf, new_node_from);
                nodesArray[(*nodesCount)++] = new_node_from;
                state = NODE_2;
            }
        } else if (state == NODE_2) {
            //The same as in NODE_1
            if (ch != ',') {
                tmp_char = ch;
            } else {
                init_node(new_node_to, tmp_char);
                add_node(graf, new_node_to);
                nodesArray[(*nodesCount)++] = new_node_to;
                state = VALUE;
            }
        } else if (state == VALUE && ch != ',') {
            if (ch == '-') {
                is_negative = true;
            }
            //Reading value of edge between nodes, and adding scraped edges to node_from and node_to(we have to add edge in both directions) after reading closing bracket
            if (is_digit(ch)){
                value = 10 * value + (is_negative ? -1 : 1) * (ch - '0');
                is_negative = false;  // Reset the flag
            }else if (ch == ')'){
                // if the edge was already declared, throw an error
                for (int i = 0; i < graf->nodes->num_edges; i++) {
                    char edge_from = graf->nodes->edge[i]->node_from->name;
                    char edge_to = graf->nodes->edge[i]->node_to->name;

                    if ((edge_from == new_node_from->name && edge_to == new_node_to->name) || (edge_from == new_node_to->name && edge_to == new_node_from->name)){
                        fprintf(stderr, "Error: Edge between %c and %c was already declared\n", new_node_from->name,
                                new_node_to->name);
                        exit(6);
                    }
                }

                add_edge(graf, new_node_from, new_node_to, value);
                add_edge(graf, new_node_to, new_node_from, value);
                state = END;
                value = 0;
            }else if (ch != '-'){
                //If we have incorrect format of graph in file, we exit program with error
                fprintf(stderr, "Error: Incorrect graph format in the .txt file\n");
                exit(5);
            }

        } else if (state == END && ch == ',') {
            state = START;
        } else {
            //If we have incorrect format of graph in file, we exit program with error
            fprintf(stderr, "Error: Incorrect graph format in the .txt file\n");
            exit(5);
        }
        ch = fgetc(ptr);

    }

    fclose(ptr);
}
