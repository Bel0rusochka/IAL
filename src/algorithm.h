#ifndef ALGORITHM_H
#define ALGORITHM_H

#include <limits.h>
#include <stdio.h> 
#include <stdlib.h>
#include <time.h>
#include "edge.h"
#include "list.h"
#include "set.h"
#include "node.h"

void start_algorithm(graf_item graf);
void algorithm_step(list *listAvailableEdge, CharSet* set,list *queueProcesEdge,graf_item *graf);

#endif