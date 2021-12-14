#include <stdio.h>
#include <math.h>

typedef struct Pontos{
    int x, y, idx;
}pontos;
int main(){
    int i, n, p1, p2, menord, menord_idx = 0;
    FILE *fp;
    fp = fopen("pontos.dat", "r");

    while(fscanf(fp,"%d %*d %*d", &n) > 0){}
    rewind(fp);

    pontos ponto[n];
    int d[n - 2];
    menord = d[0];

    scanf("%d %d", &p1, &p2);

    for(i = 0; i < n; i++)
        fscanf(fp, "%d %d %d", &ponto[i].idx, &ponto[i].x, &ponto[i].y);
    for(i = 0; i < n; i++){
        if(i != p1 && i != p2){
            d[i] = sqrt((ponto[i].x*(ponto[p1].y - ponto[p2].y) + ponto[i].y*(ponto[p2].x - ponto[p1].x) + (ponto[p1].x*ponto[p2].y - ponto[p2].x*ponto[p1].y))*(ponto[i].x*(ponto[p1].y - ponto[p2].y) + ponto[i].y*(ponto[p2].x - ponto[p1].x) + (ponto[p1].x*ponto[p2].y - ponto[p2].x*ponto[p1].y)));
            if(d[i] < menord){
                menord = d[i];
                menord_idx = i;
            }
        }     
    }
    printf("%d\n", menord_idx);
    fclose(fp);

    return 0;
}