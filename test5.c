#include <stdio.h>
#include "graphe.h"
#include <stdlib.h>
#include <stdlib.h>
#include <string.h>


int main()
{
  unsigned int depart,arrivee;
  Graphe g;
  char* fichier="graphe1.csv";
  g=lit_graphe(fichier);

  printf("Donner le umero de station de depart : \n");
  scanf("%u", &depart);

  printf("Donner le umero de station d arrivée : \n");
  scanf("%u", &arrivee);
  pcc(g,depart,arrivee);


}
