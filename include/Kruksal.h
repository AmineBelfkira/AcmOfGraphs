#ifndef KRUKSAL_H
#define KRUKSAL_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "graphe.h"
#include "tri.h"

typedef struct  {
    int parent;
    int rang;
} ensemble;


int find( ensemble* tab, int i);
void ensemble_union(ensemble* tab, int i, int j);
listedge_t kruskal(graph_t graphe);

#endif