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

    printf("\n (1) Visualizar Funcionarios");
    printf("\n (2) Adicionar funcionario");
    printf("\n (3) Editar funcionario");
    printf("\n (4) Excluir funcionario \n");

    scanf("%d", &resposta);

    switch (resposta)
    {
    case 1:
        printf("\e[H\e[2J"); //Limpa a tela
        system("./dist/funcionarios/VisualizarFuncionario");
        break;
    case 2:
        printf("\e[H\e[2J"); //Limpa a tela
        system("./dist/funcionarios/CadastrarFuncionario");
        break;
    case 3:
        printf("\e[H\e[2J"); //Limpa a tela
        system("./dist/funcionarios/EditarFuncionario");
        break;
    case 4:
        printf("\e[H\e[2J"); //Limpa a tela
        system("./dist/funcionarios/ExcluirFuncionario");
        break;
    }
}   