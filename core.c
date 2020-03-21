#include "core.h"

liaisons_t * filtre_ls(liaisons_t ls, char filtre)
{
	liaisons_t * res;
	res = (liaisons_t *)malloc(sizeof(liaisons_t));
	res->t = 0;	
	for(int i = 0; i < ls.t; i++){
		if(ls.l[i].etat == filtre){
		res->l[res->t] = ls.l[i];
		res->t++;	
		} 		
	}
	return res;
}

liaisons_t * append_ls(liaisons_t ls1, liaisons_t ls2)
{
	liaisons_t * res;
	res = (liaisons_t *)malloc(sizeof(liaisons_t));
	res->t = 0;
	for(int i = 0; i < ls1.t; i++){
		res->l[res->t] = ls1.l[i];
		res->t++;	
				
	}
	for(int i = 0; i < ls2.t; i++){
		res->l[res->t] = ls2.l[i];
		res->t++;	
				
	}
	return res;
}

// parcours en largeur (d'abord verifier si un lien existe entre les points du graphe avec le dfs)
liaisons_t * bfs(liaisons_t * ls, point_t p1, point_t p2)
{
	liaisons_t * chemin;
	chemin = (liaisons_t *) malloc(sizeof(liaisons_t));
	chemin->t=0;

	if (p1.nom == p2.nom){ // TODO
		printf("les points sont identiques, il faut traiter la condition en dehors de la fonction présente : BFS\n");
		return chemin;
	}

	if(!dfs(*ls, p1, p2)){ // TODO
		printf("il n'existe aucune liaison qui relie les points %c et %c et vous n'avez pas vérifié cela avant d'appeler la fonction : BFS, à traiter le chemin vide en dehors de la fonction : BFS \n", p1.nom, p2.nom);	
		return chemin;

	}
	tab_pere_t * tp; 
	tp = (tab_pere_t *) malloc(sizeof(tab_pere_t));
	tp->t=0;
	points_t vs;
	vs.t = 0;

	file_p_t * file; // file de priorité pour l'ordre des points à traiter
	initFile_pts(&file);
	enfiler(file,&p1);

	vs.pts[vs.t] = p1;//le point courant est marqué comme visité	
	vs.t++;



	while(file->premier!=NULL){
		point_t * courant;
		courant = defiler(file);


		points_t * voisins_courant;
		voisins_courant=(points_t*) malloc(sizeof(points_t));
		voisins_courant = voisins(*ls, *courant);
		
		
		
		for(int i = 0; i<voisins_courant->t;i++){

			if(!isIncluded(vs,voisins_courant->pts[i])){

				enfiler(file,&(voisins_courant->pts[i]));//le point courant est à traiter dans la file			
				vs.pts[vs.t] = voisins_courant->pts[i];//le point courant est marqué comme visité	
				vs.t++;

				e_pere_t e;
				e.fils=voisins_courant->pts[i];
				e.pere=*courant;
				tp->tab[tp->t]=e;
				tp->t++;

			}

		}



	}
	
	//parcourir la table des peres depuis p2 pour remonter à p1	
	
	//retrouver P2
	
	char courant;
	courant = p2.nom;
	while(courant!=p1.nom && tp->t){
		for(int i=0;i < tp->t;i++){
			if(tp->tab[i].fils.nom==courant){
				//recuperer la liaison entre le courant et son pere et l'ajouter au chemin
				chemin->l[chemin->t]=*(getLiaison(ls,tp->tab[i].fils,tp->tab[i].pere));
				chemin->t++;
				courant=tp->tab[i].pere.nom;
				break;
			}
		}
	}
	
	return chemin;
	
}

// parcours en profondeur
bool dfs(liaisons_t ls, point_t p1, point_t p2)
{
	if (p1.nom == p2.nom)
		return true;
	points_t *vs;
	vs = (points_t *)malloc(sizeof(points_t));
	vs->t = 0;
	vs->pts[vs->t] = p1;
	vs->t++;


	bool found;
	found = false;


	found = dfs_aux(ls, p1, p2, vs, found);

	free(vs);

	return found;
}

bool dfs_aux(liaisons_t ls, point_t p1, point_t p2, points_t *vs, bool found)
{	
	if(found)
		return found;

	liaisons_t voisins_p1;
	vs->pts[vs->t] = p1;
	vs->t++;
	voisins_p1.t = 0;
	voisins_p1 = l_voisins(ls, p1);
	for (int i = 0; i < voisins_p1.t; i++)
	{
		if (!(isIncluded(*vs, voisins_p1.l[i].p1) && (isIncluded(*vs, voisins_p1.l[i].p2))))
		{		
			if (voisins_p1.l[i].p1.nom == p2.nom)
			{	
				found = true;
				return found;
			}
			if (voisins_p1.l[i].p2.nom == p2.nom)
			{
				found = true;
				return found;
			}
			point_t p = (voisins_p1.l[i].p1.nom == p1.nom) ? voisins_p1.l[i].p2 : voisins_p1.l[i].p1;
			found = dfs_aux(ls, p, p2, vs, found);
			
		}
		if(found)
		return found;
	}
	return found;
}

