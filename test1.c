#include graphe.c
#include liste.c
#include <stdio.h>

int main()
{
	printf("Test 1\n");
	printf("Donnez nX et nA = 1\n");
	unsigned int  nX,nA;
	nX=2;
	nA=2;
	Graphe g = nouveau_graphe( nX, nA);
	int i;
	sommet* tableau=Graphe->stations
	for (i=0; i<graphe_lit_nX(Graphe g); i++)
	{
		printf("Donnez le nom de station %i\n", i);
		scanf("%c", &nom);
		tableau[i].nom_station=nom;
		getchar();
	}
	printf("Affichage du graphe:\n" );
	affiche_graphe(g);
	detruit_graphe(g);
	printf("graphe detruit\n test affiche");
	affiche_graphe(g);

}