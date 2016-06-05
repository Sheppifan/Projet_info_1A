
#include "graphe.h"
#include "element.h"
#include "liste.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{	Graphe g;
	unsigned int depart;
	unsigned int arrivee;
	char cond;

	char* fichier="metro.csv";

    printf("Bienvenue dans l'interface d'itineraire\n");
	g=lit_graphe(fichier);
	while(cond!='0')
    {
        printf("1: Nouveau trajet\n");
        printf("0: Quitter\n");
        fflush(stdout);
        cond=getchar();
        switch(cond){
    case '1' :
            printf("nouveau trajet\n");

            printf("Entrez la station de depart\n");
            scanf("%u",&depart);
            printf("Entrez la station d'arrivee\n");
            scanf("%u",&arrivee);

            graphe_pcc(g, depart, arrivee);
            break;

    case '0':
            printf("Quitter\n");
            break;
        }
        getchar();
    }
	return 1;
}

