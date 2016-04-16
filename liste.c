#include "liste.h"
#include "carte.h"
#include <stdio.h>
#include <stdlib.h>

/*int compare(CARTE c1, CARTE c2)
{	if (c1.rang>c2.rang) return -1;
	if (c1.rang==c2.rang) return 0;
	else return 1;
}*/

/*void affiche (CARTE* e) {
  static char* mesc[]={"trefle","carreau","coeur","pique"};
  static char* mesval[] ={"as","2","3","4","5","6","7","8","9","dix","valet","dame","roi"};
  printf("%s de %s ;",mesval[e->rang-1],mesc[e->couleur]);
}*/

/*void affichevisible(CARTE* e) {
  static char* mesc[]={"trefle","carreau","coeur","pique"};
  static char* mesval[] ={"as","2","3","4","5","6","7","8","9","dix","valet","dame","roi"};
  if (e->visible) printf("%s de %s ;",mesval[e->rang-1],mesc[e->couleur]);
}
*/


Liste creer_liste(void)
{	return NULL;
}

int est_vide(Liste l)
{	return !l;
}

void visualiser_liste(Liste l)
{	Liste p=l;
	if (est_vide(p)) printf("liste vide");
	while (!est_vide(p))
	{	affiche(&p->val);
		//printf("%s\n",*p->visible);
		p=p->suiv;
	}
}

Liste ajout_tete(CARTE c,Liste l)
{	Liste p=calloc(1,sizeof(*p));
	if (p==NULL) return NULL;
	p->val.rang=c.rang;
	p->val.couleur=c.couleur;
	p->val.visible=c.visible;
	p->suiv=l;
	return p;
}

Liste supprimer_tete(Liste l)
{	Liste p;
	if (!est_vide(l))
	{	p=l->suiv;
		free(l);
		return p;
	}
	else {printf("liste vide"); return NULL;}
}

Liste ajout_queue(CARTE c,Liste l)
{	Liste p1=l,p2;
	if (est_vide(l)) return ajout_tete(c,l);
	while (!est_vide(p1->suiv))
	{	p1=p1->suiv;
	}
	p2=calloc(1,sizeof(*p2));
	p2->val.rang=c.rang;
	p2->val.couleur=c.couleur;
	p2->val.visible=c.visible;
	p2->suiv=NULL;
	p1->suiv=p2;
	return l;
}

Liste supprimen(int n,Liste l)
{	int i;
	Liste p1=l,p2;
	if (est_vide(l)) {printf("liste vide\n"); return l;}
	if (n<1) {printf("n négatif\n"); return l;} 
	if (n==1) return supprimer_tete(l);
	else 
	{	for(i=1;i<n-1;i++)
		{	if(est_vide(p1->suiv)) { printf("n trop grand\n"); return l;}
			p1=p1->suiv;
		}
		if (p1->suiv==NULL) {printf("n trop grand\n");return l;}
		p2=p1;
		p2=(p2->suiv)->suiv;
		free(p1->suiv);
		p1->suiv=p2;
		return l;
	}
}


/*Liste concat(Liste l1,Liste l2)
{	Liste p1=l1,p2=l2;
	while(est_vide(p1->suiv)) p1=p1->suiv;
	p1->suiv=p2;
	return l1;
}

Liste copie(Liste l)
{	Liste l2,p1=l;
	l2=creer_Liste()
	while (!est_vide(p1->suiv))
	{	ajout_queue(p1->val,l2);
		p1=p1->suiv;
	}
	return l2;
}
*/


