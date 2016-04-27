#include "graphe.h"
#include "liste.h"
#include <stdio.h>


/// Fonctions de laure
/*Graphe nouveau_graphe(unsigned int nX,unsigned int nA)
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


void graphe_ecrit_nA(Graphe g, unsigned int nA)


unsigned int graphe_lit_nX(Graphe g)


unsigned int graphe_lit_nA(Graphe g)*/

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
	int nX;
	int nA;
	int nbstation;
	double latitude,longitude;
	char nmstation,nomligne;
	int nbr_noeud;
	int nbr_arc;
	int station_depart;
	int station_arrivee;
	double poids_arc;
	
	if ((fstation=fopen("graphe1.csv","r+"))==NULL)  //exit avec erreur
	else
	{	fscanf(fstation,"%d %d",nX,nA);
		
while (fscanf(fstation,"%s %s %d %lf",element.nom,element.symbole,&element.numeroatomique,&element.masseatomique)==4)
		{
		position=(element.numeroatomique-1)*sizeof(FICHE);
		fseek(fbin,position,0);
		fwrite(&element,sizeof(FICHE),1,fbin);
		}
	fclose(fstation);
}
}

void graphe_ajoute_arc(Graphe g, unsigned int u, unsigned int v, double val)

double graphe_pcc(Graphe g, unsigned int u, unsigned int v)
*/

