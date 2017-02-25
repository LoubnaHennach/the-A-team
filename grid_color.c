/**
*	\file grid_color.c
*	\brief bibliothèque permettant de manipuler les structures et les fonctions nécessaires pour la réalisation du jeu
*	\author Loubna Anthea Abdellah Bader
*	\version 3.0
*	\date 25 Feb 2017
*/
#include "grid_color.h"
#include <math.h>

/**
*	\fn grid allocate_grid(int n)
*	\brief alloue la mémoire pour une grille de taille n*n
*	\param n la taille de la grille
*	\return grid une grille vide alloué en mémoire
*/
grid allocate_grid(int n)
{

   grid grille;
   int i;
   
   if(n > 0)
   {
		
	   grille.size = n;
	
		grille.array=malloc(n*sizeof(char*));
		grille.belong=malloc(n*sizeof(int*));
		for(i = 0; i < n; i++)
		{
			grille.array[i] = malloc(n*sizeof(char));
			grille.belong[i] = malloc(n*sizeof(int));
		}
		
	}
	else
	{
		printf("allocation impossible\n");
		grille.size = 0;	
	}
	
	return grille;
}

/**
*	\fn grid init_grid(int n)
*	\brief initialise la grille de taille n*n à partir de valeurs aléatoires
*	\param  n la taille de la grille
*	\return grid une grille initialisée par des valeurs aléatoires
*/
grid init_grid(int n)
{
		grid grille;
		if(n > 0)
		{
			srand(time(NULL));
			grille=allocate_grid(n);

			int i,j;
  	    	char couleurs[6]={'B','V','R','J','M','G'};

			for(i=0; i<n ; i++)
			{
				for(j=0; j<n ; j++)
				{
					grille.array[i][j]=couleurs[rand()%6];
					grille.belong[i][j]=0;
				}
			}
		}
		if(n <= 0)
		{ 
    	 	printf(" Taille non valide n <= 0\n");
    	 	grille = allocate_grid(1);
    	 	grille.array[0][0] = '0';	
		}

		return grille;
}

/**
*	\fn void free_grid(grid *grille)
*	\brief libère la memoire occupée par une grille
*	\param *grille adresse de la grille à libérer
*	\return ne retourne rien, c'est une fonction de type void
*/
void free_grid(grid *grille)
{
	int i;

	for(i = 0; i < grille->size ; i++)
	{
		free(grille->array[i]);
		grille->array[i] = NULL;
		free(grille->belong[i]);
		grille->belong[i] = NULL;
	}

	free(grille->array);
	free(grille->belong);
	grille->array = NULL;
	grille->belong = NULL;
}

/**
*	\fn int test_is_color(char couleur)
*	\brief teste si couleur est une des couleurs utilisées
*	\param couleur la couleur à tester
*	\return 1 si le couleur appartient à la liste des couleurs utilisées
*	\return 0 si le couleur n'appartient pas à la liste des couleurs utilisées
*/
int test_is_color(char couleur)
{

	int i;
	int test = 0;
	char couleurs[6]={'B','V','R','J','M','G'};
	
	for(i = 0; i < 6; i = i+1)
	{
		if(couleur == couleurs[i])
		{
			test = 1;
		}
	}

	return test;
}

/**
*	\fn void set_grid(grid *grille,int x,int y,int couleur)
*	\brief pour modifier la grille
*	\param *grille adresse de la grille pour accéder et modifier
*	simplement ses variables
*	\param x abscisse de la case à modifier
*	\param y ordonnée de la case à modifier
*	\param couleur la nouvelle couleur
*	\return une fonction de type void
*/
void set_grid(grid *grille,int x,int y,char couleur) 
{
	if(test_is_color(couleur))
	{
		grille->array[x][y] = couleur;
	}
}

/*
*	\fn void fill_file(char name_file[], int n)
*	\brief pour remplir un fichier avec des charactères aléatoires
*	\param name_file nom du fichier
*	\param n nombre de charactères à générer
*	\return ne retourne rien fonction de type void
*/
void fill_file(char name_file[], int n)
{

	int i;
	char c;
	char couleurs[6]={'B','V','R','J','M','G'};

	if(n > 0){
		FILE * f =fopen(name_file, "w+");
		if(f){

			srand(time(NULL));

			for(i = 0; i < n*n; i = i+1)
			{
				c = couleurs[rand()%6];
				fprintf(f, "%c", c);
			}
   		fclose(f);
		}
	}
	else{
		printf("taille non valide\n");
	}
}

/*
*	\fn int count_file(char name_file[])
*	\brief compte le nombre de caractères dans un fichier implémenté par fill_file
*	\param name_file[] le nom du fichier
*	\return le nombre de caractères contenus dans le fichier implémenté à l'aide de fill_file
*/
int count_file(char name_file[])
{

	char a;
	int compteur = 0;
	
	FILE * f = fopen(name_file, "r");

	while(fread(&a, sizeof(char), 1, f))
	{
		compteur = compteur+1;
	}

	fclose(f);

	return compteur;
}

