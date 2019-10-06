#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#include <locale.h>
#include <math.h>
/* #include <conio.h> */

/* Sctruct é uma variavel com varias propriedades */
struct produtos{
    int category; /* Define se é pizza, bebida ou doce */
    char name[20];
    float price;
};

void CadastrarProduto(){

    FILE *ProdFile;
    ProdFile = fopen("./data/produtos.dat", "a"); /* Abre o arquivo somente para adição */

    struct produtos prod; /* Cria uma instancia, da estrutura (Como uma cópia) */

    printf("Informe o que deseja cadastrar: \n \n [1] Pizzas \n [2] Bebidas \n [3] Doces\n\n");
    scanf("%d", &prod.category ); /* Isso vai definir como vai ser exibido em "Vizualizar Produto" */

    printf("\e[1;1H\e[2J"); /* Limpa a Tela */
    printf("Informe o nome do produto: \n");
    scanf("%s", prod.name);
    printf("Informe o preco do produto: \n");
    scanf("%f", &prod.price);

    fwrite (&prod, sizeof(struct produtos), 1, ProdFile); /* Grava a estrutura no arquivo */

    if(&fwrite != 0){ /* Se conseguir gravar */
        printf("\e[1;1H\e[2J");
        printf("Salvo com sucesso !\n\n"); 
    }else{
        printf("\e[1;1H\e[2J"); 
        printf("Erro ao gravar !\n");
    }
    
    fclose(ProdFile);
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
    CadastrarProduto();

    /* Isso se tornará uma biblioteca de cabeçalho */
    int continuar;

    printf("Deseja voltar ao menu? \n [1] Sim \n [2] Nao\n");
    scanf("%d", &continuar);
    if(continuar == 1){
        system("./source/menu");
    }else{
        printf("Programa Encerrado");
    }

    return 0;
}
