#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Contato
{
    int id;
    char nome[50];
    int ano;
    int mes;
    int dia;
    char t_movel[12];
    char t_fixo[11];
    char email[100];
} CONTATO_T;


char readchar()
{
    char c;
    do
    {
        c = getchar();
    }
    while (c == '\n');
    return(c);
}

void imprimir_agenda(FILE *pFile)
{
    CONTATO_T c;
    int conta_registro = 0;

    while (fscanf(pFile,"%d %s %d %d %d %s %s %s", &c.id,c.nome,&c.dia,&c.mes,&c.ano,c.email,c.t_movel,c.t_fixo)!= EOF)
    {
        printf("\n\nContato [%d]\nNome: %s\nNascimento: %02d\\%02d\\%04d\nEmail: %s\nMovel: %s\t Fixo: %s", c.id,c.nome,c.dia,c.mes,c.ano,c.email,c.t_movel,c.t_fixo);
        conta_registro++;
    }

    if (conta_registro ==0)
        printf("\nAGENDA VAZIA\n");
}

void inserir_contato(FILE *pFile)
{   
    FILE *fp;
    int n = 0, i = 0, aux;

    while(fscanf(pFile, "%d %*s %*d %*d %*d %*s %*s %*s", &aux) > 0){
        n++;
    }
    rewind(pFile);

    CONTATO_T contato[n + 1];

    while(i != n){
        fscanf(pFile, "%d %s %d %d %d %s %s %s", &contato[i].id, contato[i].nome, &contato[i].dia, &contato[i].mes, &contato[i].ano, contato[i].email, contato[i].t_movel, contato[i].t_fixo);
        i++;
    }
    fclose(pFile);

    contato[n].id = contato[n - 1].id + 1;
    printf("Entre o Contato[%d]\nNome: ", contato[n].id);
    scanf("%s", contato[n].nome);
    printf("Nascimento dia mes ano: ");
    scanf("%d %d %d", &contato[n].dia, &contato[n].mes, &contato[n].ano);
    printf("Email: ");
    scanf("%s", contato[n].email);
    printf("Movel(11) e fixo(10): ");
    scanf("%s %s", contato[n].t_movel, contato[n].t_fixo);

    fp = fopen("Agenda.dat", "w+");

    for(i = 0; i < n + 1; i++){
        fprintf(fp ,"%d %s %d %d %d %s %s %s\n", contato[i].id, contato[i].nome, contato[i].dia, contato[i].mes, contato[i].ano, contato[i].email, contato[i].t_movel, contato[i].t_fixo);
    }

    fclose(fp);
    rename("Agenda.dat", "agenda.dat");
    pFile = fopen("agenda.dat", "r+");
}


void excluir_contato(FILE *pFile)
{
    int n = 0, i = 0, aux, registro_excluido = 0;

    while(fscanf(pFile, "%d %*s %*d %*d %*d %*s %*s %*s", &aux) > 0){
        n++;
    }
    CONTATO_T contato[n];
    
    rewind(pFile);
    while(i != n){
        fscanf(pFile, "%d %s %d %d %d %s %s %s", &contato[i].id, contato[i].nome, &contato[i].dia, &contato[i].mes, &contato[i].ano, contato[i].email, contato[i].t_movel, contato[i].t_fixo);
        i++;
    }
    fclose(pFile);

    printf("Informe o id do contato a ser excluido: ");
    scanf("%d", &aux);

    FILE *fp = fopen("Agenda.dat", "w+");
    for(i = 0; i < n; i++){
        if(contato[i].id != aux)
            fprintf(fp ,"%d %s %d %d %d %s %s %s\n", contato[i].id, contato[i].nome, contato[i].dia, contato[i].mes, contato[i].ano, contato[i].email, contato[i].t_movel, contato[i].t_fixo);
        if(contato[i].id == aux)
            registro_excluido = 1;
    }

    fclose(fp);
    rename("Agenda.dat", "agenda.dat");
    pFile = fopen("agenda.dat", "r+");

    if(registro_excluido)
        printf("REGISTRO APAGADO COM SUCESSO");
    else
        printf("REGISTRO NAO ENCONTRADO");
}

