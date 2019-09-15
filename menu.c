#include<stdio.h>
#include<stdlib.h>
#include <windows.h>
#include <locale.h>

void showFuncionarios(){
    int resposta;

    printf("\e[H\e[2J"); //Limpa a tela

    printf("\n ==============================================");
    printf("\n ============ Funcionarios ==============");
    printf("\n ==============================================");
    printf("\n \n");

    printf("\n (1) Vizualizar Funcionarios");
    printf("\n (2) Adicionar funcionario");
    printf("\n (3) Editar funcionario \n");

    scanf("%d", &resposta);

    switch (resposta)
    {
    case 1:
        printf("\e[H\e[2J"); //Limpa a tela
        printf("Vizualizar");
        break;
    case 2:
        system("./funcionarios/cadastrar");
        break;
    case 3:
        printf("\e[H\e[2J"); //Limpa a tela
        printf("\n Editar");
        break;
    }
}

void showClientes(){
    int resposta;

    printf("\e[H\e[2J"); //Limpa a tela

    printf("\n ==============================================");
    printf("\n ============ Clientes ==============");
    printf("\n ==============================================");
    printf("\n \n");

    printf("\n (1) Vizualizar Clientes");
    printf("\n (2) Adicionar Clientes");
    printf("\n (3) Editar Clientes \n");

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
        printf("\n Editar");
        break;
    }
}

void showProdutos(){
    int resposta;

    printf("\e[H\e[2J"); //Limpa a tela

    printf("\n ==============================================");
    printf("\n ============ Produtos ==============");
    printf("\n ==============================================");
    printf("\n \n");

    printf("\n (1) Vizualizar Produtos");
    printf("\n (2) Adicionar Produtos");
    printf("\n (3) Editar Produtos \n");

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
        printf("\n Editar");
        break;
    }
}

void showIngredientes(){
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
        printf("\n Vizualizar");
        break;
    case 2:
        printf("\e[H\e[2J"); //Limpa a tela
        printf("\n Adicionar");
        break;
    case 3:
        printf("\e[H\e[2J"); //Limpa a tela
        printf("\n Editar");
        break;
    }
}

void showPedidos(){
    int resposta;

    printf("\e[H\e[2J"); //Limpa a tela

    printf("\n ==============================================");
    printf("\n ============ Pedidos ==============");
    printf("\n ==============================================");
    printf("\n \n");

    printf("\n (1) Vizualizar Pedidos");
    printf("\n (2) Adicionar Pedidos");
    printf("\n (3) Editar Pedidos \n");

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
        printf("\n Editar");
        break;
    }
}

void showReclamacoes(){
    int resposta;

    printf("\e[H\e[2J"); //Limpa a tela

    printf("\n ==============================================");
    printf("\n ============ Reclamações ==============");
    printf("\n ==============================================");
    printf("\n \n");

    printf("\n (1) Vizualizar Reclamações");
    printf("\n (2) Adicionar Reclamações");

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
    }
}

void showPromocoes(){
    int resposta;

    printf("\e[H\e[2J"); //Limpa a tela

    printf("\n ==============================================");
    printf("\n ============ Promoções ==============");
    printf("\n ==============================================");
    printf("\n \n");

    printf("\n (1) Vizualizar Promoções");
    printf("\n (2) Adicionar Promoções");
    printf("\n (3) Editar Promoções \n");
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
        printf("\n Editar");
        break;
    case 4:
        printf("\e[H\e[2J"); //Limpa a tela
        printf("\n Excluir");
        break;
    }
}

void showRelatorios(){
    int resposta;

    printf("\e[H\e[2J"); //Limpa a tela

    printf("\n ==============================================");
    printf("\n ============ Relatorios ==============");
    printf("\n ==============================================");
    printf("\n \n");

}

void showFechamento(){
    int resposta;

    printf("\e[H\e[2J"); //Limpa a tela

    printf("\n ==============================================");
    printf("\n ============ Fechamento ==============");
    printf("\n ==============================================");
    printf("\n \n");

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
    printf(" (1) Funcionarios \n (2) Clientes \n (3) Produtos \n (4) Ingredientes \n (5) Contabilizacao \n (6) Esqueci esse \n (7) Esse tambem \n (8) Ralatorios \n (9) Fechamento  \n (0) Sair ");
    printf("\n \n \n Selecione uma das opcoes acima: \n");

    scanf("%d", &resposta);

    switch (resposta){
        
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

}
