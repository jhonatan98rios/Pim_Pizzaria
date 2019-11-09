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

    printf("\n (1) Visualizar Clientes");
    printf("\n (2) Adicionar Clientes");
    printf("\n (3) Excluir Clientes \n");

    scanf("%d", &resposta);

    switch (resposta)
    {
    case 1:
        printf("\e[H\e[2J"); //Limpa a tela
        system("./dist/clientes/VisualizarClientes");
        break;
    case 2:
        printf("\e[H\e[2J"); //Limpa a tela
        system("./dist/clientes/CadastrarClientes");
        break;
    case 3:
        printf("\e[H\e[2J"); //Limpa a tela
        system("./dist/clientes/EditarClientes");
        break;
    }
}   