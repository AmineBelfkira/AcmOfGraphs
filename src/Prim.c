#include "../include/Prim.h"

void affiche(int *tab,int taille){
    for(int i=0;i<taille;i++){
        printf("[%d]",tab[i]);
    }
    printf("\n");
}

bool dans_sommet(int* tab,int n){
    return tab[n]==1;
}

void ajout_sommet(int *tab, int i){
    tab[i]=1;
}

bool In_heap(heap_t* p,int sommet,int* indice){ //Cherche la presence de sommet dans p et stocke sa position dans indice
    for (int i=0;i< p->size;i++){
        if (p->data[i]==sommet) {
            *indice=i;
            return true;
        }
    }
    return false;
}

listedge_t Prim(int depart, graph_t graphe){

    heap_t* Atraiter=new_heap(graphe.size_vertices); //Initialiser un ensemble de sommets Atraiter
    
    //Initialiser un ensemble de sommets Atteint : tableau[i]=1 => i est dans le tableau                         tableau[i]=0 => i n'est pas dans le tableau          
    int* Atteint=calloc(graphe.size_vertices,sizeof(*Atteint)); 


    //Initialiser un ensemble dansAtraiter qui contient les sommets déjà inclus dans Atraiter pour minimiser 
    // la complexité à savoir la recherche dans tout Atraiter O(1)<O(log(n))
    int* DansAtraiter=calloc(graphe.size_vertices,sizeof(*Atteint)); 
    if (Atteint==NULL) {printf("Probleme d'allocation\n"); exit(EXIT_FAILURE);}
    for (int i=0;i<graphe.size_vertices;i++) Atteint[i]=0; //Pourer etre fait à l'aide de malloc directement
    //initialiser tous les peres edge previous des sommets à NULL ;
    for (int i=0;i<graphe.size_vertices;i++){
        if (i==depart) { //Mettre le cout du sommet depart à 0
            graphe.data[depart].cout=0;
            graphe.data[i].edge_previous=NULL;
        }
        else{
            graphe.data[i].cout=INFINI;
            graphe.data[i].edge_previous=NULL;
        }
    }
    
    heap_add(Atraiter,depart,graphe); //Ajouter le sommet depart a l’ensemble Atraiter
    
    while(Atraiter->size!=0 ){
        int n=heap_get_min(*Atraiter); //Rechercher le sommet u de plus faible cout de l’ensemble Atraiter
        supprimer_valeur_de_tas(Atraiter,graphe); //Supprimer le sommet u de plus faible cout de l’ensemble Atraiter
        DansAtraiter[n]=-1; //Supprime de Attraiter certes on peut avoir encore la meme valeur dans Atraiter mais le but c'est pas d'avoir un resultat parfait mais 
        //d'optimiser plus au moin la complexité
        ajout_sommet(Atteint,n); //Mettre le sommet u dans l’ensemble Atteint
        listedge_t p=graphe.data[n].edges;
        while(p!=NULL){
            int sommet_arrive= p->val.arrivee;
            if(!dans_sommet(Atteint,sommet_arrive) && p->val.cout < graphe.data[sommet_arrive].cout ){
                int indice=-1; //indice pour detecter la presence du sommet dans Atraiter et dans ce cas enregistrer sa position
                if(dans_sommet(DansAtraiter,sommet_arrive)){//pour moin de complexité on verifie au debut si on a presence dans DansAtraiter
                    In_heap(Atraiter,sommet_arrive,&indice);//Et que dans ce cas quand chercher dans Atraiter et cherche la position
                    if(graphe.data[Atraiter->data[indice]].cout > p->val.cout){
                        
                        graphe.data[ Atraiter->data[indice] ].cout=p->val.cout;
                        graphe.data[ Atraiter->data[indice] ].edge_previous=&p->val;
                        //On retrie notre nouveau Tas
                        while( (indice-1)/2>=0 && graphe.data[Atraiter->data[(indice-1)/2]].cout > graphe.data[Atraiter->data[indice]].cout){
                            switcher(&Atraiter->data[(indice-1)/2],&Atraiter->data[indice]);
                            indice=(indice-1)/2;
                        
                        }
                    }
                }else{
                    
                    graphe.data[sommet_arrive].cout=p->val.cout;
                    graphe.data[sommet_arrive].edge_previous=&p->val;
                    heap_add(Atraiter,sommet_arrive,graphe); //Ajouter le sommet v dans l’ensemble Atraiter
                    ajout_sommet(DansAtraiter,sommet_arrive); //Ajouter le sommet v dans l’ensemble DansAtraiter
                    
                }

            }
            p=p->next;
            
        }
    }
    
    listedge_t ACM=NULL;
    double cout=0;
    
    for (int i=0;i<graphe.size_vertices;i++){
        if (graphe.data[i].edge_previous!=NULL){
            insere_tete(graphe.data[i].edge_previous,&ACM);
            cout=cout+graphe.data[i].edge_previous->cout; //calcule notre cout
        }   
    } 
    //verfie que le graphe admet bien un ACM
    for (int i=0;i<graphe.size_vertices;i++){
        if( graphe.data[i].cout==INFINI && graphe.data[i].edge_previous==NULL ){
            printf("Ce graphe n'admet pas d'ACM. \n");
            exit(EXIT_FAILURE);
        }
    }
    
    printf("Le graphe a pour cout: %f\n",cout);
    free(Atteint);
    free(DansAtraiter);
    heap_delete(Atraiter);
    
    return ACM;
    
}



