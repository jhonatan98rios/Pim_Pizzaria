#include<stdio.h>
#include<stdlib.h>
//#include <windows.h>
#include <locale.h>

void showClientes2(){
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
        printf("\n Vizualizar");
        break;
    case 2:
        printf("\e[H\e[2J"); //Limpa a tela
        printf("\n Adicionar");
        break;
    case 3:
        printf("\e[H\e[2J"); //Limpa a tela
        printf("\n Excluir");
        break;
    }
}

void showProdutos2(){
    int resposta;

    printf("\e[H\e[2J"); //Limpa a tela

    printf("\n ==============================================");
    printf("\n ============ Produtos ==============");
    printf("\n ==============================================");
    printf("\n \n");

    printf("\n (1) Vizualizar Produtos");
    printf("\n (2) Adicionar Produtos");
    printf("\n (3) Excluir Produtos \n");

    scanf("%d", &resposta);

    switch (resposta)
    {
    case 1:
        printf("\e[H\e[2J"); //Limpa a tela
        system("./produtos/LerProduto");
        break;
    case 2:
        printf("\e[H\e[2J"); //Limpa a tela
        system("./produtos/CadastrarProduto");
        break;
    case 3:
        printf("\e[H\e[2J"); //Limpa a tela
        printf("\n Excluir");
        break;
    }
}

void showPedidos2(){
    int resposta;

    printf("\e[H\e[2J"); //Limpa a tela

    printf("\n ==============================================");
    printf("\n ============ Pedidos ==============");
    printf("\n ==============================================");
    printf("\n \n");

    printf("\n (1) Vizualizar Pedidos");
    printf("\n (2) Adicionar Pedidos");
    printf("\n (3) Excluir Pedidos \n");

    scanf("%d", &resposta);

    switch (resposta)
    {
    case 1:
        printf("\e[H\e[2J"); //Limpa a tela
        printf("\n Vizualizar");
        break;
    case 2:
        printf("\e[H\e[2J"); //Limpa a tela
        printf("\n Adicionar");
        break;
    case 3:
        printf("\e[H\e[2J"); //Limpa a tela
        printf("\n Excluir");
        break;
    }
}

void showPromocoes2(){
    int resposta;

    printf("\e[H\e[2J"); //Limpa a tela

    printf("\n ==============================================");
    printf("\n ============ Promoções ==============");
    printf("\n ==============================================");
    printf("\n \n");

    printf("\n (1) Vizualizar Promoções");
    printf("\n (2) Adicionar Promoções");
    printf("\n (3) Excluir Promoções \n");
    printf("\n (3) Excluir Promoções \n");

    scanf("%d", &resposta);

    switch (resposta)
    {
    case 1:
        printf("\e[H\e[2J"); //Limpa a tela
        printf("\n Vizualizar");
        break;
    case 2:
        printf("\e[H\e[2J"); //Limpa a tela
        printf("\n Adicionar");
        break;
    case 3:
        printf("\e[H\e[2J"); //Limpa a tela
        printf("\n Excluir");
        break;
    }
}

int main()
{
    //Define o padrão UTF-8
    setlocale(LC_ALL, "Portuguese_Brasil");
    //Define a cor azul do terminal
    system("color 1F");
    //define o titulo da janela do prompt
    system("title Menu");

    printf("\e[H\e[2J"); //Limpa a tela

    int resposta;
    printf("\n");
    printf("\n ==============================================");
    printf("\n ============ Controle de Pizzaria ==============");
    printf("\n ==============================================");
    printf("\n");
    printf(" Opcoes disponiveis:");
    printf("\n");
    printf(" ---------------------------------------------- ");
    printf("\n");
    printf("(1) Clientes \n (2) Produtos \n (3) Pedidos \n (4) Promoções \n (0) Sair ");
    printf("\n \n \n Selecione uma das opcoes acima: \n");

    scanf("%d", &resposta);

    switch (resposta){

    case 1:
        showClientes2();
        break;

    case 2:
        showProdutos2();
        break;

    case 3:
        showPedidos2();
        break;

    case 4:
        showPromocoes2();
        break;

    case 0:
        printf("\n Programa encerrado \n");
        return 0;
        break;
    }

    printf("\n");

}
