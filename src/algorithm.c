#include "algorithm.h" 

void get_min_edge(list *listAvailableEdge, CharSet* set, list *queueProcesEdge, graf_item *graf){
    edge_item min_edge;
    int min_value = 999999;

    setFirstActive_list(listAvailableEdge);

    while (listAvailableEdge->activeElement != NULL){
        edge_item edge = getActiveEdge_list(listAvailableEdge);
        if(edge.value < min_value && containsInSet(set, edge.node_to->name)){
            
            min_value = getActiveEdge_list(listAvailableEdge).value;
            min_edge = getActiveEdge_list(listAvailableEdge);
        }
        next_list(listAvailableEdge);
    }


    node_item *node_tmp = get_node(graf,min_edge.node_to->name);
    for(int i =0; i<node_tmp->num_edges; i++){
        insertLast_list(listAvailableEdge, *node_tmp->edge[i]);
    }

    removeFromSet(set, min_edge.node_to->name);
    deleteEdgeFromList(listAvailableEdge, &min_edge);
    edge_item min_edge2;
    init_edge(&min_edge2, min_edge.value, min_edge.node_to, min_edge.node_from);
    deleteEdgeFromList(listAvailableEdge, &min_edge2);

    insertLast_list(queueProcesEdge, min_edge);
    
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

    printSet(&nodeNameSet);
    
    for(int i =0; i<graf.nodes[start_pos].num_edges; i++){
        insertLast_list(&listAvailableEdge, *graf.nodes[start_pos].edge[i]);
    }
    printList(&listAvailableEdge);
    printList(&queueProcesEdge);
    printf("__________________\n");
    while (nodeNameSet.size!=0){
        get_min_edge(&listAvailableEdge, &nodeNameSet, &queueProcesEdge, &graf);
    }
    
    
    //printf("From %c to %c for %i\n",edge.node_from->name,edge.node_to->name,edge.value);
    printList(&listAvailableEdge);
    printList(&queueProcesEdge);

    freeList(&listAvailableEdge);
    freeList(&queueProcesEdge);
    freeSet(&nodeNameSet);
}