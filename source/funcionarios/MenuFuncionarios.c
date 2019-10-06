#include<stdio.h>
#include<stdlib.h>
/* #include <windows.h> */
#include <locale.h>
 
 int main(){
     
    int resposta;

    printf("\e[H\e[2J"); //Limpa a tela

    printf("\n ==============================================");
    printf("\n ============ Funcionarios ==============");
    printf("\n ==============================================");
    printf("\n \n");

    printf("\n (1) Vizualizar Funcionarios");
    printf("\n (2) Adicionar funcionario");
    printf("\n (3) Excluir funcionario \n");

    scanf("%d", &resposta);

    switch (resposta)
    {
    case 1:
        printf("\e[H\e[2J"); //Limpa a tela
        printf("Vizualizar");
        break;
    case 2:
        system("./source/funcionarios/CadastrarFuncionarios");
        break;
    case 3:
        printf("\e[H\e[2J"); //Limpa a tela
        printf("\n Excluir");
        break;
    }
}   