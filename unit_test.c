/**
*	\file unit_test.c
*	\brief bibliothèque permettant de faire les tests unitaires du module grid_color
*	\author Loubna Anthea Abdellah Bader
*	\date 19 Feb 2017
*/

#include "CUnit/CUnit.h"
#include "CUnit/Basic.h"
#include "unit_test.h"
#include <math.h>

/*
	fn test_filled_grid(grid *grille)
	brief teste si une grille est bien remplie
	param  *grille adresse de la grille à tester
	return 1 si la grille est bien remplie 
	return 0 si la grille n'est pas bien remplie 
*/
int test_filled_grid(grid *grille)
{
	int i, j;
	int test = 1;
	
	if(grille->size <= 0)
	{
		if(grille->array != NULL)
		{
			test = 0;
		}
	}
	
	else
	{
		for(i = 0; i < grille->size; i = i+1)
		{
			for(j = 0; j < grille->size; j = j+1)
			{
				if(!(test_is_color(grille->array[i][j])))
				{
					return 0;
				}
			}
		}
	}
	
	return test;	
}
/*
	fn test_test_same_colour(void)
	brief test unitaire de test_same_color, l'existence du fichier same_color rempli de manière pertinente est nécessaire pour l'exécution du test
	param  void aucun
	return void fonction de type void
*/
void test_test_same_colour(void)
{

	grid grille;
	grid grille2;
	
	grille = allocate_grid(3);
	grille2 = init_grid(3);
	init_grid_file("same_color", &grille);
	
	CU_ASSERT(test_same_colour(&grille) == 1);
	CU_ASSERT(test_same_colour(&grille2) == 0);
	
	free_grid(&grille);
	free_grid(&grille2);
	

}
/*
	fn test_init_grid(void)
	brief test unitaire de la fonction init_grid
	param  void aucun
	return void fonction de type void
*/
void test_init_grid(void)
{

	grid grille1, grille2, grille3, grille4;
	
	grille1 = init_grid(0);
	grille2 = init_grid(6);
	grille3 = init_grid(12);
	grille4 = init_grid(20);
	
	CU_ASSERT(test_filled_grid(&grille1) == 0);
	CU_ASSERT(test_filled_grid(&grille2) == 1);
	CU_ASSERT(test_filled_grid(&grille3) == 1);
	CU_ASSERT(test_filled_grid(&grille4) == 1);
	
	free_grid(&grille1);
	free_grid(&grille2);
	free_grid(&grille3);
	free_grid(&grille4);
}
/*
	fn test_set_grid(void)
	brief test unitaire de la fonction set_grid
	param  void aucun
	return void fonction de type void
*/
void test_set_grid(void)
{

	grid grille1, grille2, grille3, grille4;
		
	grille1 = init_grid(4);
	grille2 = init_grid(1);
	grille3 = init_grid(10);
	grille4 = init_grid(20);
	
	set_grid(&grille1, 0, 0, 'B');
	set_grid(&grille1, 3, 3, 'G');
	set_grid(&grille1, 3, 1, 'V');
		
	set_grid(&grille2, 0, 0, 'G');
	
	set_grid(&grille3, 9, 8, 'B');
	set_grid(&grille3, 7, 3, 'G');
	set_grid(&grille3, 4, 5, 'V');
	
	set_grid(&grille4, 19, 18, 'B');
	set_grid(&grille4, 15, 14, 'G');
	set_grid(&grille4, 12, 10, 'V');
	
	CU_ASSERT(grille1.array[0][0]=='B');
	CU_ASSERT(grille1.array[3][3]=='G');
	CU_ASSERT(grille1.array[3][1]=='V');
	
	CU_ASSERT(grille2.array[0][0]=='G');
	
	CU_ASSERT(grille3.array[9][8]=='B');
	CU_ASSERT(grille3.array[7][3]=='G');
	CU_ASSERT(grille3.array[4][5]=='V');
	
	CU_ASSERT(grille4.array[19][18]=='B');
	CU_ASSERT(grille4.array[15][14]=='G');
	CU_ASSERT(grille4.array[12][10]=='V');
	
	free_grid(&grille1);
	free_grid(&grille2);
	free_grid(&grille3);
	free_grid(&grille4);
}
/*
	fn test_grid_file(char name_file[], grid *grille)
	 brief teste si ce qu'il y a dans une grille correspond à ce qu'il y a dans un fichier
	 param  name_file[] nom du fichier pour remplir la grille 
	 param  *grille adresse de la grille
	 return 1 si ce qu'il y a dans la grille correspond à ce qui est contenu dans le fichier 
	 return 0 sinon 
*/
int test_grid_file(char name_file[], grid *grille)
{

	char a;
	FILE * f = fopen(name_file, "r");
	int i, j;
	int compteur = count_file(name_file);
	int test = 1;
	
	if(compteur >= grille->size*grille->size)
	{
		for(i = 0; i < grille->size; i = i+1) 
		{
			for(j = 0; j < grille->size; j = j+1)
			{
				fread(&a, sizeof(char), 1 , f);
				if(grille->array[i][j] != a)
				{
					test = 0;
				}
			}
		}
	}
	else
	{
		test = 0;
	}
	
	fclose(f);

	return test;
}

