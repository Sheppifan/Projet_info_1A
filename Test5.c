#include <stdio.h>
#include "graphe.h"
#include <stdlib.h>


int main()
{

  Graphe g;
  char* fichier="graphe1.csv";
  g=lit_graphe(fichier);

  printf("Donner le umero de station de depart : \n");
  scanf("%d", &depart)

  printf("Donner le umero de station d arrivée : \n");
  scanf("%d", &arrivee);
  pcc(g,depart,arrivée);


}
