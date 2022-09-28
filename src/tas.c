#include "../include/tas.h"



//à@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ TAS @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

heap_t* new_heap(int max_size){
    heap_t *p=calloc(1,sizeof(*p));
    if (p==NULL) {free(p); printf("Probleme d'allocation\n"); exit(EXIT_FAILURE);}
    p->size=0;
    p->capacity=max_size;
    p->data=calloc(max_size,sizeof(*(p->data)));
    if (p->data==NULL) {free(p); printf("Probleme d'allocation\n"); exit(EXIT_FAILURE);}
    return p;
}

int heap_get_min(heap_t tas){
  if (tas.size == 0){
    puts("le Tas vide");
    exit(1);
  }
  return tas.data[0];
}

void switcher(int* a,int* b){
  int c=*a;
  *a=*b;
  *b=c;
}

int left_son(int sommet){
  return 2*sommet+1;
}

int right_son(int sommet){
  return 2*sommet+2;
}

void heap_delete(heap_t* t){
  free(t->data);
  free(t);
}
//On ajoute la valeur dons notre tas puis en trie ce dernier 
void heap_add( heap_t* ptas, int valeur , graph_t graphe){
  if(ptas->size==ptas->capacity) {
    printf("Plus de mémoire!");
    exit(EXIT_FAILURE);
  }
  ptas->data[ptas->size] = valeur;
  ptas->size++;
  //Le tri du bas vers la haut
  int index=ptas->size-1;
  while( (index-1)/2>=0 && graphe.data[ptas->data[(index-1)/2]].cout > graphe.data[ptas->data[index]].cout){
      switcher(&ptas->data[(index-1)/2],&ptas->data[index]); //si le pere est plus grand ou echange les valeur
      index=(index-1)/2; //le pere  de l'indice
  }
}
//On supprime la valeur du tas puis en trie ce dernier
int supprimer_valeur_de_tas(heap_t* ptas , graph_t graphe){
  if(ptas->size==0) {
    printf("Pas d'element à supprimer!");
    exit(EXIT_FAILURE);
  }
  int n=ptas->data[0] ,index=0;
  ptas->data[0]=ptas->data[ptas->size-1];
  ptas->size--;
  int i;
  //le trie se fait du haut vers le bas
  while(left_son(index)<ptas->size){
    if(right_son(index)<ptas->size && graphe.data[ptas->data[right_son(index)]].cout < graphe.data[ptas->data[left_son(index)]].cout){
       i=right_son(index);
    }else i=left_son(index);
    if (graphe.data[ptas->data[index]].cout > graphe.data[ptas->data[i]].cout) switcher(&ptas->data[index],&ptas->data[i]);
    index=i;
  }
  return n; //retourne le premier element du tas qui correspend à la valeur minimal du tas
}

