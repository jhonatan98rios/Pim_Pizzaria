#include<stdio.h>
#include<stdlib.h>
/* #include <windows.h> */
#include <locale.h>
#include "../../libs/cabSys.h"
 
 int main(){
      int resposta;

    printf("\e[H\e[2J"); //Limpa a tela
    cab();
    printf("   ---------------------------------------------------------------------------------\n");
    printf("  |                         Opcoes disponiveis:                                     |\n");
    printf("  |                                                                                 |\n");
    printf("  |           (1) Visualizar Fechamento         (5) Sair                            |\n");
    printf("  |           (2) Realizar Fechamento                                               |\n");
    printf("   ---------------------------------------------------------------------------------\n");
    printf("\n \n Selecione uma das opcoes acima: ");
    scanf("%d", &resposta);

    switch (resposta)
    {
    case 1:
        printf("\e[H\e[2J"); //Limpa a tela
        system("./dist/fechamento/VisualizarFechamento");
        break;
    case 2:
        printf("\e[H\e[2J"); //Limpa a tela
        system("./dist/fechamento/RealizarFechamento");
        break;
    case 3:
        printf("\e[H\e[2J"); //Limpa a tela
        system("./dist/menu");
        break;
    }
}   