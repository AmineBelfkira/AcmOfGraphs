#include "../include/Kruksal.h"


int find(ensemble* tab, int i){
    int n=i;
    while(tab[n].parent != n) {
        n=tab[n].parent;
    }
    return n;
}

void ensemble_union(ensemble* tab, int i, int j){
    int x=find(tab,i);
    int y=find(tab,j);
    if(x==y) return;
    if(tab[x].rang < tab[y].rang){
        tab[x].parent=y;
    }else if(tab[x].rang > tab[y].rang){
        tab[y].parent=x;
    }else{
        tab[y].parent=x;
        tab[x].rang++; //ancêtre supplémentaire 
    }
}


int isCycle(listedge_t ACM, ensemble* tab){
   
    int n=find(tab,ACM->val.arrivee);
    while(ACM != NULL){ 
        int x = find(tab, ACM->val.depart);
        int y = find(tab, ACM->val.arrivee);
        if(x!=n || y!=n) return 1;  //cyclique veut dire qu'il existe un sommet qui n'a pas le même ancetre que les autres
        ACM = ACM->next;
    }
    
    return 0;
}



listedge_t kruskal(graph_t graphe){
    edge_t* Arete=calloc(graphe.size_egdes , sizeof(edge_t)); 
    int j=0;
    double cout=0;
    listedge_t ACM=NULL;
    
    ensemble* tab= calloc(graphe.size_egdes , sizeof(*tab));
    
    //rassemble tout les arcs dans une liste d'arc
    for (int i=0;i<graphe.size_vertices;i++){
        listedge_t p=graphe.data[i].edges;
        while (p!=NULL){
            edge_t v=p->val;
            Arete[j]=v;
            j++;
            p=p->next;
        }  
    }

    //On tri notre liste d'arc
    Arete=trifusion(Arete,graphe.size_egdes);
    
    //initialise notre ensemble 
    for (int i=0; i<graphe.size_egdes; i++) {
        tab[i].parent = i;
        tab[i].rang = 0;
    }
    
    for (int i=0;i<graphe.size_egdes;i++){    //for all les aretes de graphe 
        int x = find(tab, Arete[i].depart); //trouver la composante connexe du sommet de d ́epart
        int y = find(tab, Arete[i].arrivee); //trouver la composante connexe du sommet d’arriv ee
        
        if(x!=y){
            // C’est une arete de l’ACM et on fusionne les 2 composantes connexes
            insere_tete(&Arete[i],&ACM); //ajouter à la liste ACM
            cout += Arete[i].cout; //Calcule notre cout 
            ensemble_union(tab, x, y); //usionner les composantes connexes x et y
        }
    }
    
    //Verifier s'il s'agit d'un cycle ou non
    if(isCycle(ACM,tab)) {
        printf("Ce graphe n'admet pas d'ACM. \n");
        exit(EXIT_FAILURE);
    }
    
    printf("L'ACM kruksal du graphe a pour cout: %f\n",cout);
    
    free(Arete);
    free(tab);
    return ACM;
}



