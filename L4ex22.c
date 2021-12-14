#include <stdio.h>

int main(){

int m[7][7], sd = 0, i, j;

for(i = 0; i < 7; i++){
    for(j = 0; j < 7; j++){
        scanf("%d", &m[i][j]);
    }
}
for(i = 0; i < 7; i++){
sd += m[i][i];
}
printf("%d\n",sd);

return 0;

}