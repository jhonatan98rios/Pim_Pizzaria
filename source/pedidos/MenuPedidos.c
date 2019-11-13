#include<stdio.h>
#include<stdlib.h>
/* #include <windows.h> */
#include <locale.h>
#include "../../libs/cabSys.h"
#include "../../libs/voltar.h"
 
 int main(){
    cab();
    int resposta;

    printf("\e[H\e[2J"); //Limpa a tela

    printf("   ---------------------------------------------------------------------------------\n");
    printf("  |                         Opcoes disponiveis:                                     |\n");
    printf("  |                                                                                 |\n");
    printf("  |             (1) Realizar Venda        (2) Voltar                                |\n");
    printf("   ---------------------------------------------------------------------------------\n");
    printf("\n \n Selecione uma das opcoes acima: ");
    scanf("%d", &resposta);

    switch (resposta)
    {
    case 1:
        printf("\e[H\e[2J"); //Limpa a tela
        system("./dist/pedidos/CadastrarPedido");
        break;
    case 2:
        printf("\e[H\e[2J"); //Limpa a tela
        voltarMenu();
        break;
    }
}   