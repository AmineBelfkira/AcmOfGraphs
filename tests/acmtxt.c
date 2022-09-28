#include "../include/Kruksal.h"
#include "../include/LectureFichier.h"
#include "../include/Prim.h"


int main(int argc, char** argv){
    if(argc !=4) { 
        printf("Erreur nombre de paramètres\n");  exit(EXIT_FAILURE);
    } 

    if( argv[2][0]=='0' && argv[3][0]=='0' ){
        graph_t* p = OpenFile(argv[1]);
        int cl;
        printf("L'ACM kruksal du graphe %s :",argv[1]);
        cl=clock();
        listedge_t acm=kruskal(*p);
        cl = clock()-cl;
        supprimer_liste(acm);
        printf("Temps mesure en secondes: %lf\n",cl/(double)CLOCKS_PER_SEC);
        detruire_graphe(p);
    }else if(argv[2][0]=='0' && argv[3][0]=='1'){
        graph_t* p = OpenFile(argv[1]);
        int cl;
        printf("L'ACM kruksal du graphe %s :",argv[1]);
        cl=clock();
        listedge_t acm=kruskal(*p);
        cl = clock()-cl;
        affichage(acm);
        supprimer_liste(acm);
        printf("Temps mesure en secondes: %lf\n",cl/(double)CLOCKS_PER_SEC);
        detruire_graphe(p);
    }else if(argv[2][0]=='1' && argv[3][0]=='0'){
        graph_t* graphe = OpenFile(argv[1]);
        printf("L'ACM Prim du graphe %s :",argv[1]);
        listedge_t acm=Prim(0,*graphe);
        detruire_graphe_prim(graphe);
        supprimer_liste(acm);
    }
    else if(argv[2][0]=='1' && argv[3][0]=='1' ){
        graph_t* graphe = OpenFile(argv[1]);
        printf("L'ACM Prim du graphe %s :",argv[1]);
        listedge_t acm=Prim(0,*graphe);
        affichage(acm);
        detruire_graphe_prim(graphe);
        supprimer_liste(acm);
    }else{
        printf("Error: incorrect value\n"); exit(EXIT_FAILURE);
    }
    
}