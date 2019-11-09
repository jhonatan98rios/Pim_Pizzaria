#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#include <locale.h>
#include <math.h>
#include "../../libs/voltar.h"
#include "../../libs/structs.h" 

/* Sctruct é uma variavel com varias propriedades */


char senhaConfirmada[10];

void CadastrarFuncionario(){

    FILE *FuncFile;
    FuncFile = fopen("funcionarios.dat", "a"); /* Abre o arquivo somente para adição */

    struct funcionario func; /* Cria uma instancia, da estrutura (Como uma cópia) */

    printf("Informe o cargo: \n \n [1] Administrativo \n [2] Operacional \n");
    scanf("%d", &func.tipoLogin); /* Isso vai definir como vai ser exibido em "Vizualizar funcionario" */

    
    printf("Nome|Usuário: \n");
    scanf("%s", func.name);

    printf("Infome o CPF: \n");
    scanf("%s", func.cpf);

    printf("Informe a senha: \n");
    scanf("%s", func.senha);

    printf("Confirme sua senha: \n");
    scanf("%s", senhaConfirmada);

    char senhaOk = strcmp(func.senha, senhaConfirmada);/*Compara as senhas digitadas para verificar se é verdadeira*/
    if(senhaOk == 0){
        fwrite (&func, sizeof(struct funcionario), 1, FuncFile); /* Grava a estrutura no arquivo */
        printf("Funcionário salvo com sucesso!\n\n"); 
    }else{
        printf("\e[1;1H\e[2J"); 
        printf("Confirmação de senha inválida!!!\n");
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

    printf("\e[1;1H\e[2J");
    CadastrarFuncionario();
    
    voltarMenu();

    return 0;
}