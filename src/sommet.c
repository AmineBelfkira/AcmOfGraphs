#include "../include/sommet.h"



vertex_t* initialisation_Sommet_Vide(){
    vertex_t *p=calloc(1,sizeof(*p));

    return p;
}

//On libere notre structure
void supprime_sommet(vertex_t* u){
    free(u->nom);
    supprimer_liste(u->edges);
    free(u->edge_previous);

}
//Un cas particulié lors de la liberation de la mémoire dans la fonction Prim car l'acm rassemble les adresses des arcs dans le graphe
void supprime_sommet_prim(vertex_t* u){
    free(u->nom);
    supprimer_liste(u->edges);
}

