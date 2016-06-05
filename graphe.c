#include "graphe.h"
#include "liste.h"
#include <stdio.h>
#include <stdlib.h>


/// Fonctions de laure
Graphe nouveau_graphe(unsigned int nX,unsigned int nA)
{
	Graphe g=calloc(1,sizeof(Graphe)); //Allocation de mémoire pour le graphe
	sommet tableau=calloc(nX,sizeof(*tableau)); //Alloctation de mémoire pout le tableau de sommets 
	unsigned int i=0;
    g->stations=tableau;
	g->nX=nX;   // On rentre les valeurs nA et nX dans le tableau
	g->nA=nA;
	for(i=0;i<nX;i++ )// on parcourt les sommets du tableau
    {
        (tableau+i)->arc=creer_liste(); // On alloue de la mémoire aux listes partant des sommets du tableau
    }
	return g;
}

void affiche_graphe(Graphe g)
{	unsigned int i;
	sommet tableau=g->stations;
	for (i=0; i<g->nX; i++)  // On parcourt les sommets du tableau 
	{
        printf("Nom de station : %s\n", tableau[i].nom_station); // on affiche les informations contenues dans chaque sommet
        printf("Nom de ligne : %s\n", tableau[i].nom_ligne);
        printf("Numero de station : %u\n", tableau[i].num_station);
        printf("Poids noeud : %lf\n", tableau[i].poids_noeud);
        visualiser_liste(tableau[i].arc);
	}

}



void detruit_graphe(Graphe g)
{
	unsigned int i;
	sommet tableau=g->stations;
	for (i=0; i<g->nX; i++)
	{
  	free(tableau[i].arc); // On libere les listes partant de chaque sommets
	}
	free(g->stations); // On libere le tableau de sommet
	free(g); // On libere le graphe

}


void graphe_ecrit_nX(Graphe g, unsigned int nX)
{
	g->nX=nX;
}


void graphe_ecrit_nA(Graphe g, unsigned int nA)
{
	g->nA=nA;
}


unsigned int graphe_lit_nX(Graphe g)
{
	return g->nX;
}


unsigned int graphe_lit_nA(Graphe g)
{
	return g->nA;
}

///Fonctions de Caroline

///Revoir les tests de securite

double graphe_lit_poids(Graphe g, unsigned int u)       //lit le poids du noeud u du graphe g
{
    sommet p=(g->stations);
    double poids_noeud;
    if(g==NULL) { printf("graphe vide\n"); exit(1);}
	if(u>g->nX) {printf("la valeur de u (%d) n'est pas comprise entre %d et %u\n", u, 0, g->nX); exit(1);}

    p=p+u;
    poids_noeud=p->poids_noeud;
    return poids_noeud;
}

void graphe_ecrit_poids(Graphe g, unsigned int u, double valeur) //ecrit dans le champ poids_noeud le poids du noeud u du graphe g
{	sommet p=g->stations;

    	if(g==NULL) {printf("graphe vide\n"); exit(1);}

    	(p+u)->poids_noeud=valeur;
}

void graphe_ecrit_poids_arc(Graphe g, unsigned int u, unsigned int v, double valeur)///ameliorer les tests
{
    unsigned int i=0;
    sommet p=NULL;
    Liste l=creer_liste();
    if(g==NULL) {printf("graphe vide\n"); exit(1);}
    if(u>g->nX) {printf("la valeur de u (%d) n'est pas comprise entre %d et %d\n", u, 0, g->nX);exit(1);}

	p=(g->stations)+u;
    l=(p->arc);
    for(i=0;i<=v;i++)
    {
        if(l->suiv==NULL){exit(1);}
		l=l->suiv;
    }
    l->val.poids_arc=valeur;
}

double graphe_lit_poids_arc(Graphe g, unsigned int u, unsigned int v)
{
    double valeur;
    sommet p=NULL;
    Liste l=creer_liste();
    if(g==NULL) {printf("graphe vide\n"); exit(1);}
    p=(g->stations)+u;
    l=(p->arc);
    while(l->suiv!=NULL && l->val.Xdest!=v)
    {
        l=l->suiv;
    }
    valeur=l->val.poids_arc;
    return valeur;
}

///fonctions Haut niveau