/*
*	\fn void init_grid_file(char name_file[], grid *grille)
*	\brief pour remplir une grille à partir d'un fichier
*	\param name_file nom du fichier
*	\param *grille adresse de la grille
*	\return ne retourne rien fonction de type void
*/
void init_grid_file(char name_file[], grid *grille)
{

	int i, j, n;
	int compteur = count_file(name_file);
	
	FILE * f = fopen(name_file, "r");

	if(f)
	{
		n = grille->size;
		if(compteur >= grille->size*grille->size)
		{
		
			for(i = 0; i < n; i = i+1)
			{
				for(j = 0; j < n; j = j+1)
				{
					fread(&grille->array[i][j], sizeof(char), 1, f);
				}
			}
		}
		else
		{
			printf("fichier trop petit\n");
			for(i = 0; i < n; i = i+1)
			{
				for(j = 0; j < n; j = j+1)
				{
					grille->array[i][j] = '0';
				}
			}
		}

		for(i = 0; i < n; i = i+1)
		{
			for(j = 0; j < n; j = j+1)
			{		
				grille->belong[i][j]=0;
	   		}
   		}	
		fclose(f);
	}
	else
	{
		printf("le fichier ne peut pas être ouvert\n");
	}
}

/*
*	\fn void fill_file_grid(char name_file_array[], char name_file_belong[], grid* grille)
*	\brief pour remplir un fichier avec les charactères contenus dans le tableau array de la grille et un autre fichier avec les entiers contenus dans le tableau belong de la grille
*	\param name_file_array nom du fichier à remplir avec les caractères
*	\param name_file_belong nom du fichier à remplir avec les entiers
*	\param n nombre de charactères à générer
*	\return ne retourne rien fonction de type void
*/
void fill_file_grid(char name_file_array[], char name_file_belong[], grid* grille){

	int i, j, n;
	
	FILE * fa = fopen(name_file_array, "w");
	FILE * fb = fopen(name_file_belong, "w");

	if(fa && fb)
	{
		n = grille->size;
		if(n > 0)
		{
		
			for(i = 0; i < n; i = i+1)
   			{
				for(j = 0; j < n; j = j+1)
   		   		{
					fprintf(fa, "%c", grille->array[i][j]);
					fprintf(fb, "%d", grille->belong[i][j]);
				}
			}
		}
		else
		{
			printf("grille non valide\n");
		}

		fclose(fa);
		fclose(fb);
	}
	else
	{
		printf("le fichier ne peut pas être ouvert\n");
	}
}

/**
*	\fn void grid_print(grid *grille)
*	\brief pour afficher une grille
*	\param *grille adresse de la grille à afficher
*	\return une fonction de type void
*/
void grid_print(grid *grille)
{
	int i,j;

	for(i=0 ; i < grille->size; i++)
	{
		for(j=0 ;j < grille->size; j++)
		{
			printf("%c", grille->array[i][j]);
		}
		printf("\n");
	}
  printf("\n");
}

/**
	\fn int test_same_colour(grid *grille)
	\brief teste si toutes les cases de la grille ont la même couleur
	\param *grille adresse de la grille à tester
	\return retourne 1 si les cases ont toutes la même couleur et 0 sinon
*/

int test_same_colour(grid *grille)
{
	int i, j;
	int test;
	test = 1;

	for(i = 0; i < grille->size; i = i+1)
	{
		for(j = 0; j < grille->size; j = j+1)
		{
			if(grille->array[i][j] != grille->array[0][0])
			{
				test = 0;
			}
		}
	}
	return test;
}

/*
	\fn detect_flood(grid *grille)
	\brief identifie la tâche en se basant sur l'algorithme de remplissage par diffusion
	\param *grille adresse de la grille 
	\param x abscisse de l'origine de la tâche
	\param y ordonnée de l'origine de la tâche
	\param couleur couleur de l'origine de la tâche
	\return void c'est une fonction de type void
*/

void detect_flood(grid *g,int x,int y,char couleur)
{
	if(g->array[x][y]==couleur && g->belong[x][y]==0)
	{
		g->belong[x][y]=1;
		if(x-1>=0) 
		{
			detect_flood(g,x-1,y,couleur);
		}
		if(y-1>=0)
		{
			detect_flood(g,x,y-1,couleur);
		}
		if(x+1<g->size)
		{
			detect_flood(g,x+1,y,couleur);
		}
		if(y+1<g->size)
		{
			detect_flood(g,x,y+1,couleur);
		}
	}
}

/*
	\fn change_color(grid *grille, char couleur)
	\brief change la couleur des cases appartenant à la tâche par la couleur entrée en paramètre
	\param *grille adresse de la grille 
	\param couleur la nouvelle couleur à étaler
	\return void c'est une fonction de type void
*/
void change_color(grid *g,char couleur)
{ 
	int n = g->size;
  
	if(test_is_color(couleur))
	{	
		if(n > 0)
		{
			for (int i = 0; i < n; i++)
			{
				for(int j = 0; j < n; j++)
				{
					if(g->belong[i][j] == 1)
					{ 
						set_grid(g, i, j, couleur);
					}
				}
			}
		}
	}
}

/*
	\fn refresh_grid(grid *g)
	\brief remet à 0 le tableau d'appartenance à la tâche
	\param *grille adresse de la grille 
	\return void c'est une fonction de type void
*/
void refresh_grid(grid *g)
{
	int n=g->size;

	for(int i = 0; i < n; i = i+1)
	{
		for(int j = 0; j < n; j = j+1)
		{
			g->belong[i][j]=0;
		}
	}   
}