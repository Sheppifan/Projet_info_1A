#include <stdio.h>
#include "element.h"

#ifndef _ELEMENT
#define _ELEMENT
typedef struct{
    unsigned int Xdest;     //Numero du noeud de destination
    double poids_arc;       //poids de l'arc ainsi realise
    }   ELEMENT;

#endif // _ELEMENT
#ifndef _Liste
#define _Liste

struct cellule {
	ELEMENT val;
	struct cellule* suiv;};

typedef struct cellule* Liste;

Liste creer_liste(void);
int est_vide(Liste l);
void visualiser_liste(Liste l);
Liste ajout_tete(ELEMENT e,Liste l);
Liste supprimer_tete(Liste l);
Liste ajout_queue(ELEMENT e,Liste l);
Liste supprimen(int n,Liste l);

#endif

