#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#include <locale.h>
#include <math.h>
#include "../../libs/StructClie.h"

/* Sctruct é uma variavel com varias propriedades */


void CadastrarCliente(){

    FILE *FuncFile;
    FuncFile = fopen("./data/clientes.dat", "a"); /* Abre o arquivo somente para adição */

    struct cliente cli; /* Cria uma instancia, da estrutura (Como uma cópia) */

    // printf("Informe o nome do cliente:\n");
    // scanf("%d", &func.category ); /* Isso vai definir como vai ser exibido em "Vizualizar Produto" */

    printf("\e[1;1H\e[2J"); /* Limpa a Tela */
    printf("Informe o nome do cliente:\n");
    gets(cli.nome);
    fflush(stdin);
    printf("Informe o endereco do cliente: \n");
    gets(cli.endereco);
    fflush(stdin);
    printf("Informe o telefone do cliente \n");
    gets(cli.telefone);

    fwrite (&cli, sizeof(struct cliente), 1, FuncFile); /* Grava a estrutura no arquivo */

    if(&fwrite != 0){ /* Se conseguir gravar */
        printf("\e[1;1H\e[2J");
        printf("Cadastro realizado com sucesso !\n\n"); 
    }else{
        printf("\e[1;1H\e[2J"); 
        printf("Erro ao gravar !\n");
    }
    
    fclose(FuncFile);
}

int main()
{
    //Define o padrão UTF-8
    setlocale(LC_ALL, "Portuguese_Brasil");
    //Define a cor azul do terminal
    //system("color 1F");
    //define o titulo da janela do prompt
    //system("title Menu");

    CadastrarCliente();
    
    /* Isso se tornará uma biblioteca de cabeçalho */
    int continuar;

    printf("Deseja voltar ao menu? \n [1] Sim \n [2] Nao\n");
    scanf("%d", &continuar);
    if(continuar == 1){
        system("./source/menu");
    }else{
        printf("Programa Encerrado");
    }

    return 0;
}
