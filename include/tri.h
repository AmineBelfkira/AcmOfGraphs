#ifndef TRI_H
#define TRI_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "arc.h"


void switcher_edge(edge_t* a,edge_t* b);
void fusion(edge_t* tabi,edge_t* tab1,edge_t* tab2,int taille1,int taille2);
edge_t* trifusion(edge_t* tab,int taille);



#endif