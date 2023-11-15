#include "reader.h"

#define MAX_NODES 512

/*
Main function of the program. The program takes the path to the file as an argument.
If the path is not specified, the default path is selected like "./graphs/graph_1.txt".
The program reads the graph from the file, then starts the algorithm of finding the shortest paths in the graph,
and then outputs the result to the console.
At the end of the program, the memory allocated for the graph is freed.
*/
int main(int argc, char *argv[]){

    //Parsing arguments
    char *file_path = NULL;
    if(argc != 2){
        file_path = "./graphs/graph_1.txt";
        printf("You didn't specify the path to the file, so the default path was selected: %s\n", file_path);
    }else{
        file_path  = argv[1];
    }

    //Allocating memory for the graph
    graf_item graf;
    init_graf(&graf);

    /*
    Allocating memory for the array of nodes. At the end of the program,
    the memory allocated for the array of nodes is freed. 
    It is necessary to avoid memory leaks.
    */
    node_item *nodesArray[MAX_NODES];
    size_t nodesCount = 0;

    //Reading the graph from the file
    ReadGraf(&graf, nodesArray, &nodesCount, file_path);

    //Starting the algorithm of finding the shortest paths in the graph and outputting the result to the console
    start_algorithm(graf);

    //Freeing memory
    delete_graf(&graf);
    for (int i = 0; i < nodesCount; ++i){
        free(nodesArray[i]);
    }

    return 0;
}
