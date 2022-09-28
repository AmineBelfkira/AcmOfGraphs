#ifndef GRAPHE_H
#define GRAPHE_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "sommet.h"


// Type graphe :
typedef struct {
    int size_vertices;  // nombre de sommets
    int size_egdes;     // nombre d’arcs
    vertex_t* data;     // tableau des sommets, alloue dynamiquement
} graph_t;


graph_t* initialisation_graphe(int nb_sommet,int nb_arc);

void detruire_graphe(graph_t* p_graph);

void detruire_graphe_prim(graph_t* p_graph);

#endif