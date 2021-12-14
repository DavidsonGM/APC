#include <stdio.h>

int main(){
    int n[500], i, j, a;

    for(i = 0; i < 500; i++){
        a = 0;
        scanf("%d", &n[i]);
        for(j = 0; j <= i; j++){
            if(n[j] == n[i])
            a += 1;
        }
        if(a < 2)
        printf("%d ", n[i]);
        }

printf("\n");

return 0;

}