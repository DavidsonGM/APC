#include <stdio.h>

int main(){

int m[4][5], maior = 0, i, j, mi, mj;

for(i = 0; i < 4; i++){
    for(j = 0; j < 5; j++){
        scanf("%d", &m[i][j]);
        if(m[i][j] > maior){
            maior = m[i][j];
            mi = i;
            mj = j;
        }
    }
}
    printf("%d %d %d\n", maior, mi, mj);
    return 0;
}