bool isIncluded(points_t vs, point_t p)
{
	for (int i = 0; i < vs.t; i++)
	{
		if (vs.pts[i].nom == p.nom)
			return true;
	}
	return false;
}

liaisons_t l_voisins(liaisons_t l, point_t p)
{

	liaisons_t voisins;
	voisins.t = 0;

	for (int i = 0; i < l.t; i++)
	{
		if (l.l[i].p1.nom == p.nom)
		{
			voisins.l[voisins.t] = l.l[i];
			voisins.t++;
		}
		if (l.l[i].p2.nom == p.nom)
		{
			voisins.l[voisins.t] = l.l[i];
			voisins.t++;
		}
	}

	return voisins;
}

// renvoie NULL quand la file est vide et devrait être géré pendant le defilage
point_t *defiler(file_p_t *file)
{
	if (file->premier == NULL){
		return NULL;
	}
	element_p_t *premier;
	premier = file->premier;
	if (file->premier->suivant == NULL)
	{
		file->premier = NULL;
		file->dernier = NULL;
	}
	else
	{
		file->premier = file->premier->suivant;
	}
	point_t *p;
	p = premier->p;
	free(premier);

	// printf("je defile %c\n",p->nom);
	return p;
}

void enfiler(file_p_t *file, point_t *p)
{
	element_p_t *e;
	e = (element_p_t *)malloc(sizeof(element_p_t));
	e->p = p;
	e->suivant = NULL;
	
	// printf("j'enfile %c\n",p->nom);

	if (file->dernier == NULL)
	{
		file->premier = (element_p_t *)malloc(sizeof(element_p_t));
		file->dernier = (element_p_t *)malloc(sizeof(element_p_t));
		file->premier = e;
		file->dernier = e;
		return;
	}
	else
	{
		file->dernier->suivant = (element_p_t *)malloc(sizeof(element_p_t));
		file->dernier->suivant = e;
		file->dernier = e;
		return;
	}
}

void initFile_pts(file_p_t **file)
{
	*file = (file_p_t *)malloc(sizeof(file_p_t));
	(*file)->premier = NULL;
	(*file)->dernier = NULL;
}

points_t * voisins(liaisons_t l, point_t p)
{

	points_t * voisins;
	voisins=(points_t*) malloc(sizeof(points_t));
	voisins->t = 0;

	for (int i = 0; i < l.t; i++)
	{
		if (l.l[i].p1.nom == p.nom)
		{
			voisins->pts[voisins->t] = l.l[i].p2;
			voisins->t++;
		}
		if (l.l[i].p2.nom == p.nom)
		{
			voisins->pts[voisins->t] = l.l[i].p1;
			voisins->t++;
		}
	}

	return voisins;
}

liaison_t * getLiaison(liaisons_t *ls, point_t pt1, point_t pt2){
	liaison_t *l;
	l=NULL;
	for (int i = 0; i < ls->t; i++)
	{
		if ((ls->l[i].p1.nom == pt1.nom && ls->l[i].p2.nom == pt2.nom) || (ls->l[i].p1.nom == pt2.nom && ls->l[i].p2.nom == pt1.nom))
		{
			l=&(ls->l[i]);
			break;
		}
	}
	return l;



}

liaisons_t add(liaisons_t ls, point_t pt1, point_t pt2)
{
	liaisons_t result;

	result.t = ls.t + 1;

	for (int i = 0; i < ls.t; i++)
	{
		if ((ls.l[i].p1.nom == pt1.nom && ls.l[i].p2.nom == pt2.nom) || (ls.l[i].p1.nom == pt2.nom && ls.l[i].p2.nom == pt1.nom))
		{
			printf("erreur la liaison [%c, %c] est deja présente.\n", pt1.nom, pt2.nom);
			return ls;
		}
		result.l[i] = ls.l[i];
	}

	liaison_t temp;
	temp.p1 = pt1;
	temp.p2 = pt2;
	temp.etat = 'x';
	result.l[result.t - 1] = temp;

	return result;
}

inline void changerEtat(liaison_t *l, char e)
{
	(*l).etat = e;
}

