#ifndef LIST_H
#define LIST_H

/*
For reference was used homwork #1 from subject IAL.
The list can be used as a queue, thanks to the functionality. 
This was done to reduce the number of lines of code.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "edge.h"




//Strukture representing element of list. Each element has pointer to previous and next element and edge_item variable.
typedef struct listElement{
	edge_item edge;
	struct listElement *previousElement;
	struct listElement *nextElement;
} *listElementPtr;


//Strukture representing list. Each list has pointer to first, active and last element.
typedef struct {
	listElementPtr firstElement;
	listElementPtr activeElement;
	listElementPtr lastElement;
} list;


/**
 * @brief      Inicialize list
 * 
 * @param      lst   Pointer to list which will be inicialized
*/
void init_list(list * lst);

/**
 * @brief      Free inicialized list
 * 
 * @param      lst   Pointer to list which will be freed
*/
void freeList(list * lst);

/**
 * @brief      Insert new element to list on last position
 * 
 * @param      lst   Pointer to list where will be inserted new element
 * @param	   edge  Edge which will be inserted to list
*/
void insertLast_list(list *lst, edge_item edge );

/**
 * @brief      Set first element of list as active
 * 
 * @param      lst   Pointer to list where will be set first element as active
*/
void setFirstActive_list(list *lst);


/**
 * @brief      Get first element of list
 * 
 * @param      	lst   Pointer to list where will be get first element
 * @return	 	edege_item  from first element of list
*/
edge_item getFirstEdge_list(list *lst);

/**
 * @brief      Delete active element from list
 * 
 * @param      lst   Pointer to list where will be deleted active element
*/
void deleActiveItem_list(list *lst);


/**
 * @brief      Delete element from list by edge
 * 
 * @param      	lst   Pointer to list where will be deleted element
 * @param		edgeToDelete  edge_item which will determine which element from list will be deleted
 */
void deleteEdgeFromList(list *lst, const edge_item *edgeToDelete);

/**
 * @brief      Get active element from list
 * 
 * @param      	lst   Pointer to list where will be get active element
 * @return		edege_item  from active element of list
 */
edge_item getActiveEdge_list(list *lst);

/**
 * @brief      Set next element of list as active
 * 
 * @param      lst   Pointer to list where will be set next element as active
*/
void next_list(list *lst);

/**
 * @brief      Print list to console
 * 
 * @param      lst   Pointer to list which will be printed
*/
void printList(list *lst);
#endif
