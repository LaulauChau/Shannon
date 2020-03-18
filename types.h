#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct point point_t;

struct element_visites
{
	point_t *p;
	bool visite;
};
typedef struct element_visites e_visites_t;

struct visites
{
	e_visites_t tab[50];
	int taille;
};
typedef struct visites visites_t;

// point
struct point
{
	char nom;
};

// Liste de points
struct points
{
	point_t pts[10];
	short t;
};
typedef struct points points_t;

//liaison entre deux points dans un état donné
struct liaison
{
	point_t p1, p2;
	char etat; // x libre, * construit, ~ cassé
};
typedef struct liaison liaison_t;

// Liste de liaison
struct liaisons
{
	liaison_t l[50];
	int t;
};
typedef struct liaisons liaisons_t;

// element d'une file de points
struct element_point
{
	point_t *p;
	struct element_point *suivant;
};
typedef struct element_point element_p_t;

//file de points (structure FIFO first in first out)
struct file_points
{
	element_p_t *premier;
	element_p_t *dernier;
};
typedef struct file_points file_p_t;
