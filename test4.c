#include "graphe.h"
#include 'liste.h'
#include "element.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    //test de la fonction ajoute_arc
    Graphe g;
    unsigned int depart=2, arrivee=3;
    double valeur=5.6;

    g->nX=3;
    g->nA=3;
    for(i=0;i<4;i++)
    {
        (*(g->stations)+i)->num_station=i;
    }
    puts("Graphe de depart");
    affiche_graphe(g);
    graphe_ajoute_arc(g,depart,arrivee,valeur);
    puts("Graphe apres ajout");
    affiche_graphe(g);

    return 1;
}
