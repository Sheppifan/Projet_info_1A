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

affichage information dans pcc
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
	unsigned int condition;
	unsigned int continuer=1;
	
	char* fichier="metro.csv";
	g=lit_graphe(fichier);
	
	while(continuer==1){
		printf("1 : nouveau trajet\n");
		printf("0 : quitter\n");
		scanf("u\n",&condition);
		switch(condition)
		{	case 1 :
				printf("entrez la station de depart\n");
				scanf("%u\n",&depart);
				printf("entrez la station d'arrivee\n");
				scanf("%u\n",&arrivee);
				pcc(g,depart,arrivee);
				continuer=1;
				break;
			
			case 0 :
				continuer=0;
				break;
		}
	}
	return(1);
}
