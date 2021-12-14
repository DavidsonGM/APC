#include <stdio.h>
#include <string.h>

typedef struct filmes{
    char title[100];
    double orc;
    int idx, id, ano, dur, gen;
}Filme;

int main(){
    int i = 0, idx = 1, nlinhas = 0, j;
    Filme filme[10000];
    FILE *fp;
    fp = fopen("locadora.dat", "r+");

    while(fscanf(fp, "%d %s %lf %d %d %d %d", &filme[i].idx, &filme[i].title, &filme[i].orc, &filme[i].id, &filme[i].gen, &filme[i].ano, &filme[i].dur) > 0){
        printf("%d %s %lf %d %d %d %d\n", filme[i].idx, filme[i].title, filme[i].orc, filme[i].id, filme[i].gen, filme[i].ano, filme[i].dur);
        i++;
        nlinhas++;
    }
    
    while(idx > 0){
        rewind(fp);
        scanf("%d", &idx);
        if(idx < 1)
            break;
        scanf("%s %lf %d %d %d %d", &filme[idx - 1].title, &filme[idx - 1].orc, &filme[idx - 1].id, &filme[idx - 1].gen, &filme[idx - 1].ano, &filme[idx - 1].dur);
        for(i = 0; i < nlinhas; i++){
            printf("%d %s %lf %d %d %d %d\n", filme[i].idx, filme[i].title, filme[i].orc, filme[i].id, filme[i].gen, filme[i].ano, filme[i].dur);
            fprintf(fp, "%d %s %lf %d %d %d %d\n", filme[i].idx, filme[i].title, filme[i].orc, filme[i].id, filme[i].gen, filme[i].ano, filme[i].dur);
        }
    }
    fclose(fp);
    return 0;
}