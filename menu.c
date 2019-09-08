#include<stdio.h>
#include<stdlib.h>
#include <windows.h>

void showFuncionarios(){
    printf("\n Funcionarios");
}

void showClientes(){
    printf("\n Clientes");
}

void showProdutos(){
    printf("\n Produtos");
}

void showIngredientes(){
    printf("\n Ingredientes");
}

void showPedidos(){
    printf("\n Contabilizacao");;
}

void showReclamacoes(){
    printf("\n Reclamacoes");;
}

void showPromocoes(){
    printf("\n Promocoes");;
}

void showRelatorios(){
    printf("\n Relatorios");;
}

void showFechamento(){
    printf("\n Fechamento");;
}


int main()
{
    //Define a cor azul do terminal
    system("color 1F");
    //define o titulo da janela do prompt
    system("title Menu");

    int r;
    printf("\n");
    printf("\n ==============================================");
    printf("\n ============Controle de Pizzaria==============");
    printf("\n ==============================================");
    printf("\n");
    printf(" Opcoes disponiveis:");
    printf("\n");
    printf(" ----------------------------------------------");
    printf("\n");
    printf(" (1) Funcionarios \n (2) Clientes \n (3) Produtos \n (4) Ingredientes \n (5) Contabilizacao \n (6) Esqueci esse \n (7) Esse tambem \n (8) Ralatorios \n (9) Fechamento  \n (0) Sair ");
    printf("\n \n \n Selecione uma das opcoes acima: \n");

    scanf("%d", &r);

    switch (r){
        
    case 1:
        showFuncionarios();
        break;

    case 2:
        showClientes();
        break;

    case 3:
        showProdutos();
        break;

    case 4:
        showIngredientes();
        break;

    case 5:
        showPedidos();
        break;

    case 6:
        showReclamacoes();
        break;

    case 7:
        showPromocoes();
        break;

    case 8:
        showRelatorios();
        break;

    case 9:
        showFechamento();
        break;

    case 0:
        printf("\n Programa encerrado \n");
        return 0;
        break;
    }
    

    printf("\n");

    main();
}
