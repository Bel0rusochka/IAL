#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "edge.h"

typedef struct listElement{
	edge_item edge;
	struct listElement *previousElement;
	struct listElement *nextElement;
} *listElementPtr;


typedef struct {
	listElementPtr firstElement;
	listElementPtr activeElement;
	listElementPtr lastElement;
} list;

void init_list(list * lst);

void freeList(list * lst);

void insertLast_list(list *lst, edge_item edge );

void setFirstActive_list(list *lst);

edge_item getFirstEdge_list(list *lst);

void deleActiveItem_list(list *lst);

void deleteEdgeFromList(list *lst, const edge_item *edgeToDelete);

edge_item getActiveEdge_list(list *lst);

void next_list(list *lst);

void previos_list(list *lst);

void printList(list *lst);
#endif