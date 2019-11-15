#include <stdio.h>
#include <stdlib.h>
/* #include <windows.h> */
#include <locale.h>
#include "../../libs/cabSys.h"

 int main(){
     
     cab();
    int resposta;

    //printf("\e[H\e[2J"); //Limpa a tela

    printf("   ---------------------------------------------------------------------------------\n");
    printf("  |                         Opcoes disponiveis:                                     |\n");
    printf("  |                                                                                 |\n");
    printf("  |           (1) Visualizar Ingredientes         (3) Editar Ingredientes           |\n");
    printf("  |           (2) Adicionar Ingredientes          (0) Sair                          |\n");
    printf("   ---------------------------------------------------------------------------------\n");
    printf("\n \n Selecione uma das opcoes acima: ");
    scanf("%d", &resposta);

    switch (resposta)
    {
    case 1:
        printf("\e[H\e[2J"); //Limpa a tela
        system(".\\dist\\estoque\\VisualizarEstoque"); 
        break;
    case 2:
        printf("\e[H\e[2J"); //Limpa a tela
        system(".\\dist\\estoque\\CadastrarEstoque"); 
        break;
    case 3:
        printf("\e[H\e[2J"); //Limpa a tela
        system(".\\dist\\estoque\\EditarEstoque"); 
        break;
    case 0:
        printf("\e[H\e[2J"); //Limpa a tela
        system(".\\dist\\menu"); 
        break;
    }
}   