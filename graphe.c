#include "graphe.h"
#include "liste.h"
#include <stdio.h>


/// Fonctions de laure
Graphe nouveau_graphe(unsigned int nX,unsigned int nA)
{
	Graphe* g=calloc(1,sizeof(*g));
	g->nX=nX;
	g->nA=nA;
	sommet* tableau=calloc(nX,sizeof(*tableau));
	return g;
}

void affiche_graphe(Graphe g)
{
	int i; 
	sommet* tableau=g->sommet;
	for (i=0; i<g->nX; i++)
	{
  	visualiser_liste(tableau[i]);
	}
}



void detruit_graphe(Graphe g)
{
	int i; 
	sommet* tableau=g->sommet;
	for (i=0; i<g->nX; i++)
	{
  	free(tableau[i]);
	}
free(g);
	
}


void graphe_ecrit_nX(Graphe g, unsigned int nX)
{
	g->nX=nX;
}


void graphe_ecrit_nA(Graphe g, unsigned int nA)
{
	q->nA=nA;
}


unsigned int graphe_lit_nX(Graphe g)
{
	g->nX;
}


unsigned int graphe_lit_nA(Graphe g)
{
	g->nA;
}

///Fonctions de Caroline

///Revoir les tests de securite

double graphe_lit_poids(Graphe g, unsigned int u)       //lit le poids du noeud u du graphe g
{
    sommet p=(g->stations);
    double poids_noeud;
   //int i=0;
    if(g==NULL) { printf("graphe vide\n"); return 0;}
    /*for(i=0;i<=u;i++)
    {   if(p+1==NULL) { printf("graphe vide\n"); return 0;}
        else p=p+1;
    }*/
    p=p+u;
    poids_noeud=*(p->poids_noeud);
    return poids_noeud;
}

void graphe_ecrit_poids(Graphe g, unsigned int u, double valeur) //ecrit dans le champ poids_noeud le poids du noeud u du graphe g
{
    //Graphe p=g;
    if(g==NULL) printf("graphe vide\n");
    *(((g-<stations)+u)->poids_noeud)=valeur;

}

void graphe_ecrit_poids_arc(Graphe g, unsigned int u, unsigned int v, double valeur)///ameliorer les tests
{
    int i=0;
    Graphe p=g->stations;
    Liste l=creer_liste();
    if(g==NULL) printf("graphe vide\n");
    p=p+u;
    l=*(p->arc);
    for(i=0;i<=v;i++)
    {
        l=l->suiv;
    }
    l->val.poids_arc=valeur;
}

double graphe_lit_poids_arc(Graphe g, unsigned int u, unsigned int v)
{
    double valeur;
    int i=0;
    Graphe p=g->stations;
    Liste l=creer_liste();
    if(g==NULL) printf("graphe vide\n");
    p=p+u;
    l=*(p->arc);
    for(i=0;i<=v;i++)
    {
        l=l->suiv;
    }
    valeur=l->val.poids_arc;
    return valeur;
}

///fonctions Haut niveau

/*Graphe lit_graphe(char* fichier)
{	FILE* fstation=NULL;
	Graphe g;
	sommet p;
	int nX;
	int nA;
	int nbstation;
	double latitude,longitude;
	char* nmstation[50],nomligne[50];  //revoir appelation pour la fonction fscanf et fseek
	int nbr_noeud=0;
	int nbr_arc=0;
	int station_depart;
	int station_arrivee;
	double poids_arc;
	
	if ((fstation=fopen(fichier,"r+"))==NULL)  {puts("Erreur ouverture fichier"); exit(1);}   //revoir la sortie de fionction
	else
	{	fscanf(fstation,"%d %d",nX,nA);
		g=nouveau_graphe(nX,nA);
		p=g->stations;
		if(fseek(fstation,18,SEEK_CUR)!=0) {printf("erreur"); exit(1);}  //revoir fseek
		while(fscanf(fstation,"%d %lf %lf %s %s",nbstation,latitude,longitude,nmstation,nomligne)==5)
		{	*(p->nom_station)=nmstation;
			*(p->nom_ligne)=nomligne;
			*(p->num_station)=nbstation;
			nbr_noeud++;
		}
		if(nbr_noeud!=nX) {printf("erreur lecture stations\n"); exit(1);}
		if(fseek(fstation,38,SEEK_CUR)!=0) {printf("erreur"); exit(1);}  //revoir fseek 
		while(fscanf("%d %d %lf",station_depart,station_arrivee,poids)==3)
		{	graphe_ajoute_arc(g,station_depart,station_arrivee,poids);
			nbr_arc++;
		}
		if(nbr_arc!=nA) {printf("erreur lecture arc\n"); exit(1);}
	}
	return g;
}

void graphe_ajoute_arc(Graphe g, unsigned int u, unsigned int v, double val)

double graphe_pcc(Graphe g, unsigned int u, unsigned int v)
*/

