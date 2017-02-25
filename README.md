

LotA

Toutes les fonctions de base et les commentaires doxygen sont contenues dans grid_color.c leurs prototypes sont dans grid_color.h.

Tous les tests unitaires et leurs commentaires doxygen sont contenus dans unit_test.c leurs prototypes sont dans unit_test.h

Le main contient l'éxécution les tests
Le mainjeu contient une boucle de jeu pour mettre en évidence le bon fonctionnement des fonctions de base pour le jeu.


Instructions d'installation

Pour la documentation doxygen 
sudo apt-get install doxygen

Pour les tests unitaires avec CUnit
sudo apt-get install libcunit1 libcunit1-doc libcunit1-dev

Instructions d'utilisation

Pour compiler et exécuter

make 
./ lotA

pour tester l'absence de fuites de mémoire (Valgrind)m
valgrind ./lotA

pour générer la documentation (Doxygen)
doxygen 

pour nettoyer le répertoire
make clean