Graphe lit_graphe(char* fichier)
{	FILE* fstation=NULL;
	Graphe g;
	sommet p;
	int nX;
	int nA;
	unsigned int nbstation;
	double latitude,longitude;
	char mot[512];
	char *pos;
	unsigned char nmstation[50];
	unsigned char nomligne[50];  //revoir appelation pour la fonction fscanf et fseek
	int nbr_noeud=0;
	int nbr_arc=0;
	unsigned int station_depart;
	unsigned int station_arrivee;
	double poids_arc;

	if ((fstation=fopen(fichier,"r+"))==NULL)  {puts("Erreur ouverture fichier"); exit(1);}
	else
	{	fscanf(fstation,"%d %d",&nX,&nA);
		g=nouveau_graphe(nX,nA);
		printf("nX=%d, nA=%d\n",nX,nA);
		p=g->stations;
		fgets(mot,511,fstation);
		fgets(mot,511,fstation);
		while(fscanf(fstation,"%u %lf %lf %s ",&nbstation,&latitude,&longitude,nomligne)==4)
		{	fgets(nmstation,511,fstation);
			//printf("nbstation=%d, lat=%lf, long=%lf, nomligne=%s,nmstation=%s\n",nbstation,latitude,longitude,nomligne,nmstation);
		        strcpy(p->nom_station,nmstation);//(p->nom_station)=nmstation;
		        if ((pos=strchr(p->nom_station, '\n')) != NULL)
                    *pos = '\0';
 		        strcpy(p->nom_ligne,nomligne);//(p->nom_ligne)=nomligne;
			(p->num_station)=nbstation;
			//printf("nbstation=%d,nomligne=%s,nmstation=%s\n",(p->num_station),p->nom_ligne,p->nom_station);
			p++;
			nbr_noeud++;
//printf("nbnoeud=%d\n",nbr_noeud);
		}
		if(nbr_noeud!=nX) {printf("erreur lecture stations\n"); exit(1);} //exit (1) renvoie une erreur
        fgets(mot,511,fstation);
		while(fscanf(fstation,"%u %u %lf",&station_depart,&station_arrivee,&poids_arc)==3)
		{	//printf("depart=%u, arrivee=%u, valeur=%lf\n",station_depart,station_arrivee,poids_arc);
            graphe_ajoute_arc(g,station_depart,station_arrivee,poids_arc);
			p=(g->stations)+station_depart;
			//printf("nbstation=%d,nomligne=%s,nmstation=%s\n",(p->num_station),p->nom_ligne,p->nom_station);
		    nbr_arc++;
           // printf("nbarc=%d\n",nbr_arc);
		}
		if(nbr_arc!=nA) {printf("erreur lecture arc\n"); exit(1);}
	}
	printf("nX=%u et nA=%u\n", g->nX,g->nA);
	return g;
}

void graphe_ajoute_arc(Graphe g, unsigned int u, unsigned int v, double val)
{	sommet p=g->stations;
	ELEMENT e;
	unsigned int nbrX;

	e.Xdest=v;
	e.poids_arc=val;

	nbrX=g->nX;
	if(nbrX<u) {puts("Erreur station depart non presente\n"); exit(1);}
	p=p+u;
	/*printf("pointeurnom_ligne=%p\n",&(g->stations)->nom_ligne);
	printf("pointeurnumstation=%p\n",&(g->stations)->num_station);*/

		p->arc=ajout_queue(e,p->arc);
	//printf("%p\n",&(g->stations)->nom_ligne);
}

// fonctions chemin:
void bellman(Graphe g, unsigned int s)
{
    unsigned int nonstab= 0, i;
    unsigned int u,v;
    double poids_inf = 10000;
    sommet tableau=g->stations;
    Liste maListe;

    for(i=0; i<graphe_lit_nX(g); i++)
    {
        graphe_ecrit_poids(g, i, poids_inf); // Initialisation des poids des sommets à 10000 (infini)
    }
    graphe_ecrit_poids(g,s,0); // Initialisation du poids du sommet de départ à 0
    while (!nonstab) {
        nonstab = 1;
        for(i=0; i<graphe_lit_nX(g); i++) { // On parcourt tous les sommets
            maListe = tableau[i].arc;
            while (!est_vide(maListe)){ <:: // On parcourt tous les arcs d'un sommet
                u= tableau[i].num_station;
                v= maListe->val.Xdest;
                if( graphe_lit_poids(g, u) + graphe_lit_poids_arc(g,u,v) < graphe_lit_poids(g, v))
                {
                    graphe_ecrit_poids(g,v,graphe_lit_poids(g,u) + graphe_lit_poids_arc(g,u,v));
                    tableau[v].pere=u;
                    nonstab = 0;
                }
                maListe=maListe->suiv;
            }

        }
    }
}




void graphe_pcc(Graphe g, unsigned int u, unsigned int v)
{
    unsigned int position = v;
    unsigned int nbstations=0;
    unsigned int nbchangements=0;
    unsigned int i;
    unsigned int itineraire[100];
    unsigned int changements[100];
    double temps;
    double poids_inf = 10000;
    sommet tableau=g->stations;
    changements[0]=-10;
    itineraire[0] = v;
    //affiche_graphe(g);
    bellman(g, u);
    if ( graphe_lit_poids(g, v)== poids_inf) {
        printf("Aucun itineraire trouve\n");
    }
    else {
        temps = graphe_lit_poids(g, v);
        while(position != u)
        {
            position = tableau[position].pere;
            if (strcmp(tableau[position].nom_ligne, tableau[itineraire[nbstations]].nom_ligne)) {
                //printf("Changement entre %s et %s\n", tableau[itineraire[nbstations]].nom_ligne, tableau[position].nom_ligne);
                changements[nbchangements] = nbstations;
                nbchangements++;
            }
            nbstations++;
            itineraire[nbstations] = position;
        }
        printf("Trajet entre les stations %s et %s :\n\n", tableau[u].nom_station, tableau[v].nom_station);
        printf("Durée du trajet : %lf\n ", temps);
        printf("Nombre de stations : %u\n", nbstations);
        printf("Nombre de changements : %u\n\n", nbchangements);
        printf("Itineraire : (%d etape(s)) \n", nbstations);
        for(i=0; i<nbstations; i++)
        {
            printf("Etape %u : ligne %s, station %u (%s)\n",i+1, tableau[itineraire[i]].nom_ligne, tableau[itineraire[i]].num_station, tableau[itineraire[i]].nom_station);
        }

    }

}
