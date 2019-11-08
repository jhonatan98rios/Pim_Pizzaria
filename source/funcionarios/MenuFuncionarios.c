#include<stdio.h>
#include<stdlib.h>
/* #include <windows.h> */
#include <locale.h>
#include "../../libs/cabSys.h"
 
 int main(){
     
     system("color 1F");
     
    int resposta;

    printf("\e[H\e[2J"); //Limpa a tela
    cab();
    printf("   ---------------------------------------------------------------------------------\n");
    printf("  |                         Opcoes disponiveis:                                     |\n");
    printf("  |                                                                                 |\n");
    printf("  |           (1) Visualizar Funcionarios         (5) Excluir funcionario           |\n");
    printf("  |           (2) Adicionar funcionario           (6) Reclamacoes                   |\n");
    printf("   ---------------------------------------------------------------------------------\n");
    printf("\n \n Selecione uma das opcoes acima: ");
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