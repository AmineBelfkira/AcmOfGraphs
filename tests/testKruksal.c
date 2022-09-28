#include "../include/Kruksal.h"
#include "../include/LectureFichier.h"


int main(int argc, char** argv){ 
    if(argc !=2) { 
        printf("Erreur nombre de paramètres\n");  exit(EXIT_FAILURE);
    } 
 
    graph_t* p = OpenFile2(argv[1]);
    int cl;
    
    printf("Pour le graphe %s  on a:\n",argv[1]);
    
    cl=clock();

    listedge_t acm=kruskal(*p);
    
    cl = clock()-cl;

    supprimer_liste(acm);
    printf("Temps mesure en secondes: %lf\n",cl/(double)CLOCKS_PER_SEC);
    detruire_graphe(p);
}
