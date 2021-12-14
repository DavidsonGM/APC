#include <stdio.h>
#include <string.h>

typedef struct filmes{
    char title[100];
    double orc;
    int idx, id, ano, dur, gen;
}Filme;

int main(){
    int i = 0, idx = 1, nlinhas = 0;
    Filme filme[10000];
    FILE *fp, *fn;
    fp = fopen("locadora.dat", "r");
    fn = fopen("locadora(1).dat", "w");
    while(fscanf(fp, "%d %s %lf %d %d %d %d", &filme[i].idx, filme[i].title, &filme[i].orc, &filme[i].id, &filme[i].gen, &filme[i].ano, &filme[i].dur) > 0){
        printf("%d %s %lf %d %d %d %d\n", filme[i].idx, filme[i].title, filme[i].orc, filme[i].id, filme[i].gen, filme[i].ano, filme[i].dur);
        i++;
        nlinhas++;
    }
    
    while(idx > 0){
        scanf("%d", &idx);
        if(idx < 1)
            break;
        fp = fopen("locadora.dat", "r");
        fn = fopen("locadora(1).dat", "w");
        for(i = 0; i < nlinhas; i++){
            fscanf(fp,"%d %s %lf %d %d %d %d", &filme[i].idx, filme[i].title, &filme[i].orc, &filme[i].id, &filme[i].gen, &filme[i].ano, &filme[i].dur);
            if(filme[i].idx != idx){
                fprintf(fn, "%d %s %lf %d %d %d %d\n", filme[i].idx, filme[i].title, filme[i].orc, filme[i].id, filme[i].gen, filme[i].ano, filme[i].dur);
                printf("%d %s %lf %d %d %d %d\n", filme[i].idx, filme[i].title, filme[i].orc, filme[i].id, filme[i].gen, filme[i].ano, filme[i].dur);
            }
        }
        fclose(fp);
        fclose(fn);
        rename("locadora(1).dat", "locadora.dat");
        nlinhas--;
    }
    return 0;
}