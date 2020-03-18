#include "types.h"

// ------ core ----- //

// defile le premier point de la file et
point_t *defiler(file_p_t *);

// enfile un element dans la file
void enfiler(file_p_t *, point_t *);

// initialise les pointeurs de la file premier et dernier à NULL
void initFile_pts(file_p_t *);

// Ajoute une liaison (libre) à partir des points passés en paramètre à la liste de liaison passée en paramètre. (Sauf si doublon)
liaisons_t add(liaisons_t, point_t, point_t);

// Change l'état de la liaison pointée
void changerEtat(liaison_t *, char);

// Renvoie la liste des voisins du point passé en paramètre dans la liste de liaison passé en paramètre.
points_t voisins(liaisons_t, point_t);

// ----- IO ------- //

// affiche tous les points d'une file de points.
void afficherFile(file_p_t *);

// Affiche une liaison.
void affLi(liaison_t);

// Affiche une liste de liaison.
void affLs(liaisons_t);

// Affiche une liste de points.
void affPts(points_t);

//Affiche le graphe au format console
void affPlateau();
