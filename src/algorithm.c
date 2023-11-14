#include "algorithm.h" 

void algorithm_step(list *listAvailableEdge, CharSet* set, list *queueProcesEdge, graf_item *graf){
    edge_item min_edge1;
    init_edge(&min_edge1, INT_MAX, NULL, NULL);

    setFirstActive_list(listAvailableEdge);

    while (listAvailableEdge->activeElement != NULL){
        edge_item edge = getActiveEdge_list(listAvailableEdge);
        if(edge.value < min_edge1.value && containsInSet(set, edge.node_to->name)){
            
            min_edge1.value = getActiveEdge_list(listAvailableEdge).value;
            min_edge1 = getActiveEdge_list(listAvailableEdge);
        }
        next_list(listAvailableEdge);
    }


    node_item *node_tmp = get_node(graf,min_edge1.node_to->name);
    for(int i =0; i<node_tmp->num_edges; i++){
        insertLast_list(listAvailableEdge, *node_tmp->edge[i]);
    }
    removeFromSet(set, min_edge1.node_to->name);
    deleteEdgeFromList(listAvailableEdge, &min_edge1);

    edge_item min_edge2;
    init_edge(&min_edge2, min_edge1.value, min_edge1.node_to, min_edge1.node_from);

    deleteEdgeFromList(listAvailableEdge, &min_edge2);

    insertLast_list(queueProcesEdge, min_edge1);
    
}



void start_algorithm(graf_item graf){
    srand(time(NULL));
    int start_pos = 0+rand()%graf.size;

    CharSet nodeNameSet;
    initSet(&nodeNameSet, graf.size);

    list queueProcesEdge;
    init_list(&queueProcesEdge);

    list listAvailableEdge;
    init_list(&listAvailableEdge);


    for(int i =0; i<graf.size; i++){
        addToSet(&nodeNameSet,graf.nodes[i].name);
    }
    removeFromSet(&nodeNameSet, graf.nodes[start_pos].name);

    
    for(int i =0; i<graf.nodes[start_pos].num_edges; i++){
        insertLast_list(&listAvailableEdge, *graf.nodes[start_pos].edge[i]);
    }
    

    while (nodeNameSet.size!=0){
        algorithm_step(&listAvailableEdge, &nodeNameSet, &queueProcesEdge, &graf);
    }
    
    printList(&queueProcesEdge);

    freeList(&listAvailableEdge);
    freeList(&queueProcesEdge);
    freeSet(&nodeNameSet);
}