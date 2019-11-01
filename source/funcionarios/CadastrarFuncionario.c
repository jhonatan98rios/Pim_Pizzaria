#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#include <locale.h>
#include <math.h>

/* Sctruct é uma variavel com varias propriedades */
struct funcionario{
    int category; /* Define se é pizza, bebida ou doce */
    char name[10];
    char senha[10];
};

void CadastrarFuncionario(){

    FILE *FuncFile;
    FuncFile = fopen("./data/funcionarios.dat", "a"); /* Abre o arquivo somente para adição */

    struct funcionario func; /* Cria uma instancia, da estrutura (Como uma cópia) */

    printf("Informe o tipo de funcionario a cadastrar: \n \n [1] Funcionario|Usuário \n [2] Pizzaiolo \n");
    scanf("%d", &func.category ); /* Isso vai definir como vai ser exibido em "Vizualizar Produto" */

    printf("\e[1;1H\e[2J"); /* Limpa a Tela */
    fflush(stdin);
    printf("Nome|Usuário: \n");
    gets(func.name);
    fflush(stdin);
    printf("Informe a senha: \n");
    gets(func.senha);
    fflush(stdin);

    fwrite (&func, sizeof(struct funcionario), 1, FuncFile); /* Grava a estrutura no arquivo */

    if(&fwrite != 0){ /* Se conseguir gravar */
        printf("\e[1;1H\e[2J");
        printf("Salvo com sucesso !\n\n"); 
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

    printf("\e[1;1H\e[2J");
    CadastrarFuncionario();
    
    /* Isso se tornará uma biblioteca de cabeçalho */
    /*int continuar;

    printf("Deseja voltar ao menu? \n [1] Sim \n [2] Nao\n");
    scanf("%d", &continuar);
    if(continuar == 1){
        system("./dist/menu");
    }else{
        printf("Programa Encerrado");
    }*/

    return 0;
}
