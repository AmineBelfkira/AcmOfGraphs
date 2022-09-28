#include "../include/LectureFichier.h"



/*
Fichier à lire graphe.txt
Dans ces fichiers, les arêtes ne sont représentées que par 1 seul arc, dans un des 2
sens, afin de limiter la taille des fichiers avec des informations inutiles. Pour Kruskal,
cela n’a aucune importance. Pour Prim, comme vous utilisez une représentation des
arcs dans le graphe, il vous faudra aussi créer un arc inverse pour chaque arc du fichier afin de
représenter une arête.
*/

                                                                //LECTURE FICHIER
graph_t* OpenFile(char* filename){
    //graph_t* p_graphe=calloc(1,sizeof(*p_graphe));
    int numero,nbsommet,nbarete;
    double lat,longi ;
    char mot[512] ;
    

    FILE* f=fopen(filename,"r");
    if (f==NULL) { printf("Impossible d’ouvrir le fichier\n"); exit(EXIT_FAILURE);}
    /* Lecture de la premiere ligne du fichier : nombre de sommets et nombre d’aretes */
    fscanf(f,"%d %d ",&nbsommet,&nbarete);
    graph_t* p_graph=initialisation_graphe(nbsommet,2*nbarete);
    /* Ligne de texte "Sommets du graphe" qui ne sert a rien */
    fgets(mot,511,f);
    for (int i = 0; i<nbsommet; i++){
        /* lecture d’une ligne de description d’un sommet */
        /* on lit d’abord le numero du sommet, sa position et le nom de la ligne */
        fscanf(f,"%d %lf %lf ", &numero, &lat, &longi);
        /* numero contient alors l’entier ou numero du sommet, lat et longi la position du sommet */
        /* Le nom de la station peut contenir des separateurs comme l’espace. On utilise plutot fgets pour lire
        toute la fin de ligne */
        fgets(mot,511,f);
        /* fgets a lu toute la ligne, y compris le retour a la ligne. On supprime le caractere ’\n’ qui peut se
        trouver a la fin de la chaine mot : */
        //p_graph->data[i].nom=calloc(1,sizeof(strlen(mot)));
        p_graph->data[i].nom=malloc(strlen(mot)+1);
        strcpy(p_graph->data[i].nom,mot);
        if (mot[strlen(mot)-1]<32) mot[strlen(mot)-1]=0;
        /* mot contient desormais le nom du sommet, espaces eventuels inclus. */
        /*Pour sauter les lignes de commentaires, on peut simplement utiliser la fonction fgets, sans exploiter
        la chaine de caracteres lue dans le fichier */
        p_graph->data[numero].x = lat;
        //printf("x: %lf", p_graph->data[numero].x );
        p_graph->data[numero].y = longi;
        //printf("   y: %lf\n", p_graph->data[numero].y );
        p_graph->data[numero].edges = NULL;

        /* mot contient desormais le nom du sommet, espaces eventuels inclus. */
        /*Pour sauter les lignes de commentaires, on peut simplement utiliser la fonction fgets, sans exploiter
        la chaine de caracteres lue dans le fichier */
    }
    fgets(mot,511,f);
    
    int depart,arrive;
    double cout;
    edge_t* valeur1=initialisation_edge(0,0,0);
    edge_t* valeur2=initialisation_edge(0,0,0);
    for( int i = 0; i< nbarete ; i++ ){
        fscanf( f , "%d %d %lf" , &depart , &arrive, &cout );
        valeur1->depart = depart;
        valeur2->depart = arrive;
        valeur1->arrivee = arrive;
        valeur2->arrivee = depart;
        valeur1->cout = cout;
        valeur2->cout = cout;
        insere_tete(valeur1, &(p_graph->data[depart].edges));
        insere_tete(valeur2, &(p_graph->data[arrive].edges));
        fgets(mot,511,f);
    }
    supprime_arc(valeur1);
    supprime_arc(valeur2);
    
    
    
   
    /* Ne pas oublier de fermer votre fichier */
    fclose(f);
    return p_graph;
}
    



graph_t* OpenFile2(char* filename){
    //graph_t* p_graphe=calloc(1,sizeof(*p_graphe));
    int numero,nbsommet,nbarete;
    double lat,longi ;
    char mot[512] ;
    

    FILE* f=fopen(filename,"r");
    if (f==NULL) { printf("Impossible d’ouvrir le fichier\n"); exit(EXIT_FAILURE);}
    /* Lecture de la premiere ligne du fichier : nombre de sommets et nombre d’aretes */
    fscanf(f,"%d %d ",&nbsommet,&nbarete);
    graph_t* p_graph=initialisation_graphe(nbsommet,nbarete);
    /* Ligne de texte "Sommets du graphe" qui ne sert a rien */
    fgets(mot,511,f);
    for (int i = 0; i<nbsommet; i++){
        /* lecture d’une ligne de description d’un sommet */
        /* on lit d’abord le numero du sommet, sa position et le nom de la ligne */
        fscanf(f,"%d %lf %lf ", &numero, &lat, &longi);
        /* numero contient alors l’entier ou numero du sommet, lat et longi la position du sommet */
        /* Le nom de la station peut contenir des separateurs comme l’espace. On utilise plutot fgets pour lire
        toute la fin de ligne */
        fgets(mot,511,f);
        /* fgets a lu toute la ligne, y compris le retour a la ligne. On supprime le caractere ’\n’ qui peut se
        trouver a la fin de la chaine mot : */
        //p_graph->data[i].nom=calloc(1,sizeof(strlen(mot)));
        p_graph->data[i].nom=malloc(strlen(mot)+1);
        strcpy(p_graph->data[i].nom,mot);
        if (mot[strlen(mot)-1]<32) mot[strlen(mot)-1]=0;
        /* mot contient desormais le nom du sommet, espaces eventuels inclus. */
        /*Pour sauter les lignes de commentaires, on peut simplement utiliser la fonction fgets, sans exploiter
        la chaine de caracteres lue dans le fichier */
        p_graph->data[numero].x = lat;
        //printf("x: %lf", p_graph->data[numero].x );
        p_graph->data[numero].y = longi;
        //printf("   y: %lf\n", p_graph->data[numero].y );
        p_graph->data[numero].edges = NULL;

        /* mot contient desormais le nom du sommet, espaces eventuels inclus. */
        /*Pour sauter les lignes de commentaires, on peut simplement utiliser la fonction fgets, sans exploiter
        la chaine de caracteres lue dans le fichier */
    }
    fgets(mot,511,f);
    
    int depart,arrive;
    double cout;
    edge_t* valeur1=initialisation_edge(0,0,0);
    //edge_t* valeur2=initialisation_edge(0,0,0);
    for( int i = 0; i< nbarete ; i++ ){
        fscanf( f , "%d %d %lf" , &depart , &arrive, &cout );
        valeur1->depart = depart;
        //valeur2->depart = arrive;
        valeur1->arrivee = arrive;
        //valeur2->arrivee = depart;
        valeur1->cout = cout;
        //valeur2->cout = cout;
        insere_tete(valeur1, &(p_graph->data[depart].edges));
        //insere_tete(valeur2, &(p_graph->data[arrive].edges));
        fgets(mot,511,f);
    }
    supprime_arc(valeur1);
    //supprime_arc(valeur2);
    
    //for( int i = 0; i< nbsommet ; i++ ){
    //    printf("WE HAVE %d : \n",i);
    //    affichage(p_graph->data[i].edges); puts(" ");    
    //}
    
   
    /* Ne pas oublier de fermer votre fichier */
    fclose(f);
    return p_graph;
}

