#include <stdio.h>

int conferir_contagem(int my_hand[5]){
    int conferircontagem = 1, i;
    for(i = 0; i < 4; i++){
        if(my_hand[i] > my_hand[i + 1])
            conferircontagem = 0;
    }
	return conferircontagem;
}

void corrigir_contagem(int my_hand[5]){
    int aux, i, j;
    for(j = 0; j < 5; j++){
        for(i = 0; i < 4; i++){
            if(my_hand[i] > my_hand[i + 1]){
                aux = my_hand[i];
                my_hand[i] = my_hand[i + 1];
                my_hand[i + 1] = aux;
            }
        }
    }

}
	
int main(){
	int i, mao[5];
	for(i=0; i<5; ++i)
		scanf("%d", &mao[i]);

	if(conferir_contagem(mao))printf("Contagem Correta\n");
	else{
		printf("Contagem Incorreta\n");
		printf("Sequencia certa: ");
		corrigir_contagem(mao);
		for(i=0; i<5; ++i)
			printf("%d%c", mao[i], ((i==4)? '\n' : ' '));
	}

 return 0;
}
