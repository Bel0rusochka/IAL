#include "algorithm.h" 

//Implementation of the algorithm.h header file

void algorithm_step(list *listAvailableEdge, CharSet* set, list *queueProcesEdge, graf_item *graf){

    //Initializing edge with minimum value, but for first iteration we need to initialize it with maximum value to find minimum edge
    edge_item min_edge1;
    init_edge(&min_edge1, INT_MAX, NULL, NULL);
    
    setFirstActive_list(listAvailableEdge);

    /*
    Finding minimum edge in the list of available edges and checking if node_to of this edge is in the set of nodes that have not yet been processed.
    When we find minimum edge, we need to change min_edge1.value to value of this edge and min_edge1 to this edge.
    */
    while (listAvailableEdge->activeElement != NULL){
        edge_item edge = getActiveEdge_list(listAvailableEdge);
        if(edge.value < min_edge1.value && containsInSet(set, edge.node_to->name)){
            
            min_edge1.value = getActiveEdge_list(listAvailableEdge).value;
            min_edge1 = getActiveEdge_list(listAvailableEdge);
        }
        next_list(listAvailableEdge);
    }

    /*
    The implementation of adding edges from the new processed node to the list of available edges.
    min_edge1.node_to have the name of the new processed node, but not all the edges from this node, 
    so we need to find this node in the graph, and take everything from him.
    */
    node_item *node_tmp = get_node(graf,min_edge1.node_to->name);
    for(int i =0; i<node_tmp->num_edges; i++){
        insertLast_list(listAvailableEdge, *node_tmp->edge[i]);
    }

    //Removing new processed node from the set of nodes
    removeFromSet(set, min_edge1.node_to->name);
    //Removing find minimum edge from the list of available edges
    deleteEdgeFromList(listAvailableEdge, &min_edge1);

    //Initializing edge which is opposite to min_edge1, because that edge is the same edge, but in opposite direction
    edge_item min_edge2;
    init_edge(&min_edge2, min_edge1.value, min_edge1.node_to, min_edge1.node_from);
    deleteEdgeFromList(listAvailableEdge, &min_edge2);

    //Adding minimum edge to the list of processed edges
    insertLast_list(queueProcesEdge, min_edge1);
}


void start_algorithm(graf_item graf){

    //Choosing random starting node, like in Prim's algorithm
    srand(time(NULL));
    int start_pos = 0+rand()%graf.size;


    //Initializing all necessary data structures like list, set and queue(it is also a list, but it is used like a queue)
    CharSet nodeNameSet;
    initSet(&nodeNameSet, graf.size);

    list queueProcesEdge;
    init_list(&queueProcesEdge);

    list listAvailableEdge;
    init_list(&listAvailableEdge);

    //Adding all nodes to the set of nodes that have not yet been processed
    for(int i =0; i<graf.size; i++){
        addToSet(&nodeNameSet,graf.nodes[i].name);
    }
    
    //Removing start node from the set of nodes that have not yet been processed
    printf("Start node: %c\n", graf.nodes[start_pos].name);
    removeFromSet(&nodeNameSet, graf.nodes[start_pos].name);

    //Adding all edges from start node to the list of available edges
    for(int i =0; i<graf.nodes[start_pos].num_edges; i++){
        insertLast_list(&listAvailableEdge, *graf.nodes[start_pos].edge[i]);
    }
    
    //Starting the algorithm of finding the shortest paths in the graph and outputting the result to the consol(implemented special function for this)
    printf("1)_______________\n");
    printList(&queueProcesEdge);
    printSet(&nodeNameSet);
    for(int i =2; nodeNameSet.size!=0;i++){
        //Algorithm implemeted step by step
        algorithm_step(&listAvailableEdge, &nodeNameSet, &queueProcesEdge, &graf);
        printf("%i)_______________\n", i);
        printList(&queueProcesEdge);
        printSet(&nodeNameSet);
    }

    //Freeing memory allocated for data structures
    freeList(&listAvailableEdge);
    freeList(&queueProcesEdge);
    freeSet(&nodeNameSet);
}
