#include"Core.h"

points_t voisins(liaisons_t l, point_t p){
	
	points_t voisins;
	voisins.t = 0;
	
	for(int i = 0; i < l.t ; i++){
		if(l.l[i].p1.nom==p.nom){
			voisins.pts[voisins.t]=l.l[i].p2; 
			voisins.t++;
		}
		if(l.l[i].p2.nom==p.nom){
			voisins.pts[voisins.t]=l.l[i].p1; 
			voisins.t++;
		}
		

	}

	return voisins;


}


liaisons_t add(liaisons_t ls, point_t pt1, point_t pt2){
	liaisons_t result;

	result.t = ls.t+1;
	
	for(int i=0; i<ls.t;i++){
		if((ls.l[i].p1.nom==pt1.nom && ls.l[i].p2.nom==pt2.nom)||(ls.l[i].p1.nom==pt2.nom && ls.l[i].p2.nom==pt1.nom)){
			printf("erreur la liaison [%c, %c] est deja présente.\n", pt1.nom, pt2.nom);
			return ls;
		}
		result.l[i]=ls.l[i];
	}
	
	liaison_t temp;
	temp.p1 = pt1;
	temp.p2 = pt2;
	temp.etat = 'x';
	result.l[result.t-1]= temp;
	
	return result;
	
}


inline void changerEtat(liaison_t * l, char e){
	(*l).etat = e;
}


int main(void){

	printf("Hello wild !\n");
	

	point_t a, b, c, d,e,f,g,h;
		
	a.nom='A';
	b.nom='B';
	c.nom='C';
	d.nom='D';
	e.nom='E';
	f.nom='F';
	g.nom='G';
	h.nom='H';

	liaisons_t ls;
	ls.t=0;

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

	points_t p;
	p.t=0;

	p = voisins(ls, a);
	affPts(p);
	p = voisins(ls, b);
	affPts(p);
	p = voisins(ls, c);
	affPts(p);
	p = voisins(ls, d);
	affPts(p);
	p = voisins(ls, e);
	affPts(p);
	p = voisins(ls, f);
	affPts(p);
	p = voisins(ls, g);
	affPts(p);
	p = voisins(ls, h);
	affPts(p);


	affLs(ls);
	
	affPlateau();
}


