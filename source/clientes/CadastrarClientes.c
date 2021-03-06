#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#include <locale.h>
#include <math.h>
#include "../../libs/structs.h"
#include "../../libs/voltar.h"
#include "../../libs/Mensagem.h"
#include "../../libs/cabSys.h"

/* Sctruct é uma variavel com varias propriedades */


void CadastrarCliente(){

    FILE *FuncFile;
    FuncFile = fopen("./data/clientes.dat", "a"); /* Abre o arquivo somente para adição */

    struct cliente cli; /* Cria uma instancia, da estrutura (Como uma cópia) */

    // printf("Informe o nome do cliente:\n");
    // scanf("%d", &func.category ); /* Isso vai definir como vai ser exibido em "Vizualizar Produto" */

    
    printf("   ------------------------------  Cadastrar Cliente  ------------------------------\n\n");
    printf("                            Informe o nome do cliente....: ");
    gets(cli.nome);
    fflush(stdin);
    printf("                            Informe o endereco do cliente: ");
    gets(cli.endereco);
    fflush(stdin);
    printf("                            Informe o telefone do cliente: ");
    gets(cli.telefone);

    fwrite (&cli, sizeof(struct cliente), 1, FuncFile); /* Grava a estrutura no arquivo */

    if(&fwrite != 0){ /* Se conseguir gravar */
        //printf("\e[1;1H\e[2J");
        //printf("Cadastro realizado com sucesso !\n\n"); 
        sucess();
    }else{
        //printf("\e[1;1H\e[2J"); 
        //printf("Erro ao gravar !\n");
        error();
    }
    
    fclose(FuncFile);
}

int main()
{
    //Define o padrão UTF-8
    setlocale(LC_ALL, "Portuguese_Brasil");
    //Define a cor azul do terminal
    system("color 1F");
    //define o titulo da janela do prompt
    //system("title Menu");

    cab();
    CadastrarCliente();
    
    voltarMenu();

    return 0;
}
