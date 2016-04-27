#include "liste.h"
#include <stdio.h>
#include <stdlib.h>


/*void affichevisible(CARTE* e) {
  static char* mesc[]={"trefle","carreau","coeur","pique"};
  static char* mesval[] ={"as","2","3","4","5","6","7","8","9","dix","valet","dame","roi"};
  if (e->visible) printf("%s de %s ;",mesval[e->rang-1],mesc[e->couleur]);
}
*/
void affiche(ELEMENT e) {
    printf("destination : %d    ", e.Xdest);
    printf("poids : %lf \n", e.poids_arc);
}

Liste creer_liste(void)
{	return NULL;
}

int est_vide(Liste l)
{	return !l;
}

void visualiser_liste(Liste l)
{	Liste p=l;
	if (est_vide(p)) printf("liste vide\n");
	while (!est_vide(p))
	{	affiche(p->val);
		p=p->suiv;
	}
}

Liste ajout_tete(ELEMENT e,Liste l)
{	Liste p=calloc(1,sizeof(*p));
	if (p==NULL) return NULL;
	p->val.Xdest=e.Xdest;
	p->val.poids_arc=e.poids_arc;
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
	else {printf("liste vide\n"); return NULL;}
}

Liste ajout_queue(ELEMENT e,Liste l)
{	Liste p1=l,p2;
	if (est_vide(l)) return ajout_tete(e,l);
	while (!est_vide(p1->suiv))
	{	p1=p1->suiv;
	}
	p2=calloc(1,sizeof(*p2));
	p2->val.Xdest=e.Xdest;
	p2->val.poids_arc=e.poids_arc;
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

/*int main()
{
    Liste L=creer_liste();
    int Xdest=0;
    double poids=0;
    ELEMENT e;
    int i=0;
    printf("%d\n",est_vide(L));
    for(i=0;i<5;i++)
    {
        printf("entrer element :");
        scanf("%d    %lf",&Xdest,&poids);
        printf("%d\n",Xdest);
        printf("%lf\n",poids);
        e.Xdest=Xdest;
        e.poids_arc=poids;
        L=ajout_tete(e,L);
        visualiser_liste(L);
    }
    L=supprimen(2,L);
    visualiser_liste(L);
    L=supprimer_tete(L);
    return 1;
}*/

/*Liste concat(Liste l1,Liste l2)
{	Liste p1=l1,p2=l2;
	while(est_vide(p1->suiv)) p1=p1->suiv;
	p1->suiv=p2;
	return l1;
}

Liste copie(Liste l)//a modif
{	Liste l2,p1=l;
	l2=creer_Liste()
	while (!est_vide(p1->suiv))
	{	ajout_queue(p1->val,l2);
		p1=p1->suiv;
	}
	return l2;
}
*/


