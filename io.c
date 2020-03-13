#define HG1 7
#define LG1 10


#include"Core.h"



char graph [HG1][LG1]  = {
			{'.','.','.','A','.','.','C','.','.','D'},
			{'.',' ',' ','.',' ',' ','.',' ',' ','.'},
			{'H','.','.','F','.','.','E','.','.','B'},
			{'.',' ',' ','.',' ',' ','.',' ',' ','.'},
			{'.',' ',' ','.','.','.','G','.','.','.'},
			{'.',' ',' ',' ',' ',' ','.',' ',' ',' '},
			{'.','.','.','.','.','.','.',' ',' ',' '}
};


void affLi(liaison_t l){
	printf("(%c, %c) : %s \n", l.p1.nom, l.p2.nom, (l.etat == 'x')?"libre":((l.etat == '*')?"construit":"détruit"));
}

void affLs(liaisons_t l){

	if(!l.t){
		printf("Il n'y a pas de liaison.");
		return;
	}else{
		printf("Liaisons:\n");
		
		for(int i = 0;i<l.t;i++){
			printf("\t");
			affLi(l.l[i]);
		}
		return;
	}
}


inline void affPts(points_t p){
	printf("{");
	char vide = ' ';
	char v = ',';
	for(short i = 0; i<p.t;i++){
		printf(" %c%c",p.pts[i].nom, (p.t==i+1)?vide:v);
			
	}
	printf("}\n");
}

inline void affPlateau(){
	int i,j;
	for(i=0;i<HG1;i++){
		for(j=0;j<LG1;j++){
			printf("%c",graph[i][j]);
		}
		printf("\n");
	}



}

