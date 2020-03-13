#include <stdio.h>
#include"types.h"



// Ajoute une liaison (libre) à partir des points passés en paramètre à la liste de liaison passée en paramètre. (Sauf si doublon)
liaisons_t add(liaisons_t, point_t, point_t); 


// Change l'état de la liaison pointée
void changerEtat(liaison_t* , char);



// Renvoie la liste des voisins du point passé en paramètre dans la liste de liaison passé en paramètre.
points_t voisins(liaisons_t, point_t);
// Affiche une liaison.
void affLi(liaison_t);

// Affiche une liste de liaison.
void affLs(liaisons_t);

// Affiche une liste de points.
void affPts(points_t);

//Affiche le graphe au format console
void affPlateau();
