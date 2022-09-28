#include "../include/tri.h"

void switcher_edge(edge_t* a,edge_t* b){
  edge_t c=*a;
  *a=*b;
  *b=c;
}

void fusion(edge_t* tabi,edge_t* tab1,edge_t* tab2,int taille1,int taille2){
    edge_t* tab=calloc((taille1+taille2),sizeof(*tab));
    edge_t *p=tab1;
    edge_t *q=tab2;
    int n=taille1,m=taille2,pin=0;
    while( n>0 || m>0 ){
        if ( n==0 ){
            switcher_edge(tab+pin,q);
            q++; m--;
        } 
        else if( m==0 ){
            switcher_edge(tab+pin,p);
            p++; n--;
        }
        else{
            if (p->cout<q->cout){
                switcher_edge(tab+pin,p);
                p++; n--;
            }
            else{
                switcher_edge(tab+pin,q);
                q++; m--;
            }
        }
        pin++;
    }
    for (int i=0;i<taille1+taille2;i++) tabi[i]=tab[i];
    free(tab);
}

edge_t* trifusion(edge_t* tab,int taille){
    if( taille==1 ) return tab;
    else{
        int milieu=taille/2;
        edge_t *p=tab , *q=tab+milieu;
        p=trifusion(p,milieu);
        q=trifusion(q,taille-milieu);
        fusion(tab,p,q,milieu,taille-milieu);
        return tab;
    }
}
