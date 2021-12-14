#include <stdio.h>
#include <string.h>

int main(){
    char str[100], reverse[100];
    int i, tamanho, j;

    scanf("%[^\n]", str);
    tamanho = strlen(str);

    for(i = 0; i < tamanho; i++){
        for(j = (tamanho - 1); j >= 0; j--){
            reverse[i] = str[j];
        }
    }
    for(i = 0; i < tamanho; i++){
    printf("%c", reverse[i]);
    }
return 0;
}