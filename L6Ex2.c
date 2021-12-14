#include <stdio.h>
#include <string.h>

typedef struct filmes{
    char title[100];
    double orc;
    int id, ano, dur;
}Filme;

int func(int c[4], Filme filme_desejado, Filme filme){
    int i = 1;
    switch(c[0]){
        case 1:
            if(filme_desejado.ano > filme.ano)
                i = 0;
            break;
        case 2:
            if(filme_desejado.ano < filme.ano)
                i = 0;
            break;
        case 3:
            if(filme_desejado.ano != filme.ano)
                i = 0;
            break;
        case 4:
            if(filme_desejado.ano == filme.ano)
                i = 0;
            break;
    }
    switch(c[1]){
        case 1:
            if(filme_desejado.id > filme.id)
                i = 0;
            break;
        case 2:
            if(filme_desejado.id < filme.id)
                i = 0;
            break;
        case 3:
            if(filme_desejado.id != filme.id)
                i = 0;
            break;
        case 4:
            if(filme_desejado.id == filme.id)
                i = 0;
            break;
    }
    switch(c[2]){
        case 1:
            if(filme_desejado.orc > filme.orc)
                i = 0;
            break;
        case 2:
            if(filme_desejado.orc < filme.orc)
                i = 0;
            break;
        case 3:
            if(filme_desejado.orc != filme.orc)
                i = 0;
            break;
        case 4:
            if(filme_desejado.orc == filme.orc)
                i = 0;
            break;
    }
    switch(c[3]){
        case 1:
            if(filme_desejado.dur > filme.dur)
                i = 0;
            break;
        case 2:
            if(filme_desejado.dur < filme.dur)
                i = 0;
            break;
        case 3:
            if(filme_desejado.dur != filme.dur)
                i = 0;
            break;
        case 4:
            if(filme_desejado.dur == filme.dur)
                i = 0;
            break;
    }
    return i;
}

int main(){
    int mc[4], i = 0, j;
    Filme filme, filme_desejado, filmes_encontrados[100];
    FILE *fp;
    fp = fopen("locadora.dat", "r");
    while(filme_desejado.ano >= 0){
        //scanf("%d", &filme_desejado.ano);
        if(filme_desejado.ano < 0)
            break;
        //scanf("%d %d %d %lf %d %d %d", &mc[0], &filme_desejado.id, &mc[1], &filme_desejado.orc, &mc[2], &filme_desejado.dur, &mc[3]);
        while(fscanf(fp, "%*d %s %lf %d %*d %d %d", &filme.title, &filme.orc, &filme.id, &filme.ano, &filme.dur) > 0){
            //if(!func(mc, filme_desejado, filme)){
                strcpy(filmes_encontrados[i].title, filme.title);
                //i++;
            //}
        }
 
    }
    for(j = 0; j < i; j++)
        printf("%s\n", filmes_encontrados[j].title);
    return 0;
}