#define HG1 7
#define LG1 10

#include "core.h"

char graph[HG1][LG1] = {
    {'.', '.', '.', 'A', '.', '.', 'C', '.', '.', 'D'},
    {'.', ' ', ' ', '.', ' ', ' ', '.', ' ', ' ', '.'},
    {'H', '.', '.', 'F', '.', '.', 'E', '.', '.', 'B'},
    {'.', ' ', ' ', '.', ' ', ' ', '.', ' ', ' ', '.'},
    {'.', ' ', ' ', '.', '.', '.', 'G', '.', '.', '.'},
    {'.', ' ', ' ', ' ', ' ', ' ', '.', ' ', ' ', ' '},
    {'.', '.', '.', '.', '.', '.', '.', ' ', ' ', ' '}};

void afficherFile(file_p_t *file)
{
    element_p_t *courant;
    courant = (element_p_t *)malloc(sizeof(element_p_t));
    if (file->premier != NULL)
    {
        courant = file->premier;
        while (courant != NULL)
        {
            printf("Point : %c\n", courant->p->nom);
            courant = courant->suivant;
        }
    }
}

void affLi(liaison_t l)
{
    printf("(%c, %c) : %s \n", l.p1.nom, l.p2.nom, (l.etat == 'x') ? "libre" : ((l.etat == '*') ? "construit" : "détruit"));
}

void affLs(liaisons_t l)
{

    if (!l.t)
    {
        printf("Il n'y a pas de liaison.\n");
        return;
    }
    else
    {
        printf("Liaisons:\n");

        for (int i = 0; i < l.t; i++)
        {
            printf("\t");
            affLi(l.l[i]);
        }
        return;
    }
}

inline void affPts(points_t p)
{
    printf("{");
    char vide = ' ';
    char v = ',';
    for (short i = 0; i < p.t; i++)
    {
        printf(" %c%c", p.pts[i].nom, (p.t == i + 1) ? vide : v);
    }
    printf("}\n");
}

inline void affPlateau()
{
    int i, j;
    for (i = 0; i < HG1; i++)
    {
        for (j = 0; j < LG1; j++)
        {
            printf("%c", graph[i][j]);
        }
        printf("\n");
    }
}
