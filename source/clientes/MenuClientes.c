#include<stdio.h>
#include<stdlib.h>
/* #include <windows.h> */
#include <locale.h>
 
 int main(){
     
    int resposta;

    printf("\e[H\e[2J"); //Limpa a tela

    printf("\n ==============================================");
    printf("\n ============ Clientes ==============");
    printf("\n ==============================================");
    printf("\n \n");

    printf("\n (1) Vizualizar Clientes");
    printf("\n (2) Adicionar Clientes");
    printf("\n (3) Excluir Clientes \n");

    scanf("%d", &resposta);

    switch (resposta)
    {
    case 1:
        printf("\e[H\e[2J"); //Limpa a tela
        system("./source/clientes/VizualizarClientes");
        break;
    case 2:
        printf("\e[H\e[2J"); //Limpa a tela
        system("./source/clientes/CadastrarClientes");
        break;
    case 3:
        printf("\e[H\e[2J"); //Limpa a tela
        system("./source/clientes/EditarClientes");
        break;
    }
}   