#include<stdio.h>
#include<stdlib.h>
/* #include <windows.h> */
#include <locale.h>
#include "../../libs/cabSys.h"
 
 int main(){
     cab();
    int resposta;

    printf("\e[H\e[2J"); //Limpa a tela

    printf("   ---------------------------------------------------------------------------------\n");
    printf("  |                         Opcoes disponiveis:                                     |\n");
    printf("  |                                                                                 |\n");
    printf("  |           (1) Visualizar Produtos      (2) Adicionar Produtos                   |\n");
    printf("  |           (0) Sair                                                              |\n");
    printf("   ---------------------------------------------------------------------------------\n");
    printf("\n \n Selecione uma das opcoes acima: ");

    scanf("%d", &resposta);

    switch (resposta)
    {
    case 1:
        printf("\e[H\e[2J"); //Limpa a tela
        system(".\\dist\\produtos\\VisualizarProduto");
        break;
        
    case 2:
        printf("\e[H\e[2J"); //Limpa a tela
        system(".\\dist\\produtos\\CadastrarProduto");
        break;
    case 3:
        printf("\e[H\e[2J"); //Limpa a tela
        printf("\n Excluir");
        break;
    case 0:
        system(".\\dist\\menu");
    }
}   