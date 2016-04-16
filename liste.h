#include <stdio.h>
#include "carte.h"

#ifndef _Liste
#define _Liste

struct cellule {
	CARTE val;
	struct cellule* suiv;};

typedef struct cellule* Liste;

Liste creer_liste(void);
int est_vide(Liste l);
void visualiser_liste(Liste l);
Liste ajout_tete(CARTE c,Liste l);
Liste supprimer_tete(Liste l);
Liste ajout_queue(CARTE c,Liste l);
Liste supprimen(int n,Liste l);

#endif

