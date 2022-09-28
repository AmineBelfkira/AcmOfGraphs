#include "../include/liste.h"

//fonction affichage de la liste
void affichage(listedge_t l){
    listedge_t p=l;
    if(l==NULL) printf("NULL\n");
    else{
        while(p!=NULL){
            afficheArc(&(p->val));
            p=p->next;
        }
        printf("\n");
    }
}

//fonction pour initialiser une liste vide
listedge_t initialistion_liste_vide(){
    listedge_t p=calloc(1,sizeof(*p));
    if (p == NULL) { //Verifie si notre structure a bien était alouée.
        perror("Plus de memoire\n");
        exit(EXIT_FAILURE);
    }    
    return p;
}

//Fonction insere tête plutot que insere queue pour une complexité minimale
void insere_tete(edge_t* valeur, listedge_t* pl){
    listedge_t p = initialistion_liste_vide();
    p->val  = *valeur;
    p->next = *pl;
    *pl=p;
}


//Libere notre structure
void supprimer_liste(listedge_t l){
     listedge_t p=l,q;
     if (l==NULL) return ;
     while(p!=NULL){
         q=p;
         p=p->next;
         supprime_arc(&q->val);
    }
 }
