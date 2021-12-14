#include <stdio.h>
#include <string.h>

typedef struct filmes{
    char title[100];
    double orc;
    int id, gen, ano, dur;
}Filme;

int main(){
    int i = 0;
    Filme filme;
    FILE *fptr;
    fptr = fopen("locadora.dat", "w");
    while(strcmp(filme.title,"FIM")){
        scanf("%s", &filme.title);
        if(!strcmp(filme.title, "FIM"))
            break;
        scanf("%lf %d %d %d %d",&filme.orc, &filme.id, &filme.gen, &filme.ano, &filme.dur);
        fprintf(fptr, "%d %s %lf %d %d %d %d\n", i + 1, filme.title, filme.orc, filme.id, filme.gen, filme.ano, filme.dur);
        i++;
    }
    fclose(fptr);

    return 0;
}