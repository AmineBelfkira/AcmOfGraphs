#ifndef LISTE_H
#define LISTE_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#include "arc.h"



      //DEFINITION DE NOTRE STRUCTURE:

typedef struct maillon_edge {
    edge_t val;
    // ou edge t* val, suivant votre choix : liste d’arcs ou de pointeurs d’arcs
    struct maillon_edge * next;
}* listedge_t;




void affichage(listedge_t l);
listedge_t initialistion_liste_vide();
void insere_tete(edge_t* valeur, listedge_t* pl);
void tri_insertion(listedge_t pl);
void supprimer_liste(listedge_t l);
bool same_liste(listedge_t l1 , listedge_t l2);

#endif











