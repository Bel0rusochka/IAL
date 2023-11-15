#include "list.h"

//Implementation of the list.h header file

void init_list(list *lst){
	lst -> firstElement = NULL;
	lst -> activeElement = NULL;
	lst -> lastElement = NULL;
}


void freeList(list *lst){
	listElementPtr tmp = lst -> firstElement;
	while (tmp != NULL) {
		lst -> firstElement = tmp -> nextElement;
		free(tmp);
		tmp = lst -> firstElement;
	}
	lst -> lastElement = NULL;
	lst -> activeElement = NULL;
}


void insertLast_list(list *lst, edge_item edge){
	listElementPtr newElement =  malloc(sizeof(struct listElement));
	if (newElement == NULL) {
		fprintf(stderr, "Error: Memory allocation failed\n");
        exit(2);
	}
		
	newElement -> edge = edge; 
	newElement -> previousElement = lst -> lastElement; 
	newElement -> nextElement = NULL;
	if (lst -> lastElement != NULL) {
		lst -> lastElement -> nextElement = newElement;
	}else{
		lst -> firstElement = newElement;
	}
	lst -> lastElement = newElement;
	
	
}


void setFirstActive_list(list *lst){
	if (lst -> firstElement != NULL) {
		lst -> activeElement = lst -> firstElement;
	}
}


edge_item getFirstEdge_list(list *lst) {
	if (lst -> firstElement != NULL) {
		return lst -> firstElement -> edge;
	}else{
		fprintf(stderr, "Error: The first element was not found\n");
    	exit(4);
	}
}


void deleActiveItem_list(list *lst) {
    if (lst->activeElement != NULL) {
        listElementPtr nextElement = lst->activeElement->nextElement;
        listElementPtr previousElement = lst->activeElement->previousElement;

        free(lst->activeElement);

        if (previousElement != NULL) {
            previousElement->nextElement = nextElement;
        } else {
            lst->firstElement = nextElement;
        }

        if (nextElement != NULL) {
            nextElement->previousElement = previousElement;
            lst->activeElement = nextElement;
        } else {
            lst->lastElement = previousElement;
            lst->activeElement = NULL; 
        }
    }
}


void deleteEdgeFromList(list *lst, const edge_item *edgeToDelete){
    setFirstActive_list(lst);

    while (lst->activeElement != NULL){
        edge_item edge = getActiveEdge_list(lst);
        if (edge.value == edgeToDelete->value && edge.node_to->name == edgeToDelete->node_to->name) {
            deleActiveItem_list(lst);
            break;
        }
        next_list(lst);
    }
}


edge_item getActiveEdge_list(list *lst) {
	if (lst -> activeElement != NULL) {
		return lst -> activeElement -> edge;
	}else{
		fprintf(stderr, "Error: The active element was not found\n");
    	exit(4);
	}
}


void next_list(list *lst){
	if (lst -> activeElement != NULL) {
		lst -> activeElement = lst -> activeElement -> nextElement;
	}
}


void printList(list *lst) {
    listElementPtr currentElement = lst->firstElement;

    printf("List of steps:\n");
    while (currentElement != NULL) {
        printf("From node %c to node %c for %i;\n",currentElement->edge.node_from->name, currentElement->edge.node_to->name, currentElement->edge.value);
        currentElement = currentElement->nextElement;
    }
}
