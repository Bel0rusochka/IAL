#include "reader.h"

#define MAX_NODES 512


int main(int argc, char *argv[]){

    char *file_path = NULL;
    if(argc != 2){
        file_path = "./grafs/graf_1.txt";
        printf("You didn't specify the path to the file, so the default path was selected: %s\n", file_path);
    }else{
        file_path  = argv[1];
    }

    graf_item graf;
    init_graf(&graf);

    node_item *nodesArray[MAX_NODES];
    size_t nodesCount = 0;

    ReadGraf(&graf, nodesArray, &nodesCount, file_path);

    start_algorithm(graf);

    delete_graf(&graf);
    for (int i = 0; i < nodesCount; ++i){
        free(nodesArray[i]);
    }

    return 0;
}