#include "list.h"



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
		fprintf(stderr, "Error\n");
        exit(3);
	}else{
		
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
		fprintf(stderr, "Error\n");
        exit(3);
	}
}

void deleActiveItem_list(list *lst) {
    if (lst->activeElement != NULL) {
        listElementPtr nextElement = lst->activeElement->nextElement;
        listElementPtr previousElement = lst->activeElement->previousElement;

        // Удаление активного элемента
        free(lst->activeElement);

        // Обновление указателей
        if (previousElement != NULL) {
            previousElement->nextElement = nextElement;
        } else {
            // Если активный элемент был первым
            lst->firstElement = nextElement;
        }

        if (nextElement != NULL) {
            nextElement->previousElement = previousElement;
            lst->activeElement = nextElement;  // Установка следующего элемента активным
        } else {
            // Если активный элемент был последним
            lst->lastElement = previousElement;
            lst->activeElement = NULL;  // Список пуст
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
		fprintf(stderr, "Error\n");
        exit(3);
	}
}



void next_list(list *lst){
	if (lst -> activeElement != NULL) {
		lst -> activeElement = lst -> activeElement -> nextElement;
	}
}



void previos_list(list *lst){
	if (lst -> activeElement != NULL) {
		lst -> activeElement = lst -> activeElement -> previousElement;
	}
}

void printList(list *lst) {
    listElementPtr currentElement = lst->firstElement;

    printf("List: ");
    while (currentElement != NULL) {
        // В предположении, что у edge_item есть свойство value
        printf("From %c to %c for %i; ",currentElement->edge.node_from->name, currentElement->edge.node_to->name, currentElement->edge.value);
        currentElement = currentElement->nextElement;
    }
    printf("\n");
}