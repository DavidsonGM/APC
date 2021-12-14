#include <stdio.h>

int main(){
    int a[4][5], b[4][5], i, j, soma[4][5];

    for(i = 0; i < 4; i++){
        for(j = 0; j < 5; j++){
            scanf("%d", &a[i][j]);
        }
    }
    for(i = 0; i < 4; i++){
        for(j = 0; j < 5; j++){
            scanf("%d", &b[i][j]);
            soma[i][j] = a[i][j] + b[i][j];

        }
    }
    for(i = 0; i < 4; i++){
        for(j = 0; j < 5; j++){
        printf("%d ", soma[i][j]);
        }
        printf("\n");
    }
return 0;
}

