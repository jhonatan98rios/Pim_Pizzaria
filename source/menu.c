#include<stdio.h>
#include<stdlib.h>
/* #include <windows.h> */
#include <locale.h>

void menuFuncionarios(){
    system("./source/funcionarios/MenuFuncionarios");
}

void menuClientes(){
    system("./source/clientes/MenuClientes");
}

void menuProdutos(){
    system("./source/produtos/MenuProdutos"); 
}

void menuEstoque(){
    system("./source/Estoque/MenuEstoque"); 
}

void menuPedidos(){
    system("./source/pedidos/MenuPedidos"); 
}

void menuReclamacoes(){
    system("./source/reclamacoes/MenuReclamacoes"); 
}

void menuRelatorios(){
    system("./source/relatorios/MenuRelatorios"); 
}

void menuFechamento(){
    system("./source/fechamento/MenuFechamento"); 
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
    printf(" ----------------------------------------------");
    printf("\n");
    printf(" (1) Funcionarios \n (2) Clientes \n (3) Produtos \n (4) Ingredientes \n (5) Pedidos \n (6) Reclamacoes \n (7) Ralatorios \n (8) Fechamento  \n (0) Sair ");
    printf("\n \n \n Selecione uma das opcoes acima: \n");

    scanf("%d", &resposta);

    switch (resposta){
        
    case 1:
        menuFuncionarios();
        break;

    case 2:
        menuClientes();
        break;

    case 3:
        menuProdutos();
        break;

    case 4:
        menuEstoque();
        break;

    case 5:
        menuPedidos();
        break;

    case 6:
        menuReclamacoes();
        break;

    case 7:
        menuRelatorios();
        break;

    case 8:
        menuFechamento();
        break;

    case 0:
        printf("\n Programa encerrado \n");
        return 0;
        break;
    }

    printf("\n");

}
