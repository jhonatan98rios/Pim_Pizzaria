#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#include <locale.h>
#include <math.h>
/* #include <conio.h> */

struct produtos{
    struct pizzas{
        int id;
        char nome[10];
        float preco;
    } pizzas;

    struct bebidas{
        int id;
        char nome[10];
        float preco;
        int quantidade;
    } bebidas;
};

void LerProdutos(){
    FILE *infile;
    struct produtos input;
    infile = fopen ("produtos.dat", "r");
    printf ("Pizzas \n");
    while(fread(&input, sizeof(struct produtos), 1, infile)){
        printf ("nome = %s \npreco = %.2f\n", input.pizzas.nome, input.pizzas.preco);
        printf ("nome = %s \npreco = %.2f\n", input.bebidas.nome, input.bebidas.preco);
    };
    fclose (infile);
};

void CadastrarProduto(){

    FILE *ProdFile;
    ProdFile = fopen("produtos.dat", "a");

    struct produtos prod;
    int resp;

    printf("Informe o que deseja cadastrar: \n \n [1] Pizzas \n [2] Bebidas \n");
    scanf("%d", &resp );

    switch (resp)
    {
    case 1:
        printf("\e[1;1H\e[2J");
        printf("Informe o nome da pizza: \n");
        scanf("%s", prod.pizzas.nome);
        printf("Informe o preco da pizza: \n");
        scanf("%f", &prod.pizzas.preco);
        break;
    
    default:
        printf("\e[1;1H\e[2J");
        printf("Informe o nome da bebida: \n");
        scanf("%s", prod.bebidas.nome);
        printf("Informe o preco da bebida: \n");
        scanf("%f", &prod.bebidas.preco);
        break;
    }

    fwrite (&prod, sizeof(struct produtos), 1, ProdFile);

    if(&fwrite != 0){
        printf("\e[1;1H\e[2J");
        printf("Salvo com sucesso !\n"); 
    }else{
        printf("\e[1;1H\e[2J"); 
        printf("Erro ao gravar !\n");
    }
    
    fclose(ProdFile);
}

void menu(){
    int resp;
    int repeat = 1;

    while(repeat == 1){
        printf("O que deseja fazer? \n\t[1] Cadastrar \n\t[2] Vizualizar \n");
        scanf("%d", &resp);

        switch (resp)
        {
        case 1:
            printf("\e[1;1H\e[2J");
            CadastrarProduto();
            break;

        case 2:
            printf("\e[1;1H\e[2J");
            LerProdutos();
            break;
        
        default:
            printf("\e[1;1H\e[2J");
            printf("Essa opcao nao existe seu burro");
            printf("O que deseja fazer? \n\t[1] Cadastrar \n\t[2] Vizualizar \n");

        }

        printf("Deseja continuar? \n\t [1] Sim \n\t [2] Nao \n");
        scanf("%d", &repeat);
        printf("\e[1;1H\e[2J");
    }
    
}

int main()
{
    //Define o padrão UTF-8
    setlocale(LC_ALL, "Portuguese_Brasil");
    //Define a cor azul do terminal
    //system("color 1F");
    //define o titulo da janela do prompt
    //system("title Menu");

    printf("\e[1;1H\e[2J");
    menu();

    return 0;
}
