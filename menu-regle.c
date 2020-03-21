#include <stdio.h>
#include <stdlib.h>

void menu()
{
    char choix;
    printf("Bienvenue dans le jeu de Shannon !\n
            Pour selectionner un niveau, tapez 1, 2, 3 ou 4.\n
            Pour affichier les regles, tapez 0.\n
            Pour sortir du jeu, tapez sur n'importe quel autre touche.");
    scanf(%c, &choix);

    switch (choix)
    {
    case '0':
        regle();
        break;

    case '1':
        // selectionner niveau 1
        break;

    case '2':
        // selectionner niveau 2
        break;

    case '3':
        // selectionner niveau 3
        break;

    case '4':
        // selectionner niveau 4
        break;

    default:
        printf("Merci d'avoir joué, au revoir !\n");
        // quitter le jeu, fin du programme
        break;
    }
}

void regle()
{
    printf("Le jeu de Shannon se joue sur graphe fini avec des noeuds dont deux sont particuliers (D et A).\n
            Chaque noeuds est reliés par un lien.\n
            Le jeu se joue a deux joueurs, un casseur et un lieur.\n
            A chaque tour de jeu, le casseur casse un lien (non incassable) entre deux noeuds et le lieur rend incassable un lien (non casse) entre deux noeuds.\n
            Le casseur gagne la partie lorsqu'il n'y a plus aucun moyen d'aller de D a A. Le lieur gagne la partie lorsqu'il existe un chemin incassable reliant D a A.\n");
}