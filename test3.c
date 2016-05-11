#include "graphe.h"
#include "liste.h"
#include "element.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
    Graphe g;
    char* fichier="graphe1.csv";

    g=lit_graphe(fichier);

    affiche_graphe(g);
    return 1;
}
