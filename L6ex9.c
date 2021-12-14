#include <stdio.h>
#include <math.h>

struct ponto{
    int x, y;
    double raio;
};

double distance(struct ponto a,struct ponto b){
	return hypot(a.x-b.x,a.y-b.y);
}

int main(){
    int i, achou = 0;
    double distancia[3];
    struct ponto celular, t[3];

    scanf("%d %d", &celular.x, &celular.y);
    for(i = 0; i < 3; i++){
        scanf("%lf %d %d", &t[i].raio, &t[i].x, &t[i].y);
    }

    for(i = 0; i < 3; i++)
        distancia[i] = distance(t[i],celular);
    if(distancia[0] <= t[0].raio && distancia[1] <= t[1].raio && distancia[2] <= t[2].raio) 
            achou = 1;
            
    if(achou)
        printf("Celular encontrado\n");
    else
        printf("Nao foi possivel encontrar\n");

 return 0;
}
