#include<stdio.h>
#include<stdlib.h>
/* #include <windows.h> */
#include <locale.h>
 
 int main(){
     
    int resposta;

    printf("\e[H\e[2J"); //Limpa a tela

    printf("\n ==============================================");
    printf("\n ============ Ingredientes ==============");
    printf("\n ==============================================");
    printf("\n \n");

    printf("\n (1) Vizualizar Ingredientes");
    printf("\n (2) Adicionar Ingredientes");
    printf("\n (3) Editar Ingredientes \n");

    scanf("%d", &resposta);

    switch (resposta)
    {
    case 1:
        printf("\e[H\e[2J"); //Limpa a tela
        system("./source/Estoque/VizualizarEstoque"); 
        break;
    case 2:
        printf("\e[H\e[2J"); //Limpa a tela
        system("./source/Estoque/CadastrarEstoque"); 
        break;
    case 3:
        printf("\e[H\e[2J"); //Limpa a tela
        system("./source/Estoque/EditarEstoque"); 
        break;
    }
}   