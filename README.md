Le repertoire src contient tous les fichiers sources .c 
Le répertorie include contient tous les fichiers d'entete .h 
Le répertoire tests contient tous les fichiers de tests  
Le répertoire bin contient les executables 

```
**make bin/testKruksal** pour constuire le programme de test testKruksal.
**make bin/testPrim** pour constuire le programme de test testPrim.
**make bin/acmtxt** pour constuire le programme de test acmtxt.c.
**make all** pour construire tout les progammes tests.
**make clean** pour supprimer le dossier bin des executables

```
-Les scripts permettent d'executer les fichiers graphes dans le dossier Graphes et de sauvegarder les resultats dans un fichier .txt:
```
            **./test_Kruksal **test l'algorithme Kruksal
            **./test_ Prim **test l'algorithme Prim 
```


-L'execution se fait comme suit:
```
**./test_Prim %{nom dufichier graphe}**
**./test_Kruksal %{nom du fichier graphe}**
**./test_acmtxt %{nom du fichier graphe} 0 0** : Effectuer test Kruksal en calculant le cout sans afficher l'ACM
**./test_acmtxt %{nom du fichier graphe} 1 0** : Effectuer test Prim en calculant le cout sans afficher l'ACM
**./test_acmtxt %{nom du fichier graphe} 0 1 **: Effectuer test Kruksal en calculant le cout et afficher l'ACM
**./test_acmtxt %{nom du fichier graphe} 1 1** : Effectuer test Prim en calculant le cout et afficher l'ACM

```
