#include "graphe.h"
#include "liste.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/// Fonctions de laure
Graphe nouveau_graphe(unsigned int nX,unsigned int nA)
{
	Graphe g=calloc(1,sizeof(Graphe));
	sommet tableau=calloc(nX,sizeof(*sommet));
	unsigned int i=0;
    g->stations=tableau;
	g->nX=nX;
	g->nA=nA;
	for(i=0;i<nX;i++ )
    {
        (tableau+i)->arc=creer_liste();
    }
	return g;
}

void affiche_graphe(Graphe g)
{	unsigned int i;
	sommet tableau=g->stations;
	for (i=0; i<g->nX; i++)
	{
        printf("Nom de station : %s\n", tableau[i].nom_station);
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
  	free(tableau[i].arc);
	}
	free(g->stations);
	free(g);

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
    if(g==NULL) { printf("graphe vide\n"); return 0;}	//Il faut retourner une erreur type VALUE ERROR
	if(u<1 || u>g->nX) exit(1);

    p=p+u;
    poids_noeud=p->poids_noeud;
    return poids_noeud;
}

void graphe_ecrit_poids(Graphe g, unsigned int u, double valeur) //ecrit dans le champ poids_noeud le poids du noeud u du graphe g
{
    if(g==NULL) {printf("graphe vide\n"); exit(1);}
	if(u<1 || u>g->nX) exit(1);

    (*((g->stations)+u)).poids_noeud=valeur;
}

void graphe_ecrit_poids_arc(Graphe g, unsigned int u, unsigned int v, double valeur)///ameliorer les tests
{
    unsigned int i=0;
    sommet p=NULL;
    Liste l=creer_liste();
    if(g==NULL) {printf("graphe vide\n"); exit(1);}
    if(u<1 || u>g->nX) exit(1);

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
    unsigned int i=0;
    sommet p=NULL;
    Liste l=creer_liste();
    if(g==NULL) {printf("graphe vide\n"); exit(1);}
    p=(g->stations)+u;
    l=(p->arc);
    for(i=0;i<=v;i++)
    {
		if(l->suiv==NULL) {exit(1);}
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
			printf("nbstation=%d, lat=%lf, long=%lf, nomligne=%s,nmstation=%s\n",nbstation,latitude,longitude,nomligne,nmstation);
		        strcpy(p->nom_station,nmstation);//(p->nom_station)=nmstation;
 		        strcpy(p->nom_ligne,nomligne);//(p->nom_ligne)=nomligne;
			(p->num_station)=nbstation;
			printf("nbstation=%d,nomligne=%s,nmstation=%s\n",(p->num_station),p->nom_ligne,p->nom_station);
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
			printf("nbstation=%d,nomligne=%s,nmstation=%s\n",(p->num_station),p->nom_ligne,p->nom_station);
		    nbr_arc++;
           // printf("nbarc=%d\n",nbr_arc);
		}
		if(nbr_arc!=nA) {printf("erreur lecture arc\n"); exit(1);}
	}
	return g;
}

void graphe_ajoute_arc(Graphe g, unsigned int u, unsigned int v, double val)
{	sommet p=g->stations;
	ELEMENT e;
	unsigned int nbrX;
    printf("%s\n",p->nom_ligne);
	e.Xdest=v;
	e.poids_arc=val;
    printf("%s\n",p->nom_ligne);
	nbrX=g->nX;
	if(nbrX<u) {puts("Erreur station depart non presente\n"); exit(1);}
	p=p+u;
	/*printf("pointeurnom_ligne=%p\n",&(g->stations)->nom_ligne);
	printf("pointeurnumstation=%p\n",&(g->stations)->num_station);*/

		p->arc=ajout_queue(e,p->arc);
	//printf("%p\n",&(g->stations)->nom_ligne);
}

/*double graphe_pcc(Graphe g, unsigned int u, unsigned int v)
*/

