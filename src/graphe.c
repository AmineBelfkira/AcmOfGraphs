#include "../include/graphe.h"



graph_t* initialisation_graphe(int nb_sommet,int nb_arc){
    graph_t* p_graph = calloc(1,sizeof(*p_graph));
    if (p_graph==NULL) { printf("Probleme d'allocation\n"); exit(EXIT_FAILURE);}
    p_graph->size_egdes = nb_arc;
    p_graph->size_vertices = nb_sommet;
    p_graph->data = calloc( nb_sommet , sizeof( *(p_graph->data) ) );
    if (p_graph->data==NULL) {free(p_graph); printf("Probleme d'allocation\n"); exit(EXIT_FAILURE);}
    
    return p_graph;
}

//libre notre structure graphe 
void detruire_graphe(graph_t* p_graph){
    for (int i=0 ; i<p_graph->size_vertices ; i++){
        supprime_sommet(&p_graph->data[i]);
    }
    free(p_graph->data);
    free(p_graph);
}

//la liberation pour prim utilise la liberation du sommet primS
void detruire_graphe_prim(graph_t* p_graph){
    for (int i=0 ; i<p_graph->size_vertices ; i++) supprime_sommet_prim(&p_graph->data[i]);
    free(p_graph->data);
    free(p_graph);
}