void editar_contato(FILE * pFile)
{
    int n = 0, i = 0, aux, registro_encontrado = 0;

    while(fscanf(pFile, "%d %*s %*d %*d %*d %*s %*s %*s", &aux) > 0){
        n++;
    }
    rewind(pFile);

    CONTATO_T contato[n];

    while(i != n){
        fscanf(pFile, "%d %s %d %d %d %s %s %s", &contato[i].id, contato[i].nome, &contato[i].dia, &contato[i].mes, &contato[i].ano, contato[i].email, contato[i].t_movel, contato[i].t_fixo);
        i++;
    }

    printf("Informe o id do contato a ser editado: ");
    scanf("%d", &aux);
    for(i = 0; i < n; i++){
        if(contato[i].id == aux){
            registro_encontrado = 1;
            aux = i;
            break;
        }
    }
    if(registro_encontrado){
        if(aux <= contato[n - 1].id)
        printf("Nome: %s\nForneca o novo nome: ", contato[aux].nome);
        scanf("%s", contato[aux].nome);
        printf("Nascimento dia mes ano: %d %d %d\nForneca dia mes ano: ", contato[aux].dia, contato[aux].mes, contato[aux].ano);
        scanf("%d %d %d", &contato[aux].dia, &contato[aux].mes, &contato[aux].ano);
        printf("Email: %s\nForneca email: ", contato[aux].email);
        scanf("%s", contato[aux].email);
        printf("Movel(11) %s e fixo(10): %s\nForneca Movel(11) e fixo(10): ", contato[aux].t_movel, contato[aux].t_fixo);
        scanf("%s %s", contato[aux].t_movel, contato[aux].t_fixo);

        fclose(pFile);
        FILE *fp = fopen("Agenda.dat", "w+");

        for(i = 0; i < n; i++){
            fprintf(fp ,"%d %s %d %d %d %s %s %s\n", contato[i].id, contato[i].nome, contato[i].dia, contato[i].mes, contato[i].ano, contato[i].email, contato[i].t_movel, contato[i].t_fixo);
        }

        printf("REGISTRO ALTERADO COM SUCESSO");
        fclose(fp); 
        rename("Agenda.dat", "agenda.dat");
        pFile = fopen("agenda.dat", "r+");
    }
    else
        printf("REGISTRO NAO ENCONTRADO");
}

void buscar_contato(FILE * pFile)
{
    int n = 0, i = 0, aux, contato_encontrado = 0;
    char Nome[50];

    while(fscanf(pFile, "%d %*s %*d %*d %*d %*s %*s %*s", &aux) > 0){
        n++;
    }
    rewind(pFile);

    CONTATO_T contato[n];

    while(i != n){
        fscanf(pFile, "%d %s %d %d %d %s %s %s", &contato[i].id, contato[i].nome, &contato[i].dia, &contato[i].mes, &contato[i].ano, contato[i].email, contato[i].t_movel, contato[i].t_fixo);
        i++;
    }
    printf("Informe o nome do contato a ser consultado: ");
    scanf("%s", Nome);

    for(i = 0; i < n; i++){
        if(!strcmp(Nome, contato[i].nome)){
            contato_encontrado = 1;
            printf("Nome: %s\nNascimento: %02d\\%02d\\%04d\nEmail: %s\nMovel(11): %s fico(10): %s", contato[i].nome, contato[i].dia, contato[i].mes, contato[i].ano, contato[i].email, contato[i].t_movel, contato[i].t_fixo);
            break;
        }
    }
    if(!contato_encontrado)
        printf("CONTATO NAO ENCONTRADO");    
}

int main()
{
    int opcao = 0;
    FILE * pFileAgenda;

    while (1)
    {
        printf("\n\n");
        printf("\n\nMENU DE OPERACOES NA AGENDA\n\n");
        printf("(1) Imprimir agenda\t\t(2) Inserir contato\n\n");
        printf("(3) Excluir contato\t\t(4) Editar contato\n\n");
        printf("(5) Buscar contato\t\t(6) Sair do programa\n\n\n");

        pFileAgenda = fopen("agenda.dat", "r+");
        if (pFileAgenda == NULL)
        {
            pFileAgenda = fopen("agenda.dat", "w+");
            if (pFileAgenda == NULL)
            {
                printf("Problemas com a abertura do arquivo de dados da agenda");
                exit(0);
            }
        }

        do
        {
            printf("Digite a opcao desejada: ");
            opcao = readchar();
            if (feof(stdin)) break;
        }
        while (opcao < '1'  ||  opcao > '6');

        if (feof(stdin))
        {
            printf("EOF encontrado. Saindo ...\n\n\n");
            break;
        }

        switch (opcao)
        {
        case '1':
            imprimir_agenda(pFileAgenda);
            break;
        case '2':
            inserir_contato(pFileAgenda);
            break;
        case '3':
            excluir_contato(pFileAgenda);
            break;
        case '4':
            editar_contato(pFileAgenda);
            break;
        case '5':
            buscar_contato(pFileAgenda);
            break;
        case '6':
            break;
        default:
            break;
        }

        if (opcao == '6')
        {
            printf("O usuario pediu para sair do programa. Saindo ...\n\n\n");
            break;
        }
        fclose(pFileAgenda);
    }

    exit(0);
}
