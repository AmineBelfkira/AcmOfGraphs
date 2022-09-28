#ifndef ARC_H
#define ARC_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

// Type arc
typedef struct {
    int depart;     // L’indice du sommet de départ de l’arc
    int arrivee;    // L’indice du sommet d’arrivée de l’arc
    double cout;    // Le cout (distance) de l’arc
} edge_t;



edge_t* initialisation_edge(int depart ,int arrivee,double cout);
void afficheArc(edge_t* p);
bool same(edge_t* p,edge_t* q);
void supprime_arc(edge_t* u);

#endif