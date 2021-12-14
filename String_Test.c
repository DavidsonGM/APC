#include <stdio.h>
#include <string.h>

int main(){
    int i;
    char brinquedo[3][20];
    for(i = 0; i < 3; i++){
    scanf("%s", &brinquedo[i]);
    }
    char aux[3][20];
    strcpy(aux[0], brinquedo[0]);
    strcpy(brinquedo[0], brinquedo[1]);
    strcpy(brinquedo[1], aux[0]);

    for(i = 0; i < 3; i++){
        printf("%s\n", brinquedo[i]);
    }
}