#ifndef SOMMET_H
#define SOMMET_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#define INFINI LONG_MAX
#include "liste.h"



typedef struct {
    char* nom;
    double x,y;
    listedge_t edges;
    double cout;
    edge_t* edge_previous;
} vertex_t;




vertex_t* initialisation_Sommet_Vide();

void supprime_sommet(vertex_t* u);

void supprime_sommet_prim(vertex_t* u);



#endif
