#include "graphe.h"
#include "element.h"
#include "liste.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{	Graphe g;
	unsigned  int depart;
	unsigned int arrivee;
	char cond;

	char* fichier="metro.csv";

    printf("Bienvenu dans l'interface d'itineraire\n");
	g=lit_graphe(fichier);
	while(cond!='0')
    {
        printf("1:nouveau trajet\n");
        printf("0: quitter\n");
        fflush(stdout);
        cond=getchar();
        switch(cond){
    case '1' :
            printf("nouveau trajet\n");

            printf("entrez la station de depart\n");
            scanf("%u\n",&depart);
            printf("entrez la station d'arrivee\n");
            scanf("%u\n",&arrivee);

            pcc(g, depart, arrivee)
            break;

    case '0':
            printf("quitter\n");
            break;
        }
        getchar();
    }
	return 1;
}

