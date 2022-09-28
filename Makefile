# Ce Makefile permet de générer les executables
# - pour les tests f1main et f2main du repertoire tests
#-  pour le programme pccmain du repertoire src

# les fichiezrs executables sont situés sdnas le repertoire bin


#Les repertoires
#Pour les fichiers d'entete
INCDIR=./include
#Pour les fichiers executables
BINDIR=./bin
#Pour les fichiers binaires (.o)
OBJDIR=./obj
#Pour les fichiers de tests
TESTS=./tests
#Pour les fichiers sources .c
SRCDIR=./src

#Le nom du compilateur
CC=gcc

#Les options du compilateur : compilation (-c) et debug (-g). On peut ajouter -O3 pour optimiser quand le code est juste
#CFLAGS=-c -g -I$(INCDIR) 
CFLAGS=-std=c99 -Wall -Wextra -c -g -pg -I$(INCDIR) 



#Les options de l'editeur de liens : -lm pour la bibliothèque mathématique. Voir les Makefile de TP pour ajouter la SDL si besoin
LDFLAGS= -lm

#Les executables que l'on veut construire: a la fois ceux des tests et ceux des programmes finaux
EXEDIR=$(BINDIR)/testKruksal $(BINDIR)/testPrim $(BINDIR)/acmtxt

 
#Les fichiers binaire : ajouter les noms des nouveaux fichiers ici
OBJ=$(OBJDIR)/testPrim.o $(OBJDIR)/testKruksal.o $(OBJDIR)/acmtxt.o





all:  $(EXEDIR)
		

#pour construire le test Kruksal
$(BINDIR)/testKruksal : $(OBJDIR)/testKruksal.o $(OBJDIR)/Kruksal.o  $(OBJDIR)/sommet.o $(OBJDIR)/arc.o $(OBJDIR)/liste.o $(OBJDIR)/LectureFichier.o $(OBJDIR)/graphe.o $(OBJDIR)/tri.o 
	$(CC) -o $@ $^ $(LDFLAGS)

#pour construire le test Prim 
$(BINDIR)/testPrim : $(OBJDIR)/testPrim.o $(OBJDIR)/Prim.o  $(OBJDIR)/sommet.o $(OBJDIR)/arc.o $(OBJDIR)/liste.o $(OBJDIR)/LectureFichier.o $(OBJDIR)/graphe.o $(OBJDIR)/tas.o 
	$(CC) -o $@ $^ $(LDFLAGS)
	
#pour construire le test Prim 
$(BINDIR)/acmtxt  : $(OBJDIR)/acmtxt.o $(OBJDIR)/Prim.o $(OBJDIR)/Kruksal.o  $(OBJDIR)/sommet.o $(OBJDIR)/arc.o $(OBJDIR)/liste.o $(OBJDIR)/LectureFichier.o $(OBJDIR)/graphe.o $(OBJDIR)/tas.o $(OBJDIR)/tri.o 
	$(CC) -o $@ $^ $(LDFLAGS)


# pour construire les fichiers binaires .o
$(OBJDIR)/%.o : $(TESTS)/%.c
	$(CC) $(CFLAGS) $^ -o $@

$(OBJDIR)/%.o : $(SRCDIR)/%.c
	$(CC) $(CFLAGS) $^ -o $@
	
	
clean: 
	rm -rf $(OBJDIR)/* $(BINDIR)/* $(EXEDIR) *.dSYM
	
	@echo "Make clean fait"

#Pour construire tous les executables
 







