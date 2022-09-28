#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "../include/arc.h"


//Fonction d'initialisation d'un arc
edge_t* initialisation_edge(int depart ,int arrivee,double cout){
    edge_t* p=calloc(1,sizeof(*p));
    if (p==NULL) { printf("Probleme d'allocation\n"); exit(EXIT_FAILURE);}
    p->depart=depart;
    p->arrivee=arrivee;
    p->cout=cout;
    return p;
}

//Fonction pour afficher le depart, arrivee et le cout d'un arc
void afficheArc(edge_t* p){
    if (p==NULL) printf("NULL\n");
    else{
        printf("[depart:%d , arrive:%d , cout:%f]",p->depart,p->arrivee,p->cout);
    }
    
}

//Fonction pour comparer 2 arcs: On compare les sommets arrivee depart et cout
bool same(edge_t* p,edge_t* q){
    if(p->depart==q->depart && p->arrivee==q->arrivee && p->cout==p->cout){
        return true;
    }
    return false;
}

//Fonction pour libere notre structure  arc
void supprime_arc(edge_t* u){
    if(u!=NULL) free(u);
}


