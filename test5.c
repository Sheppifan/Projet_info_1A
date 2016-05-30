#include <stdio.h>
#include "graphe.h"
#include <stdlib.h>
#include <stdlib.h>



int main()
{
  unsigned int depart,arrivee;
  Graphe g;
  char* fichier="metro.csv";
  g=lit_graphe(fichier);

  printf("Donner le umero de station de depart : \n");
  scanf("%u", &depart);

  printf("Donner le umero de station d arrivée : \n");
  scanf("%u", &arrivee);
  graphe_pcc(g,depart,arrivee);
return 0;

}
