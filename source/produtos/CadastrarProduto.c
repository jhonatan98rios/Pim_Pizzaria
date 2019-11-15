#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#include <locale.h>
#include <math.h>
/* #include <conio.h> */

#include "../../libs/structs.h" /* Essa é a classe de produto */
#include "../../libs/voltar.h" /* Essa é a classe de produto */
#include "../../libs/Mensagem.h"
#include "../../libs/cabSys.h"

int GerarID(){

    int contador = 101;

    FILE *infile;
    struct produtos input;
    infile = fopen("./data/produtos.dat", "r");

    while(fread(&input, sizeof(struct produtos), 1, infile)){
        contador++;
    };

    return contador;

}

void CadastrarPizzaGrande(struct produtos prod){

    FILE *BigFile;
    BigFile = fopen("./data/produtos.dat", "a"); /* Abre o arquivo somente para adição */

    struct produtos grande;

    grande.category = 4;
    grande.quant = 1;
    grande.id = (prod.id + 1);
    strcpy(grande.name, prod.name);
    strcat(grande.name, ":G");
    grande.price = (prod.price * 1.5);

    fwrite (&grande, sizeof(struct produtos), 1, BigFile); /* Grava a estrutura no arquivo */

    fclose(BigFile);

}

void CadastrarMeiaPizza(struct produtos prod){

    FILE *HalfFile;
    HalfFile = fopen("./data/produtos.dat", "a"); /* Abre o arquivo somente para adição */

    struct produtos meia;

    meia.category = 5;
    meia.quant = 1;
    meia.id = (prod.id + 2);
    strcpy(meia.name, prod.name);
    strcat(meia.name, ":1/2");
    meia.price = (prod.price / 2);

    fwrite (&meia, sizeof(struct produtos), 1, HalfFile); /* Grava a estrutura no arquivo */

    fclose(HalfFile);

}


void CadastrarProduto(){

    FILE *ProdFile;
    ProdFile = fopen("./data/produtos.dat", "a"); /* Abre o arquivo somente para adição */

    struct produtos prod; /* Cria uma instancia, da estrutura (Como uma cópia) */

   printf("   ---------------------------------------------------------------------------------\n");
    printf("  |                        O que deseja cadastrar:                                    |\n");
    printf("  |           (1) Pizzas                     (4) Pizzas Grandes                     |\n");
    printf("  |           (2) Bebidas                    (5) Pizzas 1/2                         |\n");
    printf("  |           (3) Doces                      (6) Promocoes                          |\n");
    printf("   ---------------------------------------------------------------------------------\n");
    printf("\n \n Selecione uma das opcoes acima: ");
     
    scanf("%d", &prod.category );

    printf("\e[1;1H\e[2J"); /* Limpa a Tela */

    printf("                    Informe o nome do produto.: \n");
    scanf("%s", prod.name);
    
    printf("                    Informe o preco do produto: \n");
    scanf("%f", &prod.price);

    prod.quant = 1;
    prod.id = GerarID();

    fwrite (&prod, sizeof(struct produtos), 1, ProdFile); /* Grava a estrutura no arquivo */

    if(&fwrite != 0){ /* Se conseguir gravar */
        printf("\e[1;1H\e[2J");
        sucess();
    }else{
        printf("\e[1;1H\e[2J"); 
        error();
    }

    if(prod.category == 1){
        CadastrarPizzaGrande(prod);
        CadastrarMeiaPizza(prod);
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
    cab();
    CadastrarProduto();

    /* Isso se tornará uma biblioteca de cabeçalho */
    
    voltarMenu();

    return 0;
}
