#include <stdio.h>
#include "graphe.h"
#include <stdlib.h>

int main()
{	ELEMENT e;
	Graphe g;
	sommet p;
	Liste A=creer_liste();
	unsigned int nX,nA,i;
	double val1, val2,lecture;
	unsigned int u,v;
	
	nX=3;
	nA=6;
	val1=2.6;
	val2=8.4;
	e.poids_arc=0;
	u=1;
	v=2;
		
	
	//creation du graphe de parametre nX et nA permettant de tester les fonctions
	g=nouveau_graphe(nX,nA);
	p=g->stations;
	for (i=0;i<nX;i++)
	{	p->num_station=i;
		A=p->arc;
		e.Xdest=i+1;
		A=ajout_tete(e,A);
		e.Xdest=i;
		A=ajout_tete(e,A);
		p=p+1;
	}
	
	//Visualisation du graphe
	affiche_graphe(g);
	
	//test fonction ecrit poids
	puts("ecriture poids sommet\n");
	graphe_ecrit_poids(g,u,val1);
	affiche_graphe(g);
	
	//test fonction lit_poids
	puts("lecture du poids du sommet u");
	lecture=graphe_lit_poids(g,u);
	printf("valeur voulue : %lf     valeur obtenue : %lf /n",val1,lecture);
	
	//test fonction ecrit poids arc
	puts("ecriture poids arc");
	graphe_ecrit_poids_arc(g,u,v,val2);
	affiche_graphe(g);
	
	//test fonction lit poids arc
	puts("lecture poids arc");
	lecture=graphe_lit_poids_arc(g,u,v);
	printf("valeur voulue : %lf     valeur obtenue : %lf /n",val2,lecture);

}	


/*double graphe_lit_poids(Graphe g, unsigned int u);
void graphe_ecrit_poids(Graphe g, unsigned int u, double val);
void graphe_ecrit_poids_arc(Graphe g, unsigned int u, unsigned int v, double val);
double graphe_lit_poids_arc(Graphe g, unsigned int u, unsigned int v);

*/