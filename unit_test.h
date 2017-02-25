/**
*	\file unit_test.h
*	\brief prototypes des fonctions et structures nécessaires pour les tests unitaires des fonctions contenues dans grid_color.c
*	\author Loubna Anthea Abdellah Bader
*	\version 3.0
*	\date 25 Feb 2017
*/

#ifndef _UNIT_TEST_H
#define _UNIT_TEST_H
#include "CUnit/CUnit.h"
#include "CUnit/Basic.h"
#include "grid_color.h"
#include <math.h>

/**
*	\fn test_filled_grid(grid *grille)
*	\brief teste si une grille est bien remplie
*	\param  *grille adresse de la grille à tester
*	\return 1 si la grille est bien remplie 
*	\return 0 si la grille n'est pas bien remplie 
*/
int test_filled_grid(grid *grille);

/**
*	\fn test_test_same_colour(void)
*	\brief test unitaire de test_same_color, l'existence du fichier same_color rempli de manière pertinente est nécessaire pour l'exécution du test
*	\param  void aucun
*	\return void fonction de type void
*/
void test_test_same_colour(void);

/**
*	\fn test_init_grid(void)
*	\brief test unitaire de la fonction init_grid
*	\param  void aucun
*	\return void fonction de type void
*/
void test_init_grid(void);

/**
*	\fn test_set_grid(void)
*	\brief test unitaire de la fonction set_grid
*	\param  void aucun
*	\return void fonction de type void
*/
void test_set_grid(void);

/**
*	\fn test_grid_file(char name_file[], grid *grille)
*	\brief teste si ce qu'il y a dans une grille correspond à ce qu'il y a dans un fichier
*	\param  name_file[] nom du fichier pour remplir la grille 
*	\param  *grille adresse de la grille
*	\return 1 si ce qu'il y a dans la grille correspond à ce qui est contenu dans le fichier 
*	\return 0 sinon 
*/
int test_grid_file(char name_file[], grid *grille);

/**
*	\fn test_init_grid_file(void)
*	\brief test unitaire de la fonction init_grid_file
*	\param  void aucun
*	\return void fonction de type void
*/
void test_init_grid_file(void);

/**
*	\fn test_file(char name_file[], int n)
*	\brief teste si le fichier est bien rempli
*	\param  name_file[] nom du fichier à tester 
*	\param  n  donne le nombre de caractères dans le fichier qui est égal à n*n
*	\return 1 le fichier est rempli de n*n caractères correspondants à une couleur 
*	\return 0 sinon 
*/
int test_file(char name_file[], int n);

/**
*	\fn test_fill_file(void)
*	\brief test unitaire de la fonction fill_file
*	\param  void aucun
*	\return void fonction de type void
*/
void test_fill_file(void);

/**
*	\fn test_fill_file_grid(void)
*	\brief test unitaire de la fonction fill_file_grid
*	\param  void aucun
*	\return void fonction de type void
*/
void test_fill_file_grid(void);

/**
*	\fn test_is_tache(grid *grille, char name_file[])
*	\brief teste si une tâche de la grille correpond à celle définie dans le fichier
*	\param  name_file[] nom du fichier contenant un tâche
*	\param  *grille adresse de la grille à tester 
*	\return 1 si la tâche de la grille correspond à celle définie dans le fichier  
*	\return 0 sinon 
*/
int test_is_tache(grid *grille, char name_file[]);

/**
*	\fn test_detect_flood(void)
*	\brief test unitaire de la fonction detect_flood, les fichiers grille1, grille2, grille3 et grille4 definissant les grilles et belong1, belong2, belong3 et belong4 definissant les tâches des grilles doivent exister pour exécuter ce test
*	\param  void aucun
*	\return void fonction de type void
*/
void test_detect_flood(void);

/**
*	\fn test_change_color_tache(grid *grille, char c)
*	\brief teste si la couleur de la tâche est changée par la couleur c
*	\param  *grille adresse de la grille à tester 
*	\param c couleur cible
*	\return 1 si la couleur de la tâche est changée par la couleur c 
*	\return 0 sinon 
*/
int test_change_color_tache(grid *grille, char c);

/**
*	\fn test_change_color(void)
*	\brief test unitaire de la fonction change_color
*	\param  void aucun
*	\return void fonction de type void
*/
void test_change_color(void);

#endif