/*
	 fn test_init_grid_file(void)
	 brief test unitaire de la fonction init_grid_file
	 param  void aucun
	 return void fonction de type void
*/
void test_init_grid_file(void)
{
	grid grille1, grille2, grille3, grille4;
	
	grille1 = allocate_grid(1);
	grille2 = allocate_grid(6);
	grille3 = allocate_grid(13);
	grille4 = allocate_grid(24);	
	
	fill_file("fichier1", 1);
	fill_file("fichier2", 6);
	fill_file("fichier3", 12);
	fill_file("fichier4", 24);
	
	init_grid_file("fichier1", &grille1);
	init_grid_file("fichier2", &grille2);
	init_grid_file("fichier3", &grille3);
	init_grid_file("fichier4", &grille4);

	CU_ASSERT(test_grid_file("fichier1", &grille1) == 1);	
	CU_ASSERT(test_grid_file("fichier2", &grille2) == 1);
	CU_ASSERT(test_grid_file("fichier3", &grille3) == 0);
	CU_ASSERT(test_grid_file("fichier4", &grille4) == 1);
	
	free_grid(&grille1);
	free_grid(&grille2);
	free_grid(&grille3);
	free_grid(&grille4);

}

/*
	 fn test_file(char name_file[], int n)
	 brief teste si le fichier est bien rempli
	 param  name_file[] nom du fichier à tester 
	 param  n  donne le nombre de caractères dans le fichier qui est égal à n*n
	 return 1 le fichier est rempli de n*n caractères correspondants à une couleur 
	 return 0 sinon 
*/
int test_file(char name_file[], int n)
{
	int test = 1;
	FILE * f = fopen(name_file, "r");
	
	if(f)
	{
		char a;
		int compteur = count_file(name_file);
	
		if(compteur != n*n)
		{
			test = 0;
		}
		else
		{
			while(fread(&a, sizeof(char), 1, f))
			{
				if(!test_is_color(a))
				{
					test = 0;
				}
			}
		}
	
		fclose(f);
	}
	else
	{
		test = 0;
	}
	
	return test;

}

/*
	 fn test_fill_file(void)
	 brief test unitaire de la fonction fill_file
	 param  void aucun
	 return void fonction de type void
*/
void test_fill_file(void)
{
	fill_file("fichier5", 6);
	fill_file("fichier6", 0);
	fill_file("fichier7", -1);
	fill_file("fichier8", 12);
	
	CU_ASSERT(test_file("fichier5", 6) == 1);
	CU_ASSERT(test_file("fichier6", 0) == 0);
	CU_ASSERT(test_file("fichier7", -1) == 0);
	CU_ASSERT(test_file("fichier8", 12) == 1);
}

/*
	 fn test_fill_file_grid(void)
	 brief test unitaire de la fonction fill_file_grid
	 param  void aucun
	 return void fonction de type void
*/
void test_fill_file_grid(void)
{
	grid grille1, grille2, grille3, grille4;
	
	grille1 = init_grid(0);
	grille2 = init_grid(1);
	grille3 = init_grid(12);
	grille4 = init_grid(24);

	fill_file_grid("a1", "b1", &grille1);
	fill_file_grid("a2", "b2", &grille2);
	fill_file_grid("a3", "b3", &grille3);
	fill_file_grid("a4", "b4", &grille4);

	CU_ASSERT(test_file("a1", 0) == 0);
	CU_ASSERT(test_file("a2", 1) == 1);
	CU_ASSERT(test_file("a3", 12) == 1);
	CU_ASSERT(test_file("a4", 24) == 1);

	free_grid(&grille1);
	free_grid(&grille2);
	free_grid(&grille3);
	free_grid(&grille4);
}

