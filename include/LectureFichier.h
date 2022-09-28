#ifndef LECTUREFICHIER_H
#define LECTUREFICHIER_H


#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "graphe.h"


graph_t* OpenFile(char* filename);
graph_t* OpenFile2(char* filename);

#endif