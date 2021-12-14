#include <stdio.h>

struct bilhete{
    int horarioEntrada, horarioSaida, horaEntrada, horaSaida, minEntrada, minSaida, preco;
};
void extrairHoraMin(struct bilhete * bilhetes){
    bilhetes->horaEntrada = bilhetes->horarioEntrada/100;
    bilhetes->horaSaida = bilhetes->horarioSaida/100;
    bilhetes->minEntrada = bilhetes->horarioEntrada%100;
    bilhetes->minSaida = bilhetes->horarioSaida%100;
}

int obterIntervalo(struct bilhete bilhetes){
    int delta;
    delta = (60 * (bilhetes.horarioSaida/100) + (bilhetes.horarioSaida%100)) -(60 * (bilhetes.horarioEntrada/100) + (bilhetes.horarioEntrada%100));
    return delta;    
}

int obterValorEstacionamento(int delta){
    int preco;
    if(delta <= 15)
        preco = 0;
    else 
    if(delta <= 60)
        preco = delta * 30;
    else 
    if(delta <= 120)
        preco = (delta - 60) * 20 + 1800;
    else 
        preco = (delta - 120) * 10 + 3000;
    return preco;
}


int main()
{
    struct bilhete bilhetes[100];
    int contaCentavos, intervalo, receita=0;
    int contadorCarros=0, i, total=0;

    scanf("%d", &bilhetes[contadorCarros].horarioEntrada);
    while (bilhetes[contadorCarros].horarioEntrada>=0)
    {
        do
        {
            scanf("%d", &bilhetes[contadorCarros].horarioSaida);
        }
        while(bilhetes[contadorCarros].horarioSaida < bilhetes[contadorCarros].horarioEntrada);

        extrairHoraMin(&bilhetes[contadorCarros]);
        intervalo = obterIntervalo(bilhetes[contadorCarros]);
        contaCentavos = obterValorEstacionamento(intervalo);
        bilhetes[contadorCarros].preco = contaCentavos;
        printf("Entrada\n%02d:%02d\nSaida\n%02d:%02d\nDuracao(min)\n%d\nPreco(centavos)\n%d\n",bilhetes[contadorCarros].horaEntrada, bilhetes[contadorCarros].minEntrada, bilhetes[contadorCarros].horaSaida, bilhetes[contadorCarros].minSaida,intervalo, bilhetes[contadorCarros].preco);
        total += contaCentavos;
        contadorCarros++;
        scanf("%d", &bilhetes[contadorCarros].horarioEntrada);
    }

    printf("Faturamento total (centavos)\n%d\n", total);

    int inicioIntervalo, finalIntervalo;
    scanf("%d", &inicioIntervalo);
    do
    {
        scanf("%d", &finalIntervalo);
    }
    while (finalIntervalo  < inicioIntervalo);

    for (i = 0; i < contadorCarros ; i++)
    {
        if (bilhetes[i].horarioSaida>inicioIntervalo && bilhetes[i].horarioSaida< finalIntervalo)
        {
            receita += bilhetes[i].preco;
        }
    }

    printf("\nFaturamento no periodo (centavos)\n%d\n", receita);

    return 0;
}
