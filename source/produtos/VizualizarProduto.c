#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <math.h>
/* #include <conio.h> */

#include "../../libs/structs.h" /* Essa é a classe de produto */
#include "../../libs/lerProd.h" /* Essa é a classe de produto */
#include "../../libs/voltar.h" /* Essa é a classe de produto */

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

    voltarMenu();

    return 0;
}