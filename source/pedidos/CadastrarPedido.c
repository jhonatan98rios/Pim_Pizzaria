#include<stdio.h>
#include<stdlib.h>
#include <locale.h>

struct produtos{
    int category;
    char name[10];
    float price;
};

void LerProd( char titulo[10], int category ){ /* Isso deve virar uma funcao de cabeçalho */

    FILE *infile;
    struct produtos prod;
    infile = fopen ("../../data/produtos.dat", "r");

    printf("\n =================== %s =================== \n", titulo);
    while(fread(&prod, sizeof(struct produtos), 1, infile)){ /* Isso deve virar uma funcao de cabeçalho */
        if(prod.category == category){
            printf ("\n nome = %s \n preco = %.2f\n", prod.name, prod.price);
        }
    };

    fclose (infile);
}

void CadastrarPedido(){

    int category;
    char produto[10];
    int produtoValido = 0;

    FILE *infile;
    struct produtos prod;
    infile = fopen ("../../data/produtos.dat", "r");

    printf("O que deseja comprar? \n\n [1] Pizzas \n [2] Bebidas \n [3] Doces \n");
    scanf("%d", &category );

    switch(category)
    {
    case 1:
        LerProd( "Pizzas" , 1);
        break;
    case 2:
        LerProd( "Bebidas" , 2);
        break;
    case 3:
        LerProd( "Doces" , 3);
        break;
    default:
        printf("Informe um valor válido");
        CadastrarPedido();
        break;
    }

    printf(" \n Informe o que nome do produto: \n");
    scanf("%s", produto);
    
    /* Preciso verificar se produto é igual à a prod.name */

    while(fread(&prod, sizeof(struct produtos), 1, infile)){

        size_t length = sizeof(produto)/sizeof(produto[0]); /* Isso deve virar uma funcao de cabeçalho */

        if(prod.category == category){
            printf ("\n nome = %s \n", prod.name);

            if(prod.name == produto){
                printf ("\n nome = %s \n preco = %.2f\n", prod.name, prod.price);
                produtoValido = 1;
            }
        }
        
    };

    if(produtoValido == 0){
        printf("Produto Inválido \n");
        CadastrarPedido();
    }

}

int main(){
    setlocale(LC_ALL, "Portuguese_Brasil");

    printf("\e[1;1H\e[2J");
    CadastrarPedido();
}