#include <stdio.h>

int main(){
    int x[10], y[10], i, j, a, b;
    for(i = 0; i < 10; i++){
        scanf("%d", &x[i]);
    }
    for(i = 0; i < 10; i++){
        scanf("%d", &y[i]);
    }
    for(i = 0; i < 10; i++){
        b = 0;    
        for(j = 0; j <= i; j++){
        if(x[i] == x[j])
        b += 1;
        }
        if(b < 2)
        printf("%d ", x[i]);
    }
    for(i = 0; i < 10; i++){
        b = 0;
        for(j = 0; j <= i; j++){
            if(y[i] == y[j])
            b += 1;
        }
        for(j = 0; j < 10; j++){
            if(y[i] == x[j])
            b += 1;
        }
        if(b < 2)
        printf("%d ", y[i]);
    }
    printf("\n");
    for(i = 0; i < 10; i++){
        a = 0;
        b = 0;
        for(j = 0; j < 10; j++){
            if(x[i] == y[j])
            a = 1;
        }
        for(j = 0; j <= i; j++){
            if(x[i] == x[j])
            b += 1;
        }
        if(a != 1 && b < 2)
        printf("%d ", x[i]);
    }
    printf("\n");
    for(i = 0; i < 10; i++){
        a = 0;
        b = 0; 
        for(j = 0; j < 10; j++){
            if(x[i] == y[j])
            a = 1;
        }
        for(j = 0; j <= i; j++){
           if(x[i] == x[j])
           b += 1;
        }
        if(b < 2 && a == 1)
        printf("%d ", x[i]);
    }
    printf("\n");

    return 0;
}