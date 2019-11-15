#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#include <locale.h>
#include <math.h>
#include "../../libs/voltar.h"
#include "../../libs/structs.h" 
#include "../../libs/cabSys.h"
#include "../../libs/Mensagem.h"

/* Sctruct é uma variavel com varias propriedades */


char senhaConfirmada[10];

void CadastrarFuncionario(){

    FILE *FuncFile;
    FuncFile = fopen(".\\data\\funcionarios.dat", "a"); /* Abre o arquivo somente para adição */

    struct funcionario func; /* Cria uma instancia, da estrutura (Como uma cópia) */

    printf("   ------------------------------Cadastrar Funcionario------------------------------\n\n");

    printf("                              Cargos: [1] Administrativo \n");
    printf("                                      [2] Operacional \n\n");
    printf("                              Informe o cargo....: ");
    scanf("%d", &func.tipoLogin); /* Isso vai definir como vai ser exibido em "Vizualizar funcionario" */

    
    printf("                              Nome|Usuário......: ");
    scanf("%s", func.name);

    printf("                              Infome o CPF.......: ");
    scanf("%s", func.cpf);

    printf("                              Informe a senha....: ");
    scanf("%s", func.senha);

    printf("                              Confirme sua senha.: ");
    scanf("%s", senhaConfirmada);

    char senhaOk = strcmp(func.senha, senhaConfirmada);/*Compara as senhas digitadas para verificar se é verdadeira*/
    if(senhaOk == 0){
        fwrite (&func, sizeof(struct funcionario), 1, FuncFile); /* Grava a estrutura no arquivo */
        sucess();
    }else{
       senhaError();
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
    system("title Menu");

    cab();
    CadastrarFuncionario();
    
    voltarMenu();

    return 0;
}