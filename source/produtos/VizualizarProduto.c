#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#include <locale.h>
#include <math.h>
/* #include <conio.h> */

struct produtos{
    int category;
    char name[10];
    float price;
};

void LerProd( char titulo[10], int category ){

    FILE *infile;
    struct produtos input;
    infile = fopen ("./data/produtos.dat", "r");

    printf("\n =================== %s =================== \n", titulo);
    while(fread(&input, sizeof(struct produtos), 1, infile)){
        if(input.category == category){
            printf ("\n nome = %s \n preco = %.2f\n", input.name, input.price);
        }
    };

    fclose (infile);
}

void LerProdutos(){

    printf("\n ==============================================");
    printf("\n ================= Produtos ===================");
    printf("\n ==============================================\n");

    LerProd( "Pizzas" , 1);
    LerProd( "Bebidas" , 2);
    LerProd( "Doces" , 3);

    printf("\n\n");
};

int main()
{
    //Define o padrão UTF-8
    setlocale(LC_ALL, "Portuguese_Brasil");
    //Define a cor azul do terminal
    //system("color 1F");
    //define o titulo da janela do prompt
    //system("title Menu");

    printf("\e[1;1H\e[2J");
    LerProdutos();

    /* Isso se tornará uma biblioteca de cabeçalho */

    /* int continuar;

    printf("Deseja voltar ao menu? \n [1] Sim \n [2] Nao\n");
    scanf("%d", &continuar);
    if(continuar == 1){
        system("./source/menu");
    }else{
        printf("Programa Encerrado");
    } */

    return 0;
}