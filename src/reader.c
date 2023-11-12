#include "reader.h"

void ReadGrafs() {

    FILE* ptr;
    ptr = fopen("./grafs/graf_1.txt", "r");

    if (NULL == ptr) {
        fprintf(stderr, "File can't be opened \n");
        exit(1);
    }

    char ch = fgetc(ptr);
    readerState state = START;
    while (ch != EOF){
        if(ch=='('){
            state = START;
        }else if(state == START && ch!=','){
            printf("Node 1: %c; ", ch);
            state = NODE_1;
        }else if(state == NODE_1 && ch!=','){
            printf("Node 2: %c; ", ch);
            state = NODE_2;
        }else if(state == NODE_2 && ch!=','){
            printf("Value: %c;\n", ch);
            state = VALUE;
        }
        ch = fgetc(ptr);
    }

    fclose(ptr);
}