/*
	 fn test_is_tache(grid *grille, char name_file[])
	 brief teste si une tâche de la grille correpond à celle définie dans le fichier
	 param  name_file[] nom du fichier contenant un tâche
	 param  *grille adresse de la grille à tester 
	 return 1 si la tâche de la grille correspond à celle définie dans le fichier  
	 return 0 sinon 
*/
int test_is_tache(grid *grille, char name_file[])
{
	int test = 1;
	int i, j;
	FILE *f = fopen(name_file, "r");
	char a;
	
	for(i = 0; i < grille->size; i = i+1)
	{
		for(j = 0; j < grille->size; j = j+1)
		{
			fread(&a, sizeof(char), 1, f);
			if(grille->belong[i][j] != atoi(&a))
			{
				test = 0;
			}
		}
	}
	
	fclose(f);
	
	return test;

}

/*
	 fn test_detect_flood(void)
	 brief test unitaire de la fonction detect_flood, les fichiers grille1, grille2, grille3 et grille4 definissant les grilles et belong1, belong2, belong3 et belong4 definissant les tâches des grilles doivent exister pour exécuter ce test
	 param  void aucun
	 return void fonction de type void
*/
void test_detect_flood(void)
{
	grid grille1, grille2, grille3, grille4;

	grille1 = allocate_grid(1);
	grille2 = allocate_grid(4);
	grille3 = allocate_grid(5);
	grille4 = allocate_grid(10);
	
	init_grid_file("grille1", &grille1);
	init_grid_file("grille2", &grille2);
	init_grid_file("grille3", &grille3);
	init_grid_file("grille4", &grille4);
	
	detect_flood(&grille1, 0, 0, grille1.array[0][0]);
	detect_flood(&grille2, 0, 0, grille2.array[0][0]);
	detect_flood(&grille3, 0, 0, grille3.array[0][0]);
	detect_flood(&grille4, 0, 0, grille4.array[0][0]);
	
	CU_ASSERT(test_is_tache(&grille1, "belong1") == 1);
	CU_ASSERT(test_is_tache(&grille2, "belong2") == 1);
	CU_ASSERT(test_is_tache(&grille3, "belong3") == 1);
	CU_ASSERT(test_is_tache(&grille4, "belong4") == 1);

	free_grid(&grille1);
	free_grid(&grille2);
	free_grid(&grille3);
	free_grid(&grille4);
}

/*
	 fn test_change_color_tache(grid *grille, char c)
	 brief teste si la couleur de la tâche est changée par la couleur c
	 param  *grille adresse de la grille à tester 
	 param c couleur cible
	 return 1 si la couleur de la tâche est changée par la couleur c 
	 return 0 sinon 
*/
int test_change_color_tache(grid *grille, char c)
{
	int test = 1;
	int i, j;
	
	for(i = 0; i < grille->size; i = i+1){
		for(j = 0; j < grille->size; j = j+1){
			if(grille->belong[i][j] == 1){
				if(grille->array[i][j] != c){
					test = 0;
				}
			}
		}
	}
	
	return test;
}

/*
	 fn test_change_color(void)
	 brief test unitaire de la fonction change_color
	 param  void aucun
	 return void fonction de type void
*/
void test_change_color(void)
{
	grid grille1, grille2, grille3, grille4;
	
	grille1 = allocate_grid(1);
	grille2 = allocate_grid(4);
	grille3 = allocate_grid(5);
	grille4 = allocate_grid(10);
	
	init_grid_file("grille1", &grille1);
	init_grid_file("grille2", &grille2);
	init_grid_file("grille3", &grille3);
	init_grid_file("grille4", &grille4);
	
	detect_flood(&grille1, 0, 0, grille1.array[0][0]);
	detect_flood(&grille2, 0, 0, grille2.array[0][0]);
	detect_flood(&grille3, 0, 0, grille3.array[0][0]);
	detect_flood(&grille4, 0, 0, grille4.array[0][0]);
	
	change_color(&grille1, 'V');
	change_color(&grille2, 'G');
	change_color(&grille3, 'J');
	change_color(&grille4, 'M');
	
	CU_ASSERT(test_change_color_tache(&grille1, 'V') == 1);
	CU_ASSERT(test_change_color_tache(&grille2, 'G') == 1);
	CU_ASSERT(test_change_color_tache(&grille3, 'J') == 1);
	CU_ASSERT(test_change_color_tache(&grille4, 'M') == 1);
	 	
	free_grid(&grille1);
	free_grid(&grille2);
	free_grid(&grille3);
	free_grid(&grille4);
}