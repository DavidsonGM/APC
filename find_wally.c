#include <stdio.h>

int main(int argc, char **argv){
    int M[625][1000], m[72][44], i, j, k, l, posicao_wally[2], diferenca[554][957] = {0}, menor_diferenca = 807841, maior_diferenca = 0;
    char lines[100];
    FILE *fp, *fi, *fd, *fq;
    if(argc < 3){
        printf("Digite ao menos 2 argumentos\n");
        return 0;
    }
    if(argc > 2){
        fp = fopen(argv[1], "r");
        fi = fopen(argv[2], "r");
        for(i = 0; i < 4; i++){
        fgets(lines, 100, fp);
        fgets(lines, 100, fi);
        }
        for(i = 0; i < 72; i++){
            for(j = 0; j < 44; j++){
                fscanf(fp, "%d", &m[i][j]);
            }
        }
        for(i = 0; i < 625; i++){
            for(j = 0; j < 1000; j++){
                fscanf(fi, "%d", &M[i][j]);
            }
        }
        for(k = 0; k < 554; k++){
            for(l = 0; l < 957; l++){
                for(i = 0; i < 72; i++){
                    for(j = 0; j < 44; j++){
                        if(m[i][j] > M[k + i][l + j])
                            diferenca[k][l] += m[i][j] - M[k + i][l + j];
                        if(M[k + i][l + j] > m[i][j])
                            diferenca[k][l] += M[k + i][l + j] - m[i][j];                    
                    }
                }
                if(diferenca[k][l] < menor_diferenca){
                    menor_diferenca = diferenca[k][l];
                    posicao_wally[0] = k;
                    posicao_wally[1] = l;
                }
                if(diferenca[k][l] > maior_diferenca)
                    maior_diferenca = diferenca[k][l];
            }
        }
        printf("Template found at row=%d, col=%d. Difference=%lf\n", posicao_wally[0], posicao_wally[1], (double)menor_diferenca);
        fclose(fp);
        fclose(fi);
    }
    if(argc > 3){
        fd = fopen(argv[3], "w");
        fprintf(fd, "P2\n957 554\n255\n");
        for(k = 0; k < 554; k++){
            for(l = 0; l < 957; l++){
                diferenca[k][l] *= 255/(double)maior_diferenca;
                fprintf(fd, "%d  ", diferenca[k][l]);
            }
            fprintf(fd, "\n");
        }
        fclose(fd);
    }
    if(argc > 4){
        fq = fopen(argv[4], "w");
        fprintf(fq, "P2\n1000 625\n255\n");
        for(i = 0; i < 625; i++){
            for(j = 0; j < 1000; j++){
                if(!(i >= posicao_wally[0] && i <= posicao_wally[0] + 72 && j >= posicao_wally[1] && j <= posicao_wally[1] + 44)){
                    M[i][j] -= 128;
                    if(M[i][j] < 0)
                        M[i][j] = 0;
                }
            fprintf(fq, "%d  ", M[i][j]);
            }
        fprintf(fq, "\n");
        }
        fclose(fq);
    }
    return 0;
}