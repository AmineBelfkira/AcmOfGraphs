#ifndef TAS_H
#define TAS_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "graphe.h"



typedef struct {
  int* data; // Tableau alloué dynamiquement d'éléments
  int capacity;    // Nombre maximal d'éléments
  int size;      // Nombre actuel d'éléments
}heap_t;



heap_t* new_heap(int max_size);

int heap_get_min(heap_t tas);

void switcher(int* a,int* b);

int left_son(int sommet);

int right_son(int sommet);

void heap_delete(heap_t* t);

void heap_add( heap_t* ptas, int newNum, graph_t g );

int supprimer_valeur_de_tas(heap_t* ptas , graph_t graphe);


#endif