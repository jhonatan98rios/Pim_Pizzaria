#include<stdio.h>
#include<stdlib.h>
/* #include <windows.h> */
#include <locale.h>
 
 int main(){
     
    int resposta;

    printf("\e[H\e[2J"); //Limpa a tela

    printf("\n ==============================================");
    printf("\n ============ Produtos ==============");
    printf("\n ==============================================");
    printf("\n \n");

    printf("\n (1) Visualizar Produtos");
    printf("\n (2) Adicionar Produto");
    printf("\n (3) Excluir Produtos");
    printf("\n (4) Voltar \n");

    scanf("%d", &resposta);

    switch (resposta)
    {
    case 1:
        printf("\e[H\e[2J"); //Limpa a tela
        system("./dist/produtos/VisualizarProduto");
        break;
        
    case 2:
        printf("\e[H\e[2J"); //Limpa a tela
        system("./dist/produtos/CadastrarProduto");
        break;
    case 3:
        printf("\e[H\e[2J"); //Limpa a tela
        printf("\n Excluir");
        break;
    case 4:
        system("./dist/menu");
    }
}   