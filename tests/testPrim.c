#include "../include/Prim.h"
#include <time.h>



int main(int argc, char** argv){
    if(argc !=2) { 
        printf("Erreur nombre de paramètres\n");  exit(EXIT_FAILURE);
    } 
    int cl;
    graph_t* graphe = OpenFile(argv[1]);
    printf("Pour le graphe %s  on a:\n",argv[1]);
    cl = clock();
    listedge_t acm=Prim(0,*graphe);
    cl = clock()-cl;
    printf("Temps mesure en secondes: %lf\n",cl/(double)CLOCKS_PER_SEC);
    
    detruire_graphe_prim(graphe);
    supprimer_liste(acm);
}




