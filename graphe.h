#include <stdio.h>
#include "liste.h"
#include "element.h"
#include <stdlib.h>

#ifndef _Graphe
#define _Graphe

/*typedef struct {
    unsigned char nom_station[50];
    unsigned int nmligne;
    unsigned int nX;
    unsigned int nA;
    double poids_noeud;
    Liste arc;
    }* Graphe;*/
// deuxième solution



typedef struct {
	unsigned char nom_station[50];
	unsigned int nbligne;
	double poids_noeud;
	Liste arc;
	}* sommet;

typedef struct {
	sommet stations;
	unsigned int nX;
	unsigned int nA;
	} Graphe;
	
Graphe nouveau_graphe(unsigned int nX,unsigned int nA);
void affiche_graphe(Graphe g);
void detruit_graphe(Graphe g);
void graphe_ecrit_nX(Graphe g, unsigned int nX);
void graphe_ecrit_nA(Graphe g, unsigned int nA);
unsigned int graphe_lit_nX(Graphe g);
unsigned int graphe_lit_nA(Graphe g);

double graphe_lit_poids(Graphe g, unsigned int u);
void graphe_ecrit_poids(Graphe g, unsigned int u, double val);
void graphe_ecrit_poids_arc(Graphe g, unsigned int u, unsigned int v, double val);
double graphe_lit_poids_arc(Graphe g, unsigned int u, unsigned int v);

Graphe lit_graphe(char* fichier);
void graphe_ajoute_arc(Graphe g, unsigned int u, unsigned int v, double val);
double graphe_pcc(Graphe g, unsigned int u, unsigned int v);

#endif // _Graphe
