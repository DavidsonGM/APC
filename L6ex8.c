#include <stdio.h>
#include <math.h>

typedef struct lados{
    int x, y;
}lado;

struct Triangle{
    lado a, b, c;
};

double area(struct Triangle t){
	return 0.5*fabs(t.a.x*(t.b.y-t.c.y) + t.b.x*(t.c.y-t.a.y) + t.c.x*(t.a.y-t.b.y));
}
int main(){
    struct Triangle my_tri;
    scanf("%d %d %d %d %d %d", &my_tri.a.x, &my_tri.a.y, &my_tri.b.x, &my_tri.b.y, &my_tri.c.x, &my_tri.c.y);

	double resp  = area(my_tri);
	if(!resp)printf("Nao e um triangulo\n");
	else printf("A area do triangulo e %.2lf\n", resp);
 return 0;
}
