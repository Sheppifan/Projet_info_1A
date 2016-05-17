#include "graphe.h"
#include "liste.h"
#include <stdio.h>

int main()
{
	printf("Test 1\n");
	printf("On prends nX et nA = 2\n");
	unsigned int  nX,nA;
	unsigned char nom[50];
	nX=2;
	nA=2;
	Graphe g = nouveau_graphe(nX, nA);
	unsigned int i;
	sommet tableau=g->stations;
	for (i=0; i<graphe_lit_nX(g); i++)
	{
		printf("Donnez le nom de station %i\n", i);
		scanf("%s", &nom);
		strcpy(tableau[i].nom_station, nom);
		getchar();
	}


	printf("Affichage du graphe:\n" );
	affiche_graphe(g);
	detruit_graphe(g);
	printf("graphe detruit\n test affiche");
	affiche_graphe(g);

    return 0;
}
