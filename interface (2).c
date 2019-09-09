#include <stdio.h>
#include <stdlib.h>

//=======================

void showFuncionarios()
{
    int r;

    printf("\e[H\e[2J");

    printf(" --------------");
    printf("| Funcionarios |");
    printf(" --------------");
    printf("\n \n");

    printf("\n (1) Vizualizar Funcionarios");
    printf("\n (2) Adicionar funcionario");
    printf("\n (3) Editar funcionario \n");

    scanf("%d", &r);

    switch (r)
    {
    case 1:
        system("X:\\Caminho\\vizualizarFuncionarios.exe");
        printf("Vizualizar");
        break;
    case 2:
        printf("\n Adicionar");
        break;
    case 3:
        printf("\n Editar");
        break;
    }
}

//=======================

void showClientes()
{
    int r;

    printf("\e[H\e[2J");

    printf(" --------------");
    printf("| Clientes |");
    printf(" --------------");
    printf("\n \n");

    printf("\n (1) Vizualizar Clientes");
    printf("\n (2) Adicionar Clientes");
    printf("\n (3) Editar Clientes \n");

    scanf("%d", &r);

    switch (r)
    {
    case 1:
        printf("\n Vizualizar");
        break;
    case 2:
        printf("\n Adicionar");
        break;
    case 3:
        printf("\n Editar");
        break;
    }
}

//=======================

void showProdutos()
{
    int r;

    printf("\e[H\e[2J");

    printf(" --------------");
    printf("| Produtos |");
    printf(" --------------");
    printf("\n \n");

    printf("\n (1) Vizualizar Produtos");
    printf("\n (2) Adicionar Produtos");
    printf("\n (3) Editar Produtos \n");

    scanf("%d", &r);

    switch (r)
    {
    case 1:
        printf("\n Vizualizar");
        break;
    case 2:
        printf("\n Adicionar");
        break;
    case 3:
        printf("\n Editar");
        break;
    }
}

//=======================

void showIngredientes()
{
    int r;

    printf("\e[H\e[2J");

    printf(" --------------");
    printf("| Ingredientes |");
    printf(" --------------");
    printf("\n \n");

    printf("\n (1) Vizualizar Ingredientes");
    printf("\n (2) Adicionar Ingredientes");
    printf("\n (3) Editar Ingredientes \n");

    scanf("%d", &r);

    switch (r)
    {
    case 1:
        printf("\n Vizualizar");
        break;
    case 2:
        printf("\n Adicionar");
        break;
    case 3:
        printf("\n Editar");
        break;
    }
}

//=======================

void showContabilizacao()
{
    int r;

    printf("\e[H\e[2J");

    printf(" --------------");
    printf("| Contabilizacao |");
    printf(" --------------");
    printf("\n \n");

    printf("\n (1) Vizualizar Contabilizacao");
    printf("\n (2) Adicionar Contabilizacao");
    printf("\n (3) Editar Contabilizacao \n");

    scanf("%d", &r);

    switch (r)
    {
    case 1:
        printf("\n Vizualizar");
        break;
    case 2:
        printf("\n Adicionar");
        break;
    case 3:
        printf("\n Editar");
        break;
    }
}

//==========================

void main()
{
    int r;

    printf("\n");
    printf(" (1) Funcionarios \n (2) Clientes \n (3) Produtos \n (4) Ingredientes \n (5) Contabilizacao \n (6) Esqueci esse \n (7) Esse tambem \n (8) Ralatorios \n (9) Fechamento ");
    printf("\n \n \n Selecione uma das opcoes acima: \n");

    scanf("%d", &r);

    switch (r)
    {
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
        showContabilizacao();
        break;

    case 6:
        printf("\nEsqueci");
        break;

    case 7:
        printf("\nEsse tambem");
        break;

    case 8:
        printf("\nRelatorios");
        break;

    case 9:
        printf("\nFechamento");
        break;
    }

    printf("\n");
}