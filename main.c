#include "graphe.h"
#include "element.h"
#include "liste.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
charger le fichier.csv et creer le graphe

demande station départ

demande station arrivee

belleman et plus court chemin

affichage information:
	trajet
	temps de trajet
	

voir affichage
voir retour sur case
	nouveau trajet
	terminee
	


*/

int main()
{	Graphe g;
	//unsigned char depart[50];
	//unsigned char arrivee[50];
	unsigned int depart;
	unsigned int arrivee;
	
	char* fichier="metro.csv";
	
	g=lit_graphe(fichier);
	
	
	printf("entrez la station de depart\n");
	scanf("%u\n",&depart);
	printf("entrez la station d'arrivee\n");
	scanf("%u\n",&arrivee);

	ppc(g,depart,arrivee);

		
	












	return 1;
}