int main(void)
{

	printf("Hello wild !\n");

	point_t a, b, c, d, e, f, g, h;

	a.nom = 'A';
	b.nom = 'B';
	c.nom = 'C';
	d.nom = 'D';
	e.nom = 'E';
	f.nom = 'F';
	g.nom = 'G';
	h.nom = 'H';

	liaisons_t ls;
	ls.t = 0;

	ls = add(ls, a, c);
	ls = add(ls, c, d);
	ls = add(ls, d, b);
	ls = add(ls, c, e);
	ls = add(ls, e, b);
	ls = add(ls, e, f);
	ls = add(ls, e, g);
	ls = add(ls, f, a);
	ls = add(ls, f, g);
	ls = add(ls, h, f);
	ls = add(ls, g, b);
	ls = add(ls, h, g);
	ls = add(ls, h, a);
	
	liaison_t * l;
	l = (liaison_t *)malloc(sizeof(liaison_t));
	l = getLiaison(&ls, d, b);
	
	affLi(*l);
	changerEtat(l, '~');
	affLi(*l);	

	l = getLiaison(&ls, e, b);
	
	affLi(*l);
	changerEtat(l, 'c');
	affLi(*l);	

	l = getLiaison(&ls, g, b);
	
	affLi(*l);
	changerEtat(l, '~');//ici
	affLi(*l);

	l = getLiaison(&ls, g, f);
	
	affLi(*l);
	changerEtat(l, '*');
	affLi(*l);	
	
	liaisons_t * construit;
	construit = (liaisons_t *)malloc(sizeof(liaisons_t));
	construit = filtre_ls(ls, '*');
	affLs(*construit);

	liaisons_t * detruit;
	detruit = (liaisons_t *)malloc(sizeof(liaisons_t));
	detruit = filtre_ls(ls, '~');
	affLs(*detruit);

	liaisons_t * libre;
	libre = (liaisons_t *)malloc(sizeof(liaisons_t));
	libre = filtre_ls(ls, 'x');
	affLs(*libre);

	printf("Avant\n");
	liaisons_t * construit_plus_libre;
	construit_plus_libre = (liaisons_t *)malloc(sizeof(liaisons_t));
	construit_plus_libre = append_ls(*construit, *libre);
	affLs(*construit_plus_libre);
	printf("Après\n");

	if(dfs(*construit_plus_libre,a, b))
		printf("(A, B) liable.\n");	
	else
		printf("(A, B) pas liable.\n");

	liaisons_t * chemin;
	printf("1\n");
	chemin = (liaisons_t *)malloc(sizeof(liaisons_t));
	printf("1 bef\n");
	chemin = bfs(construit_plus_libre, a, b);
	printf("post BFS1\n");
	affLs(*chemin);
	printf("1\n");

	points_t *p;
	p->t = 0;

	p = voisins(ls, a);
	affPts(*p);
	p = voisins(ls, b);
	affPts(*p);
	p = voisins(ls, c);
	affPts(*p);
	p = voisins(ls, d);
	affPts(*p);
	p = voisins(ls, e);
	affPts(*p);
	p = voisins(ls, f);
	affPts(*p);
	p = voisins(ls, g);
	affPts(*p);
	p = voisins(ls, h);
	affPts(*p);

	liaisons_t voisins;
	voisins.t = 0;
	voisins = l_voisins(ls, a);
	affLs(voisins);
	voisins = l_voisins(ls, b);
	affLs(voisins);
	voisins = l_voisins(ls, c);
	affLs(voisins);
	voisins = l_voisins(ls, d);
	affLs(voisins);
	voisins = l_voisins(ls, e);
	affLs(voisins);
	voisins = l_voisins(ls, f);
	affLs(voisins);
	voisins = l_voisins(ls, g);
	affLs(voisins);
	voisins = l_voisins(ls, h);
	affLs(voisins);

	affLs(ls);

	if (dfs(ls, e, e))
		printf("Vrai\n");
	else
		printf("Faux\n");
	if (dfs(ls, d, d))
		printf("Vrai\n");
	else
		printf("Faux\n");
	if (dfs(ls, d, b))
		printf("Vrai\n");
	else
		printf("Faux\n");
	if (dfs(ls, d, c))
		printf("Vrai\n");
	else
		printf("Faux\n");
	if (dfs(ls, d, e))
		printf("Vrai\n");
	else
		printf("Faux\n");
	if (dfs(ls, d, f))
		printf("Vrai\n");
	else
		printf("Faux\n");

	if (dfs(ls, d, h))
		printf("Vrai\n");
	else
		printf("Faux\n");
	if (dfs(ls, d, g))
		printf("Vrai\n");
	else
		printf("Faux\n");

	affPlateau();

	liaisons_t * chemin2;
	chemin2 = bfs(&ls, h,d);
	if(chemin2!=NULL)
		affLs(*chemin2);
	else
		printf("chemin NULL");

	


}
