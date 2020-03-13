struct point{
 	char nom;
};
typedef struct point point_t;

// Liste de point
struct points{
 	point_t pts[10];
	short t;
};
typedef struct points points_t;

struct liaison{
	point_t p1, p2;
	char etat; // x libre, * construit, ~ cassé 
};
typedef struct liaison liaison_t;

// Liste de liaison
struct liaisons{
	liaison_t l [50];
	int t;
};
typedef struct liaisons liaisons_t